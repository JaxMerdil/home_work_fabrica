#include <iostream>
#include <string>

using namespace std;

struct Map
{
    char symbol;    // symbol
    int nSymRep; // N symbol repeat
};

bool CheckQuantitySymbol(const string& s,Map* arCharRep, int i);

int main()
{
    Map arCharRep[256]; //Array of characters repeat
    string str;
    cout << "Enter the string:";
    getline(cin, str);
    int i = 0;
    
    for (i=0; i < str.size(); i++)
    {
        if (CheckQuantitySymbol(str,arCharRep,i) == 0)
        {
            arCharRep[i].nSymRep = 1;
            arCharRep[i].symbol = str[i];
        }
    }
    cout << "Number of symbol repeats:" << endl;
    
    for (int j = 0; j <= i; j++)
    {
        if (arCharRep[j].nSymRep != 0)
            cout << arCharRep[j].symbol << " = " << arCharRep[j].nSymRep << endl;
    }
}

bool CheckQuantitySymbol(const string& s,Map* arCharRep, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (s[i] == arCharRep[j].symbol)
        {
            arCharRep[j].nSymRep++;
            return 1;
        }
    }
    return 0;
}


