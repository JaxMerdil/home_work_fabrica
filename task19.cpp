#include <iostream>
#include <iomanip>

using namespace std;

//-------------------------------------------------------------------

int SquaringSymbolArr(int arr);
bool MultipleTwo(int arr);
int MultiplicationTwoArr(int arrA, int arrB);

//-------------------------------------------------------------------

int *Map(int *arr, const int size, int (*arr_p)(int));
int *Filter(int x[], const int size, int& newSize, bool (*arrFilter)(int));
int Redus(int* x, const int size, int (*arrRedus)(int, int));
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
    Map(matrix, size, SquaringSymbolArr);
    cout << "Изменение функцией Map (возведение в квадрат): "<<endl;
    PrintMatrix(matrix, size);
    int newSize;
    cout<<"Изменение массива функцией Filter (деление на 2 без остатка): "<<endl;
    Filter(matrix, size, newSize, MultipleTwo);
    PrintMatrix(matrix, newSize);
    cout <<"Свертка массива функция Redus: ";
    cout << Redus(matrix, newSize, MultiplicationTwoArr) << endl;
    return 0;
}

//-------------------------------------------------------------------

int SquaringSymbolArr(int arr)
{
    return arr*arr;
}

//-------------------------------------------------------------------

bool MultipleTwo(int arr)
{
    if(arr%2==0)
    {
        return 1;
    }
    return 0;
}

//-------------------------------------------------------------------

int MultiplicationTwoArr(int arrA, int arrB)
{
     return  arrA+arrB;
}

//-------------------------------------------------------------------

int *Map(int* arr, const int size, int (*arr_p)(int))
{
    for(int i = 0; i < size; i++)
    {
        arr[i]  = arr_p(arr[i]);
    }
    return arr;
}

//-------------------------------------------------------------------

int *Filter(int arr[], const int size, int& newSize, bool (*arrFilter)(int))
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if( arrFilter(arr[i]))
        {//filtering mas by user function
            arr[j] = arr[i];
            j++;
        }
    }
    newSize = j;//new size mas
    return arr;
}

//-------------------------------------------------------------------

int Redus(int* arr, const int size, int (*arrRedus)(int, int))
{
    int Multiplication = 0;
    for(int i = 0; i < size; i++)
    {
      Multiplication = arrRedus(Multiplication,arr[i]);
    }
    return Multiplication;
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
