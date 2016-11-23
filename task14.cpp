#include <iostream>
#include <time.h>

using namespace std;

void passGen(void);

int main()
{
    passGen();
    return 0;
}

void passGen(void)
{
    srand(time(NULL));
    char str[8];
    int k;
    for(int i=0;i<8;i++)
    {
        k=rand()%74+48;
        if((k>=58&&k<=64)||(k>=91&&k<=94)||(k==96)) {i--; continue;}
            else str[i]=k;
        cout<<str[i];
    }
    cout<<endl;
}
