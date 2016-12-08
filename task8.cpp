#include <iostream>
#include <string>

using namespace std;

struct map1
{
    char str;
    int N;
} M[100];

bool checkQuantitySymbol(const string& s, int i);

int main()
{
    string s;
    cout << "Enter the string:";
    getline(cin, s);
    int i = 0;
    ///////
    for (; i < s.size(); i++)
    {
        if (checkQuantitySymbol(s, i) == 0)
        {
            M[i].N = 1;
            M[i].str = s[i];
        }
    }
    cout << "Number of symbol repeats:" << endl;
    ///////
    for (int j = 0; j <= i; j++)
    {
        if (M[j].N != 0)
            cout << M[j].str << " = " << M[j].N << endl;
    }
}

bool checkQuantitySymbol(const string& s, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (s[i] == M[j].str)
        {
            M[j].N++;
            return 1;
        }
    }
    return 0;
}
