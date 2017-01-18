#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------
template<class T>
void FillingMatrix(T* arr, int size)
{
    for(int i  = 0; i < size; i++)
    {
        arr[i] = rand()%20;
    }
}

template<>
void FillingMatrix(bool* arr, int size)
{
    for(int i  = 0; i < size; i++)
    {
        arr[i] = rand()%2;
    }
}
//-------------------------------------------------------------------

template<class T>
void PrintMatrix(T* arr, int size)
{
    for(int i  = 0; i < size; i++)
    {
        cout <<setw(4)<<arr[i];
    }
    cout << endl;
}

//-------------------------------------------------------------------

template<class T>
T  IncrementNum(T& value)
{
     return  value++;
}
//template<>
//bool IncrementNum(bool& value)
//{
//    return !value;
//}

//-------------------------------------------------------------------

template<class T, int N>
T FilterSymbol(const T& value)
{

    return value!=N;
}

//-------------------------------------------------------------------

template<class T>
T SumArr(const T& arrA,const T& arrB)
{
     return  arrA+arrB;
}

//-------------------------------------------------------------------

template<class T>
T* Map(T* arr, int size,  T (*MapFunc)(T&))
{
    for(int i = 0; i < size; i++)
    {
         MapFunc(arr[i]);
    }
    return arr;
}
//-------------------------------------------------------------------

template<class T>
T *Filter(T* arr, int size, int& newSize, T (*FilterFunc)(const T&))
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if( FilterFunc(arr[i]))
        {
            arr[j] = arr[i];
            j++;
        }
    }
    newSize = j;
    return arr;
}

//-------------------------------------------------------------------

template<class T>
T Reduce(T* arr, int size, T (*ReduceFupc)(const T&, const T&))
{
    T var = 0;
    for(int i = 0; i < size; i++)
    {
      var = ReduceFupc(var,arr[i]);
    }
    return var;
}

//-------------------------------------------------------------------

int main()
{
    srand(time(0));
    const int size = 20;
    int matrix[size];
    cout << "Массив: "<<endl;
    FillingMatrix(matrix, size);
    PrintMatrix(matrix, size);
    Map(matrix, size, IncrementNum<int>);
    cout << "Изменение функцией Map (++value): "<<endl;
    PrintMatrix(matrix, size);
    int newSize;
    cout<<"Изменение массива функцией Filter (Фильтр числа N (""N-символа"" в аски коде), bool фильтр 0): "<<endl;
    Filter(matrix, size, newSize, FilterSymbol<int,18>);
    PrintMatrix(matrix, newSize);
    cout <<"Свертка массива функция Redus: ";
    cout << Reduce(matrix, newSize, SumArr) << endl;
    return 0;
}
