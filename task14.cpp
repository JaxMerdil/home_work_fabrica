#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    char pas[8] = {0};
    bool upS, dwS, numS;
    int k;
    upS=dwS=numS=0;
    while (upS != 1 || dwS != 1 || numS != 1)
    {
        for (size_t i = 0; i < sizeof(pas); i++)
        {
            k=rand()%74+48;
            if((k>=58&&k<=64)||(k>=91&&k<=94)||(k==96))
            {
                i--;
                continue;
            }
            else pas[i]=k;

            if (pas[i] >= 'A' && pas[i] <= 'Z')
            {
                upS = 1;
            }
            else if (pas[i] >= 'a' && pas[i] <= 'z')
            {
                dwS = 1;
            }
            else if (pas[i] >= '0' && pas[i] <= '9')
            {
                numS = 1;
            }
        }
    }
    for (size_t i = 0; i < sizeof(pas); i++)
    {
        cout << pas[i];
    }
    cout << endl;
    return 0;
}
