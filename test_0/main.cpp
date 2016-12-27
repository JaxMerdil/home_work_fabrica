#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

//----------------------------------------------------------------------------------------
template<class T>
class ImmutableBuffer
{
    T *m_data;
    int m_size;
    const ImmutableBuffer& operator=(const ImmutableBuffer& obj){}
public:
    ImmutableBuffer(T *arr, const int size)
    {
        m_data=new T[size];
        m_size=size;
        for(int i = 0; i < size; i++)
        {
            m_data[i] = arr[i];
        }
    }
    ImmutableBuffer(const ImmutableBuffer& obj)
    {
        m_data=new T[obj.m_size];
        m_size=obj.m_size;
        for(int i = 0; i < obj.m_size; i++)
        {
            m_data[i] = obj.m_data[i];
        }
    }
    ~ImmutableBuffer()
    {
        if(m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }
//----------------------------------------------------------------------------------------
    template<typename Tf>
    friend ostream& operator << (ostream& ost, const ImmutableBuffer<Tf>& obj);
//----------------------------------------------------------------------------------------
    const T& operator[](const int i)const
    {
        return m_data[i];
    }
//----------------------------------------------------------------------------------------
    bool operator == (const ImmutableBuffer& obj)const
    {
        if(m_size != obj.m_size)
        {
            return false;
        }
        for(int i = 0; i < m_size; i++)
        {
            if(m_data[i] != obj.m_data[i])
            {
                return false;
            }
        }
        return true;
    }
//----------------------------------------------------------------------------------------
    bool operator == (const T* arr)const
    {
        if(m_size != ARRAY_SIZE(arr))
        {
            return false;
        }
        for(int i = 0; i < m_size; ++i)
        {
            if(m_data[i] != arr[i])
            {
                return false;
            }
        }
        return true;
    }
//----------------------------------------------------------------------------------------
    bool operator !=(const ImmutableBuffer& obj)const
    {
        return !(this == obj);
    }
//----------------------------------------------------------------------------------------
    bool operator !=(const T *arr)const
    {
        return !(this == arr);
    }
};
//----------------------------------------------------------------------------------------
template<class Tf>
ostream& operator<< (ostream& ost, const ImmutableBuffer<Tf>& obj)
{
    for(int i = 0; i < obj.m_size; ++i)
    {
        ost << obj.m_data[i] << " ";
    }
    return ost;
}
//----------------------------------------------------------------------------------------

int main()
{
    int size=5;
    bool arr[size];
    arr[0]=true;
    arr[1]=false;
    arr[2]=true;
    arr[3]=true;
    arr[4]=false;
    ImmutableBuffer<bool> data(arr, size);
    cout << data << endl;
    return 0;
}
