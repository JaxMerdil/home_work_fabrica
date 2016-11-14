#include <iostream>

using namespace std;



bool step2(int a) {
    if ((a & (a - 2)) == 0)return 1;
    else return 0;
}

int main()
{
    cout<<"Enter the number";
    int n;
    cin >> n;
    if (step2(n))cout << "Stepen 2"<<endl;
    else cout << "Ne yavl step 2"<<endl;
    return 0;
}
