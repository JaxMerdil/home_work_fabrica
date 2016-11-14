#include <iostream>

using namespace std;

int sum3Z(int z)
{
    if (z>0)
        return z % 10 + sum3Z(z / 10);
    return 0;
}


bool square(int num)
{
    const int f = 2;
    int b = 1;
    while (b < num)
        b *= f;
    return b == num;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Number";
    if (!square(num))
        cout << "the number is not a power of 2"<< endl;
    else cout << "the number is a power of 2" << endl;

    return 0;
}
