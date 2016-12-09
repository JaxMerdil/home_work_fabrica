#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

void delS1(string& st);

int main()
{
    string st1;
    printf("Enter the string: ");
    getline(cin, st1);
    delS1(st1);
    return 0;
}

void delS1(string& str1)
{
    int j=0;
    char st2[str1.length()];
    for(int i=0;i<str1.length();i++)
    {
        if (i == 0) continue;
           if(str1[i] == ' ') {st2[j]=str1[i]; i++; j++;}
             else {st2[j]=str1[i]; j++;}
    }
    printf(st2);
    cout<<endl;
}
