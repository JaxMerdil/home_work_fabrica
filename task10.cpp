#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

void sst(string st1, string st2);

int main()
{
    string st1;
    string st2;
    printf("Enter the string: ");
    getline(cin, st1);
    sst(st1,st2);
    return 0;
}

void sst(string st1, string st2)
{
    for (int i = 0; i < st1.length(); i++)
    {
        if (i == 0)
            st1[i] = toupper(st1[i]);

        if (isspace(st1[i])) {
            st2 += st1[i];
            st2 += toupper(st1[++i]);
        }
        else
            st2 += st1[i];


    }
    cout <<"New string: "<<st2 << endl;
}

