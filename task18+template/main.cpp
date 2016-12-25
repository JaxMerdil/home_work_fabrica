#include <iostream>
#include <template.h>

using namespace std;

int main( )

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

