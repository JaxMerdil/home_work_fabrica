#include <iostream>
#include <iomanip>

typedef int(*MapFunc)(int);
typedef int(*FilterFunc)(int);
typedef int(*ReduceFupc)(int, int);

using namespace std;

//-------------------------------------------------------------------

int SquareNum(int value);
int MultipleTwo(int arr);
int MultiplicationTwoArr(int arrA, int arrB);

//-------------------------------------------------------------------

int *Map(int *arr, const int size, MapFunc mapper);
int *Filter(int x[], const int size, int& newSize, FilterFunc arrFilter);
int Reduce(int* x, const int size, ReduceFupc arrRedus);
void FillingMatrix(int* arr,const int size);
void PrintMatrix(int* arr, int size);

//-------------------------------------------------------------------

int main()
{
//    srand(time(0));
    const int size = 20;
    int matrix[size];
    cout << "Массив: "<<endl;
    FillingMatrix(matrix, size);
    PrintMatrix(matrix, size);
    Map(matrix, size, SquareNum);
    cout << "Изменение функцией Map (возведение в квадрат): "<<endl;
    PrintMatrix(matrix, size);
    int newSize;
    cout<<"Изменение массива функцией Filter (деление на 2 без остатка): "<<endl;
    Filter(matrix, size, newSize, MultipleTwo);
    PrintMatrix(matrix, newSize);
    cout <<"Свертка массива функция Redus: ";
    cout << Reduce(matrix, newSize, MultiplicationTwoArr) << endl;
    return 0;
}

//-------------------------------------------------------------------

int SquareNum(int value)
{
    return value*value;
}

//-------------------------------------------------------------------

int MultipleTwo(int arr)
{
    return arr%2==0;
}

//-------------------------------------------------------------------

int MultiplicationTwoArr(int arrA, int arrB)
{
     return  arrA+arrB;
}

//-------------------------------------------------------------------

int *Map(int* arr, const int size, MapFunc mapper)
{
    for(int i = 0; i < size; i++)
    {
        arr[i]  = mapper(arr[i]);
    }
    return arr;
}

//-------------------------------------------------------------------

int *Filter(int arr[], const int size, int& newSize, FilterFunc arrFilter)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if( arrFilter(arr[i]))
        {
            arr[j] = arr[i];
            j++;
        }
    }
    newSize = j;
    return arr;
}

//-------------------------------------------------------------------

int Reduce(int* arr, const int size, ReduceFupc arrRedus)
{
    int var = 0;
    for(int i = 0; i < size; i++)
    {
      var = arrRedus(var,arr[i]);
    }
    return var;
}

//-------------------------------------------------------------------

void FillingMatrix(int* arr,const int size)
{
    for(int i  = 0; i < size; i++)
    {
        arr[i] = rand()%10;
    }
}

//-------------------------------------------------------------------

void PrintMatrix(int* arr, int size)
{
    for(int i  = 0; i < size; i++)
    {
        cout <<setw(4)<<arr[i];
    }
    cout << endl;
}

//-------------------------------------------------------------------
