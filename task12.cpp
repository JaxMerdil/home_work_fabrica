#include <iostream>
#include <time.h>

using namespace std;

int* swap(int* array, int size);

void* ran(int* array, int size);

int main()
{
    srand(time(NULL));
    int size = 12;
    int* array = new int[size];
    ran(array, size);
    cout << endl;
    swap(array, size);
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout<< endl;
    delete[]array;
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

void* ran(int* array, int size)
{
    for (int i = 0; i<size; i++)
    {
        array[i] = rand() % 13;
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
