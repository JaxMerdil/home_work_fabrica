#include <iostream>
#include <string>

using namespace std;

struct map
{
    char symbol;
    int nSymRep; // N symbol repeat
} ArCharRep[256]; //Array of characters repeat

bool CheckQuantitySymbol(const string& s,const int i);

int main()
{
    string str;
    cout << "Enter the string:";
    getline(cin, str);
    int i = 0;

    for (i=0; i < str.size(); i++)
    {
        if (CheckQuantitySymbol(str, i) == 0)
        {
            ArCharRep[i].nSymRep = 1;
            ArCharRep[i].symbol = str[i];
        }
    }
    cout << "Number of symbol repeats:" << endl;

    for (int j = 0; j <= i; j++)
    {
        if (ArCharRep[j].nSymRep != 0)
            cout << ArCharRep[j].symbol << " = " << ArCharRep[j].nSymRep << endl;
    }
}

bool CheckQuantitySymbol(const string& s,const int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (s[i] == ArCharRep[j].symbol)
        {
            ArCharRep[j].nSymRep++;
            return 1;
        }
    }
    return 0;
}
