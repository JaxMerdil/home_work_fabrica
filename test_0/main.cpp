#include <iostream>
#include <cstring>

template<class T>
class ImmutableBuffer
{ T* m_data;
  int m_size;
public:
    ImmutableBuffer(const T*m_data, int m_size )
    {
        m_data=new T[strlen(data)+1];
        strcpy(m_name,name);
    }
    ImmutableBuffer(const T &data)
    {
        m_data=new T[strlen(data.m_data)+1];
        strcpy(m_data,data.m_data);
    }
    friend ostream& operator<<(ostream& os, const ImmutableBuffer& obj)
    {
        os << "A::value = " << obj.m_data;
        return os;
    }
    ImmutableBuffer operator[](int value)
    {
        return value < m_size;
    }
    ImmutableBuffer operator ==(const ImmutableBuffer& rhs)
    {
       return m_data == rhs.m_data;
    }
    ImmutableBuffer operator !=(const ImmutableBuffer& rhs)
    {
       return !(*this == rhs);
    }
};


using namespace std;

int main(int argc, char *argv[])
{
    int size=3;
    ImmutableBuffer obj("asd");
    return 0;
}
