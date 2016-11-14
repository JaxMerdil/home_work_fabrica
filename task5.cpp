#include <iostream>

using namespace std;

bool qube(int num)
{
    const int f = 3;
    int b = 1;
    while (b < num)
        b *= f;
    return b == num;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int num;
    cout << "Enterthe number: ";
    cin >> num;
    cout << "Number ";
        if (!qube(num))
            cout <<num<< " is not a power of 3" << endl;
        else cout<<num << " is not a power of 3" << endl;
    return 0;
}
