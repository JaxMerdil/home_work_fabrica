#include <iostream>
#include <map>
#include <cstring>
#include <cassert>

using namespace std;

class RomanNumber
{
private:
    string m_romanNumber;
    int m_arabicNumber;
    map<char, int> RomanArab= {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };
public:
    RomanNumber() : m_romanNumber(0), m_arabicNumber(0)
    {}
    RomanNumber(const string romanNumb) : m_romanNumber(romanNumb),m_arabicNumber(0)
    {
        m_arabicNumber=ConvertRomanToArab();
    }
    int ConvertRomanToArab()
    {
        int number = 0;

        for (auto value = m_romanNumber.begin(); value != m_romanNumber.end(); ++value)
        {
            if(RomanArab[*value] >= RomanArab[*(value+1)])
            {
                number += RomanArab[*value];
            }
            else
            {
                number = number - RomanArab[*value];
            }
        }
        return number;
    }
//---------------------------------------------------------
    explicit operator int()const
    {
        return m_arabicNumber;
    }
//---------------------------------------------------------
    int operator + (const RomanNumber& rhs)
    {
        return m_arabicNumber + rhs.m_arabicNumber;
    }
    friend unsigned int operator + (unsigned int lhs, const RomanNumber& rhs)
    {
        return (lhs + rhs.m_arabicNumber);
    }
    friend RomanNumber operator + (const RomanNumber& lhs, unsigned int rhs)
    {
        return (lhs += rhs);
    }
//---------------------------------------------------------
    int operator - (const RomanNumber& rhs)
    {
        return m_arabicNumber - rhs.m_arabicNumber;
    }
    friend unsigned int operator - (unsigned int lhs, const RomanNumber& rhs)
    {
        return (lhs - rhs.m_arabicNumber);
    }
    friend RomanNumber operator - (const RomanNumber& lhs, unsigned int rhs)
    {
        return (lhs -= rhs);
    }
//---------------------------------------------------------
    int operator * (const RomanNumber& rhs)
    {
        return m_arabicNumber * rhs.m_arabicNumber;
    }
    friend unsigned int operator * (unsigned int lhs, const RomanNumber& rhs)
    {
        return (lhs * rhs.m_arabicNumber);
    }
    friend RomanNumber operator * (const RomanNumber& lhs, unsigned int rhs)
    {
        return (lhs *= rhs);
    }
//---------------------------------------------------------
    int operator / (const RomanNumber& rhs)
    {
        return m_arabicNumber / rhs.m_arabicNumber;
    }
    friend unsigned int operator / (unsigned int lhs, const RomanNumber& rhs)
    {
        return (lhs / rhs.m_arabicNumber);
    }
    friend RomanNumber operator / (const RomanNumber& lhs, unsigned int rhs)
    {
        return (lhs /= rhs);
    }
//---------------------------------------------------------
    friend int operator += (RomanNumber& lhs,const RomanNumber& rhs)
    {
        lhs.m_arabicNumber += rhs.m_arabicNumber;
        return lhs.m_arabicNumber;
    }
    friend unsigned int operator += (unsigned int lhs, const RomanNumber& rhs)
    {
        lhs+=rhs.m_arabicNumber;
        return lhs;
    }
    friend RomanNumber operator += (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber += rhs;
        return lhs;
    }
//---------------------------------------------------------
    friend int operator -= (RomanNumber& lhs,const RomanNumber& rhs)
    {
        lhs.m_arabicNumber -= rhs.m_arabicNumber;
        return lhs.m_arabicNumber;
    }
    friend unsigned int operator -= (unsigned int lhs, const RomanNumber& rhs)
    {
        lhs -= rhs.m_arabicNumber;
        return lhs;
    }
    friend RomanNumber operator -= (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber -= rhs;
        return lhs;
    }
//---------------------------------------------------------
    friend int operator *= (RomanNumber& lhs,const RomanNumber& rhs)
    {
        lhs.m_arabicNumber *= rhs.m_arabicNumber;
        return lhs.m_arabicNumber;
    }
    friend unsigned int operator *= (unsigned int lhs, const RomanNumber& rhs)
    {
        lhs *= rhs.m_arabicNumber;
        return lhs;
    }
    friend RomanNumber operator *= (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber *= rhs;
        return lhs;
    }
//---------------------------------------------------------
    friend int operator /= (RomanNumber& lhs,const RomanNumber& rhs)
    {
        lhs.m_arabicNumber /= rhs.m_arabicNumber;
        return lhs.m_arabicNumber;
    }
    friend unsigned int operator /= (unsigned int lhs, const RomanNumber& rhs)
    {
        lhs /= rhs.m_arabicNumber;
        return lhs;
    }
    friend RomanNumber operator /= (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber /= rhs;
        return lhs;
    }
//---------------------------------------------------------
    bool operator == (const RomanNumber& rhs)
    {
        return (m_arabicNumber == rhs.m_arabicNumber);
    }
    friend bool operator == (const int lhs, const RomanNumber& rhs)
    {
        return (lhs == rhs.m_arabicNumber);
    }
    friend bool operator == (const RomanNumber& lhs, const int rhs)
    {
        return (lhs.m_arabicNumber == rhs);
    }
//---------------------------------------------------------
    bool operator != (const RomanNumber& rhs)
    {
        return !(m_arabicNumber == rhs.m_arabicNumber);
    }
    friend bool operator != (const int lhs, const RomanNumber& rhs)
    {
        return !(lhs == rhs.m_arabicNumber);
    }
    friend bool operator != (const RomanNumber& lhs, const int rhs)
    {
        return !(lhs.m_arabicNumber == rhs);
    }
//---------------------------------------------------------
    bool operator < (const RomanNumber& rhs)
    {
        return (m_arabicNumber < rhs.m_arabicNumber);
    }
    friend bool operator < (const int lhs, const RomanNumber& rhs)
    {
        return (lhs < rhs.m_arabicNumber);
    }
    friend bool operator < (const RomanNumber& lhs, const int rhs)
    {
        return (lhs.m_arabicNumber < rhs);
    }
//---------------------------------------------------------
    bool operator <= (const RomanNumber& rhs)
    {
        return (m_arabicNumber < rhs.m_arabicNumber || m_arabicNumber == rhs.m_arabicNumber);
    }
    friend bool operator <= (const int lhs, const RomanNumber& rhs)
    {
        return (lhs < rhs.m_arabicNumber || lhs == rhs.m_arabicNumber);
    }
    friend bool operator <= (const RomanNumber& lhs, const int rhs)
    {
        return (lhs.m_arabicNumber < rhs || lhs.m_arabicNumber == rhs);
    }
//---------------------------------------------------------
    bool operator > (const RomanNumber& rhs)
    {
        return (m_arabicNumber > rhs.m_arabicNumber);
    }
    friend bool operator > (const int lhs, const RomanNumber& rhs)
    {
        return (lhs > rhs.m_arabicNumber);
    }
    friend bool operator > (const RomanNumber& lhs, const int rhs)
    {
        return (lhs.m_arabicNumber > rhs);
    }
//---------------------------------------------------------
    bool operator >= (const RomanNumber& rhs)
    {
        return (m_arabicNumber > rhs.m_arabicNumber || m_arabicNumber == rhs.m_arabicNumber);
    }
    friend bool operator >= (const int lhs, const RomanNumber& rhs)
    {
        return (lhs > rhs.m_arabicNumber || lhs == rhs.m_arabicNumber);
    }
    friend bool operator >= (const RomanNumber& lhs, const int rhs)
    {
        return (lhs.m_arabicNumber > rhs || lhs.m_arabicNumber == rhs);
    }
//---------------------------------------------------------
    int operator ++ ()
    {
        return	(++ m_arabicNumber);
    }
    int operator ++ (int)
    {
        return (m_arabicNumber ++);
    }
//---------------------------------------------------------
    int operator -- ()
    {
        return	(-- m_arabicNumber);
    }
    int operator -- (int)
    {
        return (m_arabicNumber --);
    }
//---------------------------------------------------------
    friend ostream& operator << (ostream& os, const RomanNumber& obj)
    {
        os << "Arab number: " << obj.m_arabicNumber << endl;
        os << "Rome number: " << obj.m_romanNumber << endl;

        return os;
    }
};

int main()
{

    RomanNumber r1 = RomanNumber("MDIL");
    RomanNumber r2("MCDXLIX");
    cout << r1 << endl;
    cout << r2 << endl;
    assert(r1 == 1549);
    assert( r1+1 == 1550);
    assert( r1-100 == 1449);
    assert(r1 + r2 >= r2);
    assert(r2 + r2 == r2 * 2);
    assert(r1 + r2 >= r2 / 3);
    assert(r1 >  r2);
    assert(r1 != r2);
    return 0;
}
