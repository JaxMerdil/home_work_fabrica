#include <iostream>
#include <ctime>

using namespace std;

int* SwapSymbol(int* array, int size);

int* RandArr(int* array, int size);

void PrintArr(int* array, int size);

int main()
{
    srand(time(NULL));
    int size = 12;
    int* mass = new int[size];
    RandArr(mass, size);
    cout<<"Исходный массив: "<<endl;
    PrintArr(mass,size);
    SwapSymbol(mass, size);
    cout<<"Смена соседних четных и нечетных ячеек массива: "<<endl;
    PrintArr(mass,size);
    delete[] mass;
    return 0;
}

int* SwapSymbol(int* array, int size)
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

int* RandArr(int* array, int size)
{
    for (int i = 0; i<size; i++)
    {
        array[i] = rand() % 13;
    }
    return array;
}

void PrintArr(int* array, int size)
{
for (int i = 0; i < size; ++i)
{
    cout << array[i] << " ";
}
cout<< endl;
}
