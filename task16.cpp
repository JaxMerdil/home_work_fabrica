#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void MemoryAllocation(double **&matrix, const int m, const int n); //Выделение памяти
void FillRandomMatrix(double **matrix, const int m, const int n); //Заполнение матрицы случайными числами
void OutputMatrix(double **matrix, const int m, const int n); //Вывод матрицы
void FreeMemory(double **matrix, const int m); //Освободить память
double DeterminantMatrix(double** matrix);

int main()
{
    const int size=3;
    srand(time(NULL));
    double **matrix;
    matrix = 0;
    MemoryAllocation(matrix, size, size);
    FillRandomMatrix(matrix, size, size);
    cout<<"Matr:"<<endl;
    OutputMatrix(matrix, size, size);
    cout << "Determinant="<<DeterminantMatrix(matrix) << endl;
    FreeMemory(matrix, size);
    return 0;
}

//------------------------------------------------------------------------------------------

double DeterminantMatrix(double** matrix)
{
    double detMatr = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + \
            matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - \
            matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
    return detMatr;
}

//------------------------------------------------------------------------------------------

void MemoryAllocation(double **&matrix, const int m, const int n) //Выделение памяти
{
    int i;
    matrix = new double*[m];
    for (i = 0; i < m; i++)
    {
        matrix[i] = new double[n];
    }
}

void FillRandomMatrix(double **matrix, const int m, const int n) //Заполнение матрицы случайными числами
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

//------------------------------------------------------------------------------------------

void OutputMatrix(double **matrix, const int m, const int n) //Вывод матрицы
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

void FreeMemory(double **matrix, const int m) //Освобождение памяти
{
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
