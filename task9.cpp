#include <iostream>
#include <cstring>

using namespace std;

char* algOfCesar(char* st);

int main()
{
char srt[24];
cout << "Alphabet (abcdefgh123456-0), offset 5: ";
cin >> srt;
cout << "Result:";
cout << algOfCesar(srt) << endl;
return 0;
}

char* algOfCesar(char* st)
{
char* cipherT = "abcdefgh123456-0";
char* encrypt = new char[strlen(st)];
for(int i = 0; i<strlen(st); i++)
for(int j = 0; j<strlen(cipherT); j++)
if(st[i] == cipherT[j])
if((strlen(cipherT)-j) <= 5)
encrypt[i] = cipherT[(j+5)%strlen(cipherT)];
else
encrypt[i] = cipherT[j+5];
return encrypt;
}
