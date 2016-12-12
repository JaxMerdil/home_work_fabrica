#include <iostream>
#include <cstring>

using namespace std;

char* AlgorithmCaesars(char* st);

int main()
{
    char str[24];
    cout << "Alphabet (abcdefgh123456-0), offset 5: ";
    cin >> str;
    cout << "Result:";
    cout << AlgorithmCaesars(str) << endl;
    return 0;
}

char* AlgorithmCaesars(char* st)
{
    char* cipherTable = "abcdefgh123456-0";
    char* encrypt = new char[strlen(st)];
        for(int i = 0; i<strlen(st); i++)
        {
            for(int j = 0; j<strlen(cipherTable); j++)
            {
                if(st[i] == cipherTable[j])
                {
                encrypt[i] = cipherTable[(j+5)%strlen(cipherTable)];
                }
            }
        }
    return encrypt;
}
