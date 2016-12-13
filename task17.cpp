#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void MemoryAllocation(int **&matrix, const int m, const int n); //Выделение памяти
void FillRandomMatrix(int **matrix, const int m, const int n); //Заполнение матрицы случайными числами
int** FillingMatrix(int **matrix, const int m, const int n); //Заполнение матрици числами введенными в консоли
void OutputMatrix(int **matrix, const int m, const int n); //Вывод матрицы
void FreeMemory(int **matrix, const int m); //Освободить память
void MatrixMultiplication(int** matrix1,const int m1, const int n1, int** matrix2, const int m2, const int n2); //Умножение матриц и вывод результата

int main()
{
    //srand(time(NULL)); //Для варианта с рандомными значениями
    int **matrix1, colsMatr1 = 0,rowsMatr1 = 0;
    matrix1 = 0;
    cout << "Матрица 1: " << endl;
    cout << "Введите количество строк: ";
    cin >> rowsMatr1;
    cout << "Введите количество столбцов: ";
    cin >> colsMatr1;
    int **matrix2, colsMatr2 = 0,rowsMatr2 = 0;
    matrix2 = 0;
    cout << "Матрица 2: " << endl;
    cout << "Введите количество строк: ";
    cin >> rowsMatr2;
    cout << "Введите количество столбцов: ";
    cin >> colsMatr2;
    if(colsMatr1 != rowsMatr2)
    {
        cout << "Матрици не согласованы, количество столбцов матрици 1 должно быть равно количеству строк матрицы 2! " << endl;
        return 0;

    }
    else cout << "Матрицы согласованы выполним произведение:" << endl;

 //----------------------------------------------------------------------------------------------------------------------------
    MemoryAllocation(matrix1, rowsMatr1, colsMatr1);
    matrix1=FillingMatrix(matrix1,rowsMatr1,colsMatr1); //Для работы с числами введенными в консоли
    //Для проверки с рандомными числами
    //FillRandomMatrix(matrix1, rowsMatr1, colsMatr1);
    cout<<"Матрица 1:"<<endl;
    OutputMatrix(matrix1, rowsMatr1, colsMatr1);
//----------------------------------------------------------------------------------------------------------------------------
    MemoryAllocation(matrix2, rowsMatr2, colsMatr2);
    matrix2=FillingMatrix(matrix2,rowsMatr1,colsMatr1); //Для работы с числами введенными в консоли
    //Для проверки с рандомными числами
    //FillRandomMatrix(matrix2, rowsMatr2, colsMatr2);
    cout<<"Матрица 2:"<<endl;
    OutputMatrix(matrix2, rowsMatr2, colsMatr2);
//----------------------------------------------------------------------------------------------------------------------------
    cout << "Произведение двух матриц: " << endl;
    MatrixMultiplication(matrix1, rowsMatr1, colsMatr1, matrix2, rowsMatr2, colsMatr2);
    FreeMemory(matrix1, rowsMatr1);
    FreeMemory(matrix2, rowsMatr2);
    return 0;
}

//------------------------------------------------------------------------------------------

void MatrixMultiplication(int** matrix1,const int m1, const int n1, int** matrix2, const int m2, const int n2) //Умножение матриц и вывод результата
{
    int matr3[m2][n1];
    for(int i = 0; i < m1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            matr3[i][j]=0;
            for (int k = 0; k < m2; k++)
            {
                matr3[i][j]=matr3[i][j]+matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout<< setw(6)<< matr3[i][j] << ' ';
        }
        cout << endl;
    }
}

//------------------------------------------------------------------------------------------

int** FillingMatrix(int **matrix, const int m, const int n) //Заполнение матрици числами введенными в консоли
{
    for (int i = 0; i < m; i++)

    {
        for (int j = 0; j < n; j++)
        {
            cout << "Элемент матрици [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

//------------------------------------------------------------------------------------------

void MemoryAllocation(int **&matrix, const int m, const int n) //Выделение памяти
{
    int i;
    matrix = new int*[m];
    for (i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
    }
}

//------------------------------------------------------------------------------------------

void FillRandomMatrix(int **matrix, const int m, const int n) //Заполнение матрицы случайными числами
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 5;
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

//------------------------------------------------------------------------------------------
