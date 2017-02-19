#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

//without the use of STL
template<typename T, typename RetT = T>
class range_iterator : public std::iterator<std::bidirectional_iterator_tag, T> //https://github.com/SebastianVaell/home_work_fabrica/blob/master/task_28_forward_list/forward_list.h
{
public:
    range_iterator()
        : m_current (nullptr)
    {
    }
    range_iterator(T cur, T nex)
        : m_current (cur)
        , m_next(nex)
    {
    }
    RetT& operator*()
    {
        return m_current;
    }
    range_iterator& operator++()
    {
        m_current += m_next;
        return *this;
    }
    range_iterator operator++(int)
    {
        range_iterator tmp(m_current);
        ++(*this);
        return tmp;
    }
    bool operator == (const range_iterator& rhs)
    {
        return m_current >= rhs.m_current ;
    }
    bool operator!=(const range_iterator& rhs)
    {
        return !(*this == rhs);
    }
private:
        T m_current;
        T m_next;
};

template<int B, int E, int S=1>
class Range
{
public:

    typedef range_iterator<int> iterator;
    typedef range_iterator<int, const int> const_iterator;
    iterator begin()
    {
        return iterator(B,S);
    }
    iterator end()
    {
        return iterator(E,S);
    }
};

//using STL
//template<int B, int E, int S=1>
//class Range
//{
//    list<int> m_data;
//public:
//    Range()
//    {
//        for (size_t i = B; i < E; i += S)
//        {
//        m_data.push_back(i);
//        }
//    }
//    list<int>::iterator begin()
//    {
//    return m_data.begin();
//    }
//    list<int>::iterator end()
//    {
//    return m_data.end();
//    }

//    list<int>::const_reverse_iterator rbegin()
//    {
//    return m_data.rbegin();
//    }
//    list<int>::const_reverse_iterator rend()
//    {
//    return m_data.rend();
//    }
//};

int main()
{
    for (auto& elem : Range<1, 5>())
    {
        cout << elem << " "; // 1 2 3 4
    }
    cout << endl;

    for (auto& elem : Range<0, 10, 2>())
    {
        cout << elem << " "; //0 2 4 6 8
    }
    cout << endl;

    for (auto& elem : Range<20, 50, 1000>())
    {
        cout << elem << " "; // 20
    }
    cout << endl;

    auto r = Range<1,30>();
    cout << count_if(r.begin(), r.end(), [](int e){return e>20;}) << endl; // 9


    auto resFind = std::find(r.begin(), r.end(), 9);
    assert(*resFind == 9); // +
    auto resFind1 = std::count(r.begin(), r.end(), 9);
    assert(resFind1 == 1); // +

    cout << "PAUSE" << endl;
    return 0;
}
