#include <iostream>
#include <iomanip>
#include <template.h>

using namespace std;

int main()
{
    srand(time(0));
    const int size = 20;
    char matrix[size];
    cout << "Массив: "<<endl;
    FillingMatrix<char>(matrix, size);
    PrintMatrix(matrix, size);
    Map<char>(matrix, size, IncrementNum);
    cout << "Изменение функцией Map (++value): "<<endl;
    PrintMatrix(matrix, size);
    int newSize;
    cout<<"Изменение массива функцией Filter (Фильтр числа 74 (""J"" в аски коде), bool фильтр 0): "<<endl;
    Filter<char>(matrix, size, newSize, MultipleTwo);
    PrintMatrix(matrix, newSize);
    cout <<"Свертка массива функция Redus: ";
    cout << Reduce<char>(matrix, newSize, MultiplicationTwoArr) << endl;
    return 0;
}
