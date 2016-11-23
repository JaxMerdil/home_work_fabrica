#include <iostream>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

//Выделение памяти
void allocMemory(int m, int n, int **&matrix);
//Заполнение матрицы случайными числами
void fillRandomMatrix(int m, int n, int **matrix);
//Разворот матрици
void matr90s(int m, int n, int **matrix);
//Вывод матрицы
void outputMatrix(int m, int n, int **matrix);
//Освободить память
void freeMemory(int m,int **matrix);

int main()
{
srand(time(NULL));
int m, n;
int **matrix;
matrix = 0;
cout<<"Введите количество строк: ";
cin>>m;
cout<<"Введите количество столбцов: ";
cin>>n;
allocMemory(m, n, matrix);
fillRandomMatrix(m, n, matrix);
cout<<"Matr №1"<<endl;
outputMatrix(m, n, matrix);
cout<<"***************************************************"<<endl;
cout<<"Matr №2"<<endl;
matr90s(m,n,matrix);
freeMemory(m, matrix);

return 0;
}
void matr90s(int m, int n, int **matrix)
{
    int matrix2[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix2[j][m-1-i]=matrix[i][j];
        }
    }
    //outputMatrix
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < m; j++)
    {
    cout<< setw(6)<< matrix2[i][j] << ' ';
    }
    cout << '\n';
    }
}
//Выделение памяти
void allocMemory(int m, int n, int **&matrix)
{
int i;
matrix = new int*[m];
for (i = 0; i < m; i++) {
matrix[i] = new int[n];
}
}
//Заполнение матрицы случайными числами
void fillRandomMatrix(int m, int n, int **matrix)
{
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
matrix[i][j] = rand() % 10;
}
}
}
//Вывод матрицы
void outputMatrix(int m, int n, int **matrix)
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
//Освобождение памяти
void freeMemory(int m, int **matrix)
{
for (int i = 0; i < m; i++) {
delete[] matrix[i];
}
delete[] matrix;
}
