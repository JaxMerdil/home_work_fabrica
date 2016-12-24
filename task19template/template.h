#ifndef TEMPLATE_H
#define TEMPLATE_H
#include<iomanip>
#include<iostream>
#include<cstring>

using namespace std;


//-------------------------------------------------------------------
template<class TFillingMatrix>
void FillingMatrix(TFillingMatrix* arr,const int size)
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

template<class TPrintMatrix>
void PrintMatrix(TPrintMatrix* arr, int size)
{
    for(int i  = 0; i < size; i++)
    {
        cout <<setw(4)<<arr[i];
    }
    cout << endl;
}

//-------------------------------------------------------------------

template<class TIncrementNum>
TIncrementNum IncrementNum(TIncrementNum value)
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

template<class TMultipleTwo>
TMultipleTwo MultipleTwo(TMultipleTwo value)
{

    return value!=(TMultipleTwo)74; // 74 = 'J'
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

template<class TMultiplicationTwoArr>
TMultiplicationTwoArr MultiplicationTwoArr(TMultiplicationTwoArr arrA, TMultiplicationTwoArr arrB)
{
     return  arrA+arrB;
}

template<>
char MultiplicationTwoArr(char arrA, char arrB)
{

     return  arrA+arrB;
}
//-------------------------------------------------------------------

template<class TMap>
TMap *Map(TMap* arr, const int size, TMap (*MapFunc)(TMap))
{
    for(int i = 0; i < size; i++)
    {
        arr[i]  = MapFunc(arr[i]);
    }
    return arr;
}

//-------------------------------------------------------------------

template<class TFilter>
TFilter *Filter(TFilter arr[], const int size, int& newSize, TFilter (*FilterFunc)(TFilter))
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

template<class TReduce>
TReduce Reduce(TReduce* arr, const int size, TReduce (*ReduceFupc)(TReduce, TReduce))
{
    TReduce var = 0;
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

#endif // TEMPLATE_H
