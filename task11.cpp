#include <iostream>
#include <string>

using namespace std;



void delS1(string st)
{
    int i=0;
    while (i != st.length())
    {
        if ((i == 0) || (st[i - 1] == ' '))
        st.erase(i, 1);
        i++;
    }
    cout << st << endl;
}

int main()
{
    string st1;
    printf("Enter the string: ");
    getline(cin, st1);
    delS1(st1);
    return 0;
}
