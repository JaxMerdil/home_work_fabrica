#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
    srand(time(0));
    char pas[8] = {0};
    bool upS, dwS, numS;
    upS=dwS=numS=0;
    const char* passwComponents[] = {"abcdefghijklmnopqrstuvwxyz",
                                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                                     "1234567890_-"
                                    };
    while (upS != 1 || dwS != 1 || numS != 1)
    {
        for (size_t i = 0; i < sizeof(pas); i++)
        {
            int ran = 0;
            ran = rand()%3;
            const char* comp = passwComponents[ran];
            pas[i] = comp[rand()% strlen(comp)];
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
            cout << pas[i];
        }
    }
}
