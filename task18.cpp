//Ошибку с непонятками в выводе исправил, все ок
#include <iostream>

using namespace std;


//**************Структуры****************//
struct Professors;
struct student{
    char name[20]; //имя
    unsigned short age; //возраст
    float gpa; //ср.бал
    Professors* supervisor;//научный руководитель
};

struct Professors{
    char name[20]; //имя
    unsigned short age; //возраст
    unsigned int salary; //зарплата
};

//**************Прототипы****************//
void inPutSt(student* s); //зап. для студ.
void inPutPr(Professors* p); //зап. для проф.
float sB(student* p, int m); //ср.бал
void minGpa(student* p, int m);//мин.ср.бал
void maxGpa(student* p, int m);//макс.ср.бал
bool printStud(student* s,int m);//вывод инф. о студ.
bool printProf(Professors* p,int m);//вывод инф. о студ.
bool profFyeras(student* s, Professors* p,int m, int k);//

int main( )

{
    int n=0;
    cout<<"Введите количество студентов: ";
    cin>>n;
    student groupStud[n];
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"-й студент: ";
        inPutSt(&groupStud[i]);
    }
    printStud(groupStud,n);
    cout<<endl;
    cout<<"Средний бал: "<<sB(groupStud,n)<<endl;
    cout<<endl;
    minGpa(groupStud,n);
    cout<<endl;
    maxGpa(groupStud,n);

    int k=0;
    cout<<"Введите количество профессоров: ";
    cin>>k;
    Professors groupProf[k];
    

    for(int i=0;i<k;i++)
    {
        cout<<i+1<<"-й профессор: ";
        inPutPr(&groupProf[i]);
    }
    printProf(groupProf,k);
    profFyeras(groupStud,groupProf,n,k);


    return 0;
}


//***************Функции****************//
void inPutSt(student* s)
{
    cout<<"Имя:";
    cin.get();
    cin.getline((*s).name,20);
    cout<<"Возраст:";
    cin>>s->age;
    cout<<"Средний бал: ";
    cin>>s->gpa;
    cout<<endl;
}
//****************************************//
void inPutPr(Professors* p)
{
    cout<<"Имя:";
    cin.get();
    cin.getline((*p).name,20);
    cout<<"Возраст:";
    cin>>p->age;
    cout<<"Зарплата: ";
    cin>>p->salary;
    cout<<endl;
}
//****************************************//
float sB(student* p, int m)
{
    float sum=0;
    for(int i=0;i<m;i++)
    {
        sum=sum+p[i].gpa;
    }
    return sum/m;
}
//****************************************//
void minGpa(student* p, int m)
{
    float min=p[0].gpa;
    int temp=0;
    for(int i=0;i<m;i++)
    {
        if(min>p[i].gpa)
        {
        min=p[i].gpa;
        temp=i;
        }
    }
    cout<<"Студент с наименьшим средним балом балом:"<<p[temp].name<<" бал:"<<min<<endl;
}
//****************************************//
void maxGpa(student* p, int m)
{
    float max=p[0].gpa;
    int temp=0;
    for(int i=0;i<m;i++)
    {

        if(max<p[i].gpa)
        {
        max=p[i].gpa;
        temp=i;
        }
    }
    cout<<"Студент с наибольшим средним балом балом:"<<p[temp].name<<" бал:"<<max<<endl;
}
//****************************************//
bool printStud(student* s,int m)
{
    for(int i=0;i<m;i++)
    {
        cout<<"Студент "<<s[i].name<<", возраст "<<s[i].age<<"лет, средний бал "<<s[i].gpa<<endl;
    }
    return 1;
}
//****************************************//
bool printProf(Professors* p, int m)
{
    for(int i=0;i<m;i++)
    {
        cout<<"Профессор "<<p[i].name<<", возраст "<<p[i].age<<"лет, зарплата "<<p[i].salary<<endl;
    }
    return 1;
}
bool profFyeras(student* s, Professors* p,int m, int k)
{
    for(int i = 0 ; i < m ;i++)
        {
            int NstudProf;
            cout<<"Введите номер научного руководителя для студента "<<s[i].name;
            cin >> NstudProf;
            if(0 < NstudProf &&  NstudProf < k+1)
                s[i].supervisor = &p[NstudProf-1];
            else
                cout << "Проффесор под № " << NstudProf << " не существует.";
        }
    cout<<"Список студентов у которых научный руководитель старше 50 лет:"<<endl;
    for(int i = 0 ; i < m ;i++)
        {
            if(s[i].supervisor->age > 50)
            printf("Студент %s — научный руководитель: %s возраст научного руководителя %d \n",s[i].name,s[i].supervisor->name,s[i].supervisor->age);
        }
return 1;
}
