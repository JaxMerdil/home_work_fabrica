#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;


void fooCat(char *str1, const char *str2);

int main()
{
    int size=100;
    char* str1= new char[size]();
    char* str2= new char[size]();
    cout<<"Введите первую строку: ";
    gets(str1);
    cout<<"Введите вторую строку: ";
    gets(str2);
    fooCat(str1, str2);
    printf(str1);
    delete[]str1;
    delete[]str2;
    return 0;
}

void fooCat(char *str1, const char *str2){
str1 += strlen(str1);
while(*str2){
*str1 = *str2;
str1++;
str2++;
}
*str1='\0';
}
