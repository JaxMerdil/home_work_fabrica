#include <iostream>

using namespace std;

//-----------------------------------------------------------
struct Professor;
struct Student
{
    char name[20]; //имя
    unsigned short age; //возраст
    float gpa; //ср.бал
    Professor* supervisor;//научный руководитель
};

struct Professor
{
    char name[20]; //имя
    unsigned short age; //возраст
    unsigned int salary; //зарплата
};

//********************Шаблоны**********************//
template<typename T>
T MinOrMax(T (*pFunc)(const T&, const T&), T* arr, size_t size)
{
    T value=arr[0];
    for(size_t i = 0; i < size; i++)
    {
        value = pFunc(value, arr[i]);
    }

    return value;
}

//-----------------------------------------------------------

template<typename T>
T min(const T& value1, const T& value2)
{
    return value1 > value2 ? value2 : value1;
}

template<>
Student min(const Student& value1, const Student& value2)
{
    return value1.gpa > value2.gpa ? value2 : value1;
}
//-----------------------------------------------------------

template<typename T>
T max(const T& value1, const T& value2)
{
    return value1 < value2 ? value2 : value1;
}
template<>
Student max(const Student& value1, const Student& value2)
{
    return value1.gpa < value2.gpa ? value2 : value1;
}

//----------------------------------------------------------------------------------------------------------------------------------

//***************Функции****************//
void InputStudent(Student* Stud)
{
    cout << "Имя:";
    cin.get();
    cin.getline(Stud->name, 20);
    cout << "Возраст:";
    cin>>Stud->age;
    cout << "Средний бал: ";
    cin >> Stud->gpa;
    cout << endl;
}

//-------------------------------------------------------------

void InputProfessors(Professor* Prof)
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

//-------------------------------------------------------------

float GpaStudent(Student* Stud, int m)
{
    float sum = 0;
    for(int i = 0; i < m; i++)
    {
        sum = sum + Stud[i].gpa;
    }
    return sum / m;
}

//----------------------------------------------------------------
void PrintStudent(Student* Stud, int m)
{
    for(int i = 0 ; i < m; i++)
    {
        cout << "Студент " << Stud[i].name << ", возраст " << Stud[i].age << "лет, средний бал " << Stud[i].gpa << endl;
    }
}

//-------------------------------------------------------------

void PrintProfessors(Professor* Prof, int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << "Профессор " << Prof[i].name << ", возраст " << Prof[i].age << "лет, зарплата " << Prof[i].salary << endl;
    }
}

//-------------------------------------------------------------

void ProfessorsOlder50(Student* Stud, Professor* Prof, int m, int k)
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
}

//-------------------------------------------------------------
int main(int argc, char *argv[])
{
    int nStud=0;
       cout << "Введите количество студентов: ";
       cin >> nStud;
       Student groupStud[nStud];
       for(int i = 0; i < nStud; i++)
       {
           cout << i + 1 << "-й студент: ";
           InputStudent(&groupStud[i]);
       }
       PrintStudent(groupStud, nStud);
       cout << endl;
       cout << "Средний бал: " << GpaStudent(groupStud, nStud) << endl;
       cout << endl;
       Student minInt = MinOrMax(min, groupStud, nStud);
       Student maxInt = MinOrMax(max, groupStud, nStud);
       cout << "Минимальный бал среди студентов: " << minInt.gpa << endl;
       cout << "Максимальный бал среди студентов: " << maxInt.gpa << endl;
       int nProf = 0;
       cout << "Введите количество профессоров: ";
       cin >> nProf;
       Professor groupProf[nProf];
       for(int i = 0; i < nProf; i++)
       {
           cout << i + 1 << "-й профессор: ";
           InputProfessors(&groupProf[i]);
       }
       PrintProfessors(groupProf, nProf);
       ProfessorsOlder50(groupStud, groupProf, nStud, nProf);
       return 0;
}
