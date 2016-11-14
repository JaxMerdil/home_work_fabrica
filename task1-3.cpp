#include "iostream"
#include "iomanip"
#include "math.h"
#include "ctime"
#include "stdio.h"


using namespace std;

//--Задание 1.Написать функцию, которая будет проверять четность некоторого числа (с и без битовых операций).--//
int chetN1(int n)
{
    std::cout <<"Normal comparison:"<< (n % 2 == 0 ? "Even number" : "Odd number") << endl;
    return 0;
}

int chetN2(int a)
{
    if (a & 1) cout<<"Bitwise comparison:" <<"Odd number";
    else cout<<"Bitwise comparison:" <<"Even number";
    return 0;
}
//------------------------------------------------------------------------------------------------------------//
//--Задание 2.Написать функцию, которая рассчитывает сумму всех цифр некоторого
//трехзначного числа, введенного пользователем в консоли, без использования операторов цикла.--//
int sum3Z(int z)
{
    if (z>0)
        return z % 10 + sum3Z(z / 10);
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Russian");
//--То что было на паре задание--//
    //while (size_in_bits-- > 0)
    //{
    //	cout << ((c >> size_in_bits) & 1);
    //}
    //cout << endl;
//--То что нужно было получить (задом на перед)--//
    char c = 20;
    int size_in_bits = sizeof(char) * 8;
    int k = 1;
    while (k < size_in_bits)
    {
        cout << ((c >> k) & 1);
        k++;
    }
    cout << endl;
//Задача 1.
    int b;
    cout <<"Enter the number: ";
    cin >> b;
    chetN1(b);
    chetN2(b);
//Задача 2.
    cout << endl<<endl;
    cout <<"The sum of all digits of the number: sum="<< sum3Z(b)<<endl;

//Задача 3. Вывести все числа от 0 до 1000, которые одновременно содержат в себе цифры 1 и 7 (без преобразования в строку)--//
    cout << endl;
    cout << "All numbers are from 1 to 1000 which includes the numbers 1 and 7:"<<endl;
    for (int i = 0; i < 1000; i++)
        if (((i / 100) == 7 || ((i / 10) % 10) == 7 || (i % 10) == 7) && ((i / 100) == 1 || ((i / 10) % 10) == 1 || (i % 10) == 1))
            cout << i <<" ";
    cout << endl;

    return 0;
}
