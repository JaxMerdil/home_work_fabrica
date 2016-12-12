#include <iostream>
#include <cstring>

using namespace std;

void DelFSymAftSp(string& st); //Delete first symbol after the space

int main()
{
    string st1;
    printf("Enter the string: ");
    getline(cin, st1);
    DelFSymAftSp(st1);
    return 0;
}

void DelFSymAftSp(string& str1)
{
    int j=0;
    char st2[str1.length()];
    for(int i=1;i<str1.length();i++)
    {
        if(str1[i] == ' ')
        {
            st2[j]=str1[i];
            i++;
            j++;
        }
          else
          {
            st2[j]=str1[i];
            j++;
          }
    }
    printf(st2);
    cout<<endl;
}
