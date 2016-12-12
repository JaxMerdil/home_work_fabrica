#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void MemoryAllocation(int **&matrix, const int m, const int n); //Выделение памяти
void FillRandomMatrix(int **matrix, const int m, const int n); //Заполнение матрицы случайными числами
void TurnMatrix90(int **matrix, const int m, const int n); //Разворот матрици
void OutputMatrix(int **matrix, const int m, const int n); //Вывод матрицы
void FreeMemory(int **matrix, const int m); //Освободить память

int main()
{
    srand(time(NULL));
    int nRaws, nCols;
    int **matrix;
    matrix = 0;
    cout<<"Введите количество строк: ";
    cin>>nRaws;
    cout<<"Введите количество столбцов: ";
    cin>>nCols;
    MemoryAllocation(matrix, nRaws, nCols);
    FillRandomMatrix(matrix, nRaws, nCols);
    cout<<"Matr №1:"<<endl;
    OutputMatrix(matrix, nRaws, nCols);
    cout<<"******************************************"<<endl;
    cout<<"Matr №2:"<<endl;
    TurnMatrix90(matrix, nRaws, nCols);
    FreeMemory(matrix, nRaws);
    return 0;
}

//------------------------------------------------------------------------------------------

void TurnMatrix90(int **matrix, const int m, const int n) //Переворот матрици на 90градусов
{
    int matrix2[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix2[j][m - 1 - i]=matrix[i][j];
        }
    }
    //OutputMatrix2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<setw(6)<< matrix2[i][j] << ' ';
        }
        cout << '\n';
    }
}

//------------------------------------------------------------------------------------------

void MemoryAllocation(int **&matrix, const int m, const int n) //Выделение памяти
{
    int i;
    matrix = new int*[m];
    for (i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
}

void FillRandomMatrix(int **matrix, const int m, const int n) //Заполнение матрицы случайными числами
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

//------------------------------------------------------------------------------------------

void OutputMatrix(int **matrix, const int m, const int n) //Вывод матрицы
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< setw(6)<< matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

//------------------------------------------------------------------------------------------

void FreeMemory(int **matrix, const int m) //Освобождение памяти
{
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
