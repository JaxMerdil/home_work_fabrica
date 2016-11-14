#include "iostream"
#include "iomanip"
#include "math.h"
#include "ctime"
#include "stdio.h"

using namespace std;


//--Задание 4. Написать функцию, которая отвечает на вопрос, пересекаются ли две
//заданные окружности на плоскости.Каждая окружность задается координатами центра и радиусом.--//

float circle(float x1, float y1, float x2, float y2, float R1, float R2)
{
    float D = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    float sum = R1 + R2;
    float raz = fabs(R1 - R2);
    if ((D<=sum)||(D>=raz)) cout << "Circles intersect";
    else cout << "Circle do not intersect";
    return 0;
}

float main()
{
    //Задача 4
    float x1, x2, y1, y2, r1, r2;
    cout << "Enter the coordinates and the radius of the first circle:" << endl;
    cout << "x=";
    cin >> x1;
    cout << "y=";
    cin >> y1;
    cout << "R=";
    cin >> r1;
    cout << "Enter the coordinates and the radius of the second circle:" << endl;
    cout << "x=";
    cin >> x2;
    cout << "y=";
    cin >> y2;
    cout << "R=";
    cin >> r2;
    circle(x1, y1, x2, y2, r1, r2);
    cout<<endl;
    return 0;
}

