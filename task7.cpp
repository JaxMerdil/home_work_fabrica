#include <iostream>
#include <stdio.h>
using namespace std;


void* cat(char *str1, const char *str2)
{
while(*str1) str1++;
while(*str2)
{
*str1 = *str2;
str1++;
str2++;
}
*str1='\0';
}
int main()
{
    char* str1, *str2;
    str1 = new char[100];
    str2 = new char[100];
    memset(str1, 0, 100);
    memset(str2, 0, 100);
    gets_s(str1);
    gets_s(str2,100);
    cat(str1, str2);
    printf(str1);
    delete[]str1;
    delete[]str2;
    return 0;
}
