#include <iostream>
#include <ctime>

using namespace std;

void PassGen(void);

int main()
{
    cout<<"Password of 8 symbol: ";
    PassGen();
    return 0;
}

void PassGen(void)
{
    srand(time(NULL));
    char str[8];
    int k;
    for(int i=0;i<8;i++)
    {
        k=rand()%74+48;
        if((k>=58&&k<=64)||(k>=91&&k<=94)||(k==96))
        {
            i--;
            continue;
        }
        else str[i]=k;
        cout<<str[i];
    }
    cout<<endl;
}
