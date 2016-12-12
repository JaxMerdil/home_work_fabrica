#include <iostream>
#include <cstring>

using namespace std;

void UpperFirstSymbol(const string& str1, string& str2);

int main()
{
    string str1;
    string str2;
    printf("Enter the string: ");
    getline(cin, str1);
    UpperFirstSymbol(str1,str2);
    return 0;
}

void UpperFirstSymbol(const string& st1, string& st2)
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
