#include <iostream>
#include <ctime>

using namespace std;

int *InitArray(int *arr,const int size);
void PrintArr(int* arr,const int size);
int *RandomizeSortedArray(int *arr,const int size);


int main()
{
    int size=50;
    srand(time(NULL));
    int *mass = new int[size];
    InitArray(mass,size);
    cout<<"Первый массив: "<<endl;
    PrintArr(mass,size);
    cout<<endl;
    RandomizeSortedArray(mass,size);
    cout<<"Массив в случайном порядке: "<<endl;
    PrintArr(mass,size);
    delete[] mass;
    return 0;
}

int *InitArray(int *arr,const int size)
{
    int fSymbol=1;
    for(int i=0; i<size; i++)
    {
        arr[i]=fSymbol;
        fSymbol+=2;
    }
    return arr;
}

void PrintArr(int* arr,const int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int* RandomizeSortedArray(int *arr,const int size)
{
    int j=0;
    srand(time(NULL));
    for(int i=0; i<size; i++)
    {
        j=rand()%size;
        swap(arr[i], arr[j]);
    }
    return arr;
}
