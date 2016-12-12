#include <iostream>

using namespace std;


//**************Структуры****************//
struct Professors;
struct student
{
    char name[20]; //имя
    unsigned short age; //возраст
    unsigned int gpa; //ср.бал
    Professors* supervisor;//научный руководитель
};

struct Professors
{
    char name[20]; //имя
    unsigned short age; //возраст
    unsigned int salary; //зарплата
};

//**************Прототипы****************//
void InputStudent(student* Stud); //зап. для студ.
void InputProfessors(Professors* Prof); //зап. для проф.
float GpaStudent(student* Stud, int m); //ср.бал
void MinGpa(student* Stud, int m);//мин.ср.бал
void MaxGpa(student* Stud, int m);//макс.ср.бал
bool PrintStudent(student* Stud, int m);//вывод инф. о студ.
bool PrintProfessors(Professors* Prof, int m);//вывод инф. о студ.
bool ProfessorsOlder50(student* Stud, Professors* Prof, int m, int k);//

int main( )

{
    int nStud=0;
    cout << "Введите количество студентов: ";
    cin >> nStud;
    student groupStud[nStud];
    for(int i = 0; i < nStud; i++)
    {
        cout << i + 1 << "-й студент: ";
        InputStudent(&groupStud[i]);
    }
    PrintStudent(groupStud, nStud);
    cout << endl;
    cout << "Средний бал: " << GpaStudent(groupStud, nStud) << endl;
    cout << endl;
    MinGpa(groupStud, nStud);
    cout << endl;
    MaxGpa(groupStud, nStud);
    
    int nProf = 0;
    cout << "Введите количество профессоров: ";
    cin >> nProf;
    Professors groupProf[nProf];
    
    
    for(int i = 0; i < nProf; i++)
    {
        cout << i + 1 << "-й профессор: ";
        InputProfessors(&groupProf[i]);
    }
    PrintProfessors(groupProf, nProf);
    ProfessorsOlder50(groupStud, groupProf, nStud, nProf);
    
    
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------

//***************Функции****************//
void InputStudent(student* Stud)
{
    cout << "Имя:";
    cin.get();
    cin.getline((*Stud).name, 20);
    cout << "Возраст:";
    cin>>Stud->age;
    cout << "Средний бал: ";
    cin >> Stud->gpa;
    cout << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------

void InputProfessors(Professors* Prof)
{
    cout << "Имя:";
    cin.get();
    cin.getline((*Prof).name, 20);
    cout << "Возраст:";
    cin >> Prof->age;
    cout << "Зарплата: ";
    cin >> Prof->salary;
    cout << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------

float GpaStudent(student* Stud, int m)
{
    float sum = 0;
    for(int i = 0; i < m; i++)
    {
        sum = sum + Stud[i].gpa;
    }
    return sum / m;
}

//----------------------------------------------------------------------------------------------------------------------------------

void MinGpa(student* Stud, int m)
{
    float min = Stud[0].gpa;
    int temp = 0;
    for(int i = 0; i < m; i++)
    {
        if(min > Stud[i].gpa)
        {
            min = Stud[i].gpa;
            temp = i;
        }
    }
    cout << "Студент с наименьшим средним балом балом: " << Stud[temp].name << " бал: " << min << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------

void MaxGpa(student* Stud, int m)
{
    float max = Stud[0].gpa;
    int temp = 0;
    for(int i = 0 ; i < m; i++)
    {
        
        if(max < Stud[i].gpa)
        {
            max = Stud[i].gpa;
            temp = i;
        }
    }
    cout << "Студент с наибольшим средним балом балом: " << Stud[temp].name << " бал:" << max << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------

bool PrintStudent(student* Stud, int m)
{
    for(int i = 0 ; i < m; i++)
    {
        cout << "Студент " << Stud[i].name << ", возраст " << Stud[i].age << "лет, средний бал " << Stud[i].gpa << endl;
    }
    return 1;
}

//----------------------------------------------------------------------------------------------------------------------------------

bool PrintProfessors(Professors* Prof, int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << "Профессор " << Prof[i].name << ", возраст " << Prof[i].age << "лет, зарплата " << Prof[i].salary << endl;
    }
    return 1;
}

//----------------------------------------------------------------------------------------------------------------------------------

bool ProfessorsOlder50(student* Stud, Professors* Prof, int m, int k)
{
    for(int i = 0; i < m; i++)
    {
        int nStudProf;
        cout << "Введите номер научного руководителя для студента " << Stud[i].name << ": ";
        cin >> nStudProf;
        if(0 < nStudProf &&  nStudProf < k + 1)
            Stud[i].supervisor = &Prof[nStudProf - 1];
        else
            cout << "Проффесор под № " << nStudProf << " не существует.";
    }
    cout << "Список студентов у которых научный руководитель старше 50 лет:" << endl;
    for(int i = 0; i < m; i++)
    {
        if(Stud[i].supervisor->age > 50)
            printf("Студент %s — научный руководитель: %s возраст научного руководителя %d \n", Stud[i].name, Stud[i].supervisor->name, Stud[i].supervisor->age);
    }
    return 1;
}

//----------------------------------------------------------------------------------------------------------------------------------
