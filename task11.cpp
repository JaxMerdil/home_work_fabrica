#include <iostream>
#include <cstring>

using namespace std;

void DeleteFirstWordSymbols(const string& st);

int main()
{
    string st1;
    printf("Enter the string: ");
    getline(cin, st1);
    DeleteFirstWordSymbols(st1);
    return 0;
}

void DeleteFirstWordSymbols(const string& str1)
{
    int j=0;
    char st2[str1.length()];
    for(int i=1; i < str1.length(); i++)
    {
        st2[j]=str1[i];
        j++;

        if(str1[i] == ' ')
        {
            i++;
        }
    }
    printf(st2);
    cout<<endl;
}
