#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void allocMemory(int m, int n, double **&matrix);
void fillRandomMatrix(int m, int n, double **matrix);
void outputMatrix(int m, int n, double **matrix);
void freeMemory(int m, double **matrix);
double detOTmatr(double** matrix);

int main()
{
    srand(time(NULL));
    double **matrix;
    matrix = 0;
    allocMemory(3, 3, matrix);
    fillRandomMatrix(3, 3, matrix);
    cout<<"Matr:"<<endl;
    outputMatrix(3, 3, matrix);
    cout << "Determinant="<<detOTmatr(matrix) << endl;
    freeMemory(3,matrix);
    return 0;
}
//определитель 3х3
double detOTmatr(double** matrix)
{
    double dOtM = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + \
            matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - \
            matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
    return dOtM;
}
//выделение памяти
void allocMemory(int m, int n, double **&matrix)
{
int i;
matrix = new double*[m];
for (i = 0; i < m; i++) {
matrix[i] = new double[n];
}
}
//Заполнение матрицы случайными числами
void fillRandomMatrix(int m, int n, double **matrix)
{
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
matrix[i][j] = rand() % 10;
}
}
}
//Вывод матрицы
void outputMatrix(int m, int n, double **matrix)
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
void freeMemory(int m, double **matrix)
{
for (int i = 0; i < m; i++) {
delete[] matrix[i];
}
delete[] matrix;
}
