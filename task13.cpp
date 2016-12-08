#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>

using namespace std;

int *array(int *ar);
void printArr(int* ar);
int *randSornArray(int *ar);


int main()
{
    int size=50;
    srand(time(NULL));
    int *mass = new int[size];
    array(mass);
    cout<<"Первый массив: "<<endl;
    printArr(mass);
    cout<<endl;
    randSornArray(mass);
    cout<<"Массив в случайном порядке: "<<endl;
    printArr(mass);
    delete[] mass;
    return 0;
}



int *array(int *ar)
{
    int pSp=1;
    for(int i=0; i<100; i++)
    {
      ar[i]=pSp;
      pSp+=2;
    }
    return ar;
}

void printArr(int* ar)
{
    for(int i=0; i<50; i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

int* randSornArray(int *ar)
{
    int temp,j;
    srand(time(NULL));
    for(int i=0; i<50; i++)
    {
        j=rand()%50;
        temp=ar[i];
        ar[i]=ar[j];
        ar[j]=temp;
    }
    return ar;
}

