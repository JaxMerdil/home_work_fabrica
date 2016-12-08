#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

void upperFirstSymbol(const string& st1, string& st2);

int main()
{
    string st1;
    string st2;
    printf("Enter the string: ");
    getline(cin, st1);
    upperFirstSymbol(st1,st2);
    return 0;
}

void upperFirstSymbol(const string& st1, string& st2)
{
    int i=0;
    st2=st1;
    while (i < st1.length()){
        if ((i == 0) || (st1[i - 1] == ' '))
        st2[i]=toupper(st2[i]);
        i++;
    }
    cout << st1 << endl;
    cout <<"New string: "<<st2 << endl;
}


