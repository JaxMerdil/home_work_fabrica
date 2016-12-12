#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>

using namespace std;

int *array(int *ar,const int size);
void printArr(int* ar,const int size);
int *randSornArray(int *ar,const int size);


int main()
{
    int size=50;
    srand(time(NULL));
    int *mass = new int[size];
    array(mass,size);
    cout<<"Первый массив: "<<endl;
    printArr(mass,size);
    cout<<endl;
    randSornArray(mass,size);
    cout<<"Массив в случайном порядке: "<<endl;
    printArr(mass,size);
    delete[] mass;
    return 0;
}



int *array(int *ar,const int size)
{
    int pSp=1;
    for(int i=0; i<size; i++)
    {
      ar[i]=pSp;
      pSp+=2;
    }
    return ar;
}

void printArr(int* ar,const int size)
{
    for(int i=0; i<size; i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

int* randSornArray(int *ar,const int size)
{
    int temp,j;
    srand(time(NULL));
    for(int i=0; i<size; i++)
    {
        j=rand()%size;
        temp=ar[i];
        ar[i]=ar[j];
        ar[j]=temp;
    }
    return ar;
}
