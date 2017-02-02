#include <iostream>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>

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

    struct ArabRoman
    {
        unsigned int arab;
        char const* roman;
    };
public:
    RomanNumber() : m_romanNumber("NaN"), m_arabicNumber(0) {}
    RomanNumber(const string& romanNumb) : m_romanNumber(romanNumb),m_arabicNumber(0)
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

    string ConvertArabToRoman(unsigned int value) // goo.gl/xfOikj
    {
        const struct ArabRoman Data[] =
        {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        { 90, "XC"},
        { 50, "L"},
        { 40, "XL"},
        { 10, "X"},
        { 9, "IX"},
        { 5, "V"},
        { 4, "IV"},
        { 1, "I"},
        { 0, NULL} // end marker
    };
        string result;
        for (const ArabRoman* current = Data; current->arab > 0; ++current)
        {
            while (value >= current->arab)
            {
                result += current->roman;
                value -= current->arab;
            }
        }
        return result;
    }

    //---------------------------------------------------------

    explicit operator int()const
    {
        return m_arabicNumber;
    }

    RomanNumber operator + (const RomanNumber& rhs)
    {
        RomanNumber tmp;
        tmp.m_arabicNumber = this->m_arabicNumber + rhs.m_arabicNumber;
        tmp.m_romanNumber = ConvertArabToRoman(tmp.m_arabicNumber);
        return tmp;
        //        return *this+=rhs.m_arabicNumber;
    }

    RomanNumber operator - (const RomanNumber& rhs)
    {
        RomanNumber tmp;
        tmp.m_arabicNumber = this->m_arabicNumber - rhs.m_arabicNumber;
        tmp.m_romanNumber = ConvertArabToRoman(tmp.m_arabicNumber);
        return tmp;
        //        return *this-=rhs.m_arabicNumber;
    }

    RomanNumber operator * (const RomanNumber& rhs)
    {
        RomanNumber tmp;
        tmp.m_arabicNumber = this->m_arabicNumber * rhs.m_arabicNumber;
        tmp.m_romanNumber = ConvertArabToRoman(tmp.m_arabicNumber);
        return tmp;
        //        return *this*=rhs.m_arabicNumber;
    }

    RomanNumber operator / (const RomanNumber& rhs)
    {
        RomanNumber tmp;
        tmp.m_arabicNumber = this->m_arabicNumber / rhs.m_arabicNumber;
        tmp.m_romanNumber = ConvertArabToRoman(tmp.m_arabicNumber);
        return tmp;
        //        return *this/=rhs.m_arabicNumber;
    }

    RomanNumber& operator += (const RomanNumber& rhs)
    {
        this->m_arabicNumber += rhs.m_arabicNumber;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return *this;
    }
    friend RomanNumber operator += (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber += rhs;
        return lhs;
    }
    //---------------------------------------------------------
    RomanNumber& operator -= (const RomanNumber& rhs)
    {
        this->m_arabicNumber -= rhs.m_arabicNumber;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return *this;
    }

    friend RomanNumber operator -= (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber -= rhs;
        return lhs;
    }
    //---------------------------------------------------------
    RomanNumber& operator *= (const RomanNumber& rhs)
    {
        this->m_arabicNumber *= rhs.m_arabicNumber;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return *this;
    }

    friend RomanNumber operator *= (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber *= rhs;
        return lhs;
    }
    //---------------------------------------------------------
    RomanNumber& operator /= (const RomanNumber& rhs)
    {
        this->m_arabicNumber /= rhs.m_arabicNumber;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return *this;
    }
    friend RomanNumber operator /= (RomanNumber lhs, unsigned int rhs)
    {
        lhs.m_arabicNumber /= rhs;
        return lhs;
    }
    //---------------------------------------------------------
    bool operator == (const RomanNumber& rhs)
    {
        return (this->m_arabicNumber == rhs.m_arabicNumber);
    }
    //---------------------------------------------------------
    bool operator != (const RomanNumber& rhs)
    {
        return !(*this == rhs);
    }
    //---------------------------------------------------------
    bool operator < (const RomanNumber& rhs)
    {
        return (this->m_arabicNumber < rhs.m_arabicNumber);
    }
    //---------------------------------------------------------
    bool operator <= (const RomanNumber& rhs)
    {
        return *this < rhs || *this == rhs;
    }
    //---------------------------------------------------------
    bool operator > (const RomanNumber& rhs)
    {
        return (this->m_arabicNumber > rhs.m_arabicNumber);
    }
    //---------------------------------------------------------
    bool operator >= (const RomanNumber& rhs)
    {
        return *this > rhs || *this == rhs;
    }
    //---------------------------------------------------------
    RomanNumber operator = (const RomanNumber& rhs){
        this->m_romanNumber = rhs.m_romanNumber;
        this->m_arabicNumber = rhs.m_arabicNumber;
        return  *this;
    }
    //---------------------------------------------------------
    RomanNumber operator++ ()
    {
        ++this->m_arabicNumber;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return	*this;
    }
    RomanNumber operator ++ (int)
    {
        RomanNumber tmp = *this;
        this->m_arabicNumber++;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return tmp;
    }
    //---------------------------------------------------------
    RomanNumber operator -- ()
    {
        --this->m_arabicNumber;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return *this;
    }
    RomanNumber operator -- (int)
    {
        RomanNumber tmp = *this;
        this->m_arabicNumber--;
        this->m_romanNumber = ConvertArabToRoman(this->m_arabicNumber);
        return tmp;
    }
    //---------------------------------------------------------
    friend ostream& operator << (ostream& os, const RomanNumber& obj)
    {
        os << "Arab number: " << obj.m_arabicNumber << endl;
        os << "Rome number: " << obj.m_romanNumber << endl;

        return os;
    }
    friend istream& operator>> (istream& is, RomanNumber& rhs)
    {
        is >> rhs.m_arabicNumber;
        return is;
    }
};

//---------------------------------------------------------
bool operator == (const int lhs, const RomanNumber& rhs)
{
    return (lhs == static_cast<int>(rhs));
}

bool operator == (const RomanNumber& lhs, const int rhs)
{
    return (static_cast<int>(lhs) == rhs);
}

bool operator != (const int lhs, const RomanNumber& rhs)
{
    return !(lhs == static_cast<int>(rhs));
}

bool operator != (const RomanNumber& lhs, const int rhs)
{
    return !(static_cast<int>(lhs) == rhs);
}

bool operator < (const int lhs, const RomanNumber& rhs)
{
    return (lhs < static_cast<int>(rhs));
}

bool operator < (const RomanNumber& lhs, const int rhs)
{
    return (static_cast<int>(lhs) < rhs);
}

bool operator <= (const int lhs, const RomanNumber& rhs)
{
    return (lhs < static_cast<int>(rhs) || lhs == static_cast<int>(rhs));
}

bool operator <= (const RomanNumber& lhs, const int rhs)
{
    return (static_cast<int>(lhs) < rhs || static_cast<int>(lhs) == rhs);
}

bool operator > (const int lhs, const RomanNumber& rhs)
{
    return (lhs > static_cast<int>(rhs));
}
bool operator > (const RomanNumber& lhs, const int rhs)
{
    return (static_cast<int>(lhs) > rhs);
}

bool operator >= (const int lhs, const RomanNumber& rhs)
{
    return (lhs > static_cast<int>(rhs) || lhs == static_cast<int>(rhs));
}
bool operator >= (const RomanNumber& lhs, const int rhs)
{
    return (static_cast<int>(lhs) > rhs || static_cast<int>(lhs) == rhs);
}

//---------------------------------------------------------

unsigned int operator + (unsigned int lhs, const RomanNumber& rhs)
{
    return (lhs += static_cast<int>(rhs));
}
RomanNumber operator + (const RomanNumber& lhs, unsigned int rhs)
{
    return (lhs += rhs);
}

unsigned int operator - (unsigned int lhs, const RomanNumber& rhs)
{
    return (lhs -= static_cast<int>(rhs));
}

RomanNumber operator - (const RomanNumber& lhs, unsigned int rhs)
{
    return (lhs -= rhs);
}

unsigned int operator * (unsigned int lhs, const RomanNumber& rhs)
{
    return (lhs *= static_cast<int>(rhs));
}

RomanNumber operator * (const RomanNumber& lhs, unsigned int rhs)
{
    return (lhs *= rhs);
}

unsigned int operator / (unsigned int lhs, const RomanNumber& rhs)
{
    return (lhs /= static_cast<int>(rhs));
}

RomanNumber operator / (const RomanNumber& lhs, unsigned int rhs)
{
    return (lhs /= rhs);
}

unsigned int operator += (unsigned int lhs, const RomanNumber& rhs)
{
    lhs+=static_cast<int>(rhs);
    return lhs;
}

unsigned int operator -= (unsigned int lhs, const RomanNumber& rhs)
{
    lhs -= static_cast<int>(rhs);
    return lhs;
}

unsigned int operator *= (unsigned int lhs, const RomanNumber& rhs)
{
    lhs *= static_cast<int>(rhs);
    return lhs;
}

unsigned int operator /= (unsigned int lhs, const RomanNumber& rhs)
{
    lhs /= static_cast<int>(rhs);
    return lhs;
}


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
