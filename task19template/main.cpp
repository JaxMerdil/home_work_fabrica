#include <iostream>
#include <iomanip>
#include<cstring>

using namespace std;

//-------------------------------------------------------------------
template<class T>
void FillingMatrix(T* arr,const int size)
{
    for(int i  = 0; i < size; i++)
    {
        arr[i] = rand()%25+65;
    }
}
template<>
void FillingMatrix(char* arr,const int size)
{
    for(int i  = 0; i < size; i++)
    {
        arr[i] = rand()%25+65;
    }
}
template<>
void FillingMatrix(bool* arr,const int size)
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
T IncrementNum(T value)
{
    return ++value;
}
template<>
bool IncrementNum(bool value)
{
    if(value==1) return value=0;
            else return value=1;
}

//-------------------------------------------------------------------

template<class T>
T MultipleTwo(T value)
{

    return value!=(T)74; // 74 = 'J'
}

template<>
char MultipleTwo(char value)
{

    return value!='J';
}

template<>
bool MultipleTwo(bool value)
{

    return value!=0;
}

//-------------------------------------------------------------------

template<class T>
T MultiplicationTwoArr(T arrA, T arrB)
{
     return  arrA+arrB;
}

template<>
char MultiplicationTwoArr(char arrA, char arrB)
{

     return  arrA+arrB;
}
//-------------------------------------------------------------------

template<class T>
T *Map(T* arr, const int size, T (*MapFunc)(T))
{
    for(int i = 0; i < size; i++)
    {
        arr[i]  = MapFunc(arr[i]);
    }
    return arr;
}

//-------------------------------------------------------------------

template<class T>
T *Filter(T arr[], const int size, int& newSize, T (*FilterFunc)(T))
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
T Reduce(T* arr, const int size, T (*ReduceFupc)(T, T))
{
    T var = 0;
    for(int i = 0; i < size; i++)
    {
      var = ReduceFupc(var,arr[i]);
    }
    return var;
}

template<>
char Reduce(char* arr, const int size, char (*ReduceFupc)(char, char))
{
    char var = 0;
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
    Map(matrix, size, IncrementNum);
    cout << "Изменение функцией Map (++value): "<<endl;
    PrintMatrix(matrix, size);
    int newSize;
    cout<<"Изменение массива функцией Filter (Фильтр числа 74 (""J"" в аски коде), bool фильтр 0): "<<endl;
    Filter(matrix, size, newSize, MultipleTwo);
    PrintMatrix(matrix, newSize);
    cout <<"Свертка массива функция Redus: ";
    cout << Reduce(matrix, newSize, MultiplicationTwoArr) << endl;
    return 0;
}
