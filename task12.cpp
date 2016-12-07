#include <iostream>
#include <time.h>

using namespace std;

int* swap(int* array, int size);

int* randArr(int* array, int size);

void printArr(int* array, int size);

int main()
{
    srand(time(NULL));
    int size = 12;
    int* mass = new int[size];
    randArr(mass, size);
    cout<<"Исходный массив: "<<endl;
    printArr(mass,size);
    swap(mass, size);
    cout<<"Смена соседних четных и нечетных ячеек массива: "<<endl;
    printArr(mass,size);
    delete[] mass;
    return 0;
}

int* swap(int* array, int size)
{
    for (int i = 0; i<size; i += 2)
    {
        int temp = 0;
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
    return array;
}

int* randArr(int* array, int size)
{
    for (int i = 0; i<size; i++)
    {
        array[i] = rand() % 13;
    }
    return array;
}

void printArr(int* array, int size)
{
for (int i = 0; i < size; ++i)
{
    cout << array[i] << " ";
}
cout<< endl;
}
