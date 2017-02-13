#include <iostream>
#include <array>
#include <cassert>
#include <vector>
#include <memory>
#include <condition_variable>
#include <thread>
#include <future>
#include <pthread.h>
#include <mutex>
#include <unistd.h>
#include <chrono>


using namespace std;

template<typename T, size_t N>
class RingBuffer
{
    array<T, N> m_data;
    typedef unsigned long long tSize;
    unsigned long long m_start = 0;
    unsigned long long m_end = 0;
    std::condition_variable cond_ver;
    mutable std::mutex mtex;
    bool empty_unsafe() const
    {
        return (m_start == m_end);
    }

    bool full_unsafe() const
    {
        return (N == m_start - m_end);
    }

public:

    size_t size() const
    {
        return N;
    }

    size_t count()
    {
        return m_start - m_end;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mtex);
        return empty_unsafe();
    }
    bool full() const
    {
        std::lock_guard<std::mutex> lock(mtex);
        return full_unsafe();
    }
    void push_back(const T& elem)
    {
        std::unique_lock<std::mutex> lock{mtex};
        while(full_unsafe())
        {
            cond_ver.wait(lock);
        }
        tSize start = m_start % N;
        m_data[start] = elem;
        ++m_start;
        cond_ver.notify_one();
    }

    T& front()
    {
        unique_lock<std::mutex> lock{mtex};
        while(empty_unsafe())
        {
            cond_ver.wait(lock);
        }
        return m_data[m_end % N];
    }

    void pop_front()
    {
        unique_lock<std::mutex> lock{mtex};
        if(!empty_unsafe())
        {
            ++m_end;
            cond_ver.notify_one();
        }
    }
};

int main()
{
    RingBuffer<int, 5> ringBuffer;
    thread thread_push{[&](){
            int counter = 10;
            while(counter)
            {
                ringBuffer.push_back(--counter);
                cout << "Push: " << counter << endl;
            }
                  }};

    thread thread_pop{[&](){
            int value;
            while(value)
            {
                value = ringBuffer.front();
                ringBuffer.pop_front();
                cout << "Read: " << value << endl;
                std::chrono::milliseconds timeout(20);
                std::this_thread::sleep_for(timeout);
            }
                      }};
    thread_push.join();
    thread_pop.join();
    return 0;
}
