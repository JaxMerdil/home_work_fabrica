#include <iostream>
#include <cmath>


using namespace std;

//---------------------------------------------------------------------------------
class Shape
{
private:
    float m_x;
    float m_y;
public:
    Shape() //Конструктор по умолчанию
    {
        m_x=m_y=0;
        cout<<"Вызов конструктора по умолчанию базового класса"<<endl;
    }
    Shape(float x, float y) // Конструктор класса с параметрами
    {
        m_x=x;
        m_y=y;
        cout<<"Вызов параметризированого конструктора базового класса"<<endl;
    }
    ~Shape() // Деструктор
    {
        cout << "Вызов деструктора Shape" << endl;
    }
//    Функции доступа может когда то понадобятся
//    float get_x()
//    {
//        return m_x;
//    }
//    float get_y()
//    {
//        return m_y;
//    }
//    void set_x(float x)
//    {
//        m_x=x;
//    }
//    void set_y(float y)
//    {
//        m_y=y;
//    }
    virtual float Square()=0; // Ф-я выч. площади фигуры
};

//---------------------------------------------------------------------------------

class Rectangle: public Shape
{
private:
    float m_width;
    float m_height;
public:
    Rectangle(float w, float h)
    {
        m_width = w;
        m_height = h;
        cout<<"Вызов параметризированого конструктора класса Rectangle"<<endl;
    }
    ~Rectangle() // Деструктор
    {
        cout << "Вызов деструктора Rectangle" << endl;
    }
    float Square()
    {
        return m_width*m_height;
    }
};

//---------------------------------------------------------------------------------

class Triangle: public Shape
{
private:
    float m_cathetusA;
    float m_cathetusB;
public:
    Triangle(float cA, float cB)
    {
        m_cathetusA = cA;
        m_cathetusB = cB;
        cout<<"Вызов параметризированого конструктора класса Triangle"<<endl;
    }
    ~Triangle() // Деструктор
    {
        cout << "Вызов деструктора Triangle" << endl;
    }
    float Square()
    {
        return 0.5*m_cathetusA*m_cathetusB;
    }
};

//---------------------------------------------------------------------------------

class Circle: public Shape
{
private:
    float m_radius;
public:
    Circle(float r)
    {
        m_radius=r;
        cout<<"Вызов параметризированого конструктора класса Circle"<<endl;
    }
    ~Circle() // Деструктор
    {
        cout << "Вызов деструктора Rectangle" << endl;
    }
    float Square()
    {
        return M_PI*m_radius*m_radius;
    }
};

//---------------------------------------------------------------------------------

void PrintSquerOfShape(Shape** sF, const int size)
{
    float sum=0;
    for(int i = 0; i < size; ++i)
    {
        sum += sF[i]->Square();
    }
    cout << "Сумма площадей фигур: " << sum << endl;
}

//---------------------------------------------------------------------------------

int main()
{
    const int nFigure=3;
    Shape* squareFigures[nFigure];
    squareFigures[0] = new Rectangle(10, 10);
    cout << "S Rectangle: " << squareFigures[0]->Square() << endl;
    squareFigures[1] = new Triangle(10, 15);
    cout << "S Triangle: " << squareFigures[1]->Square() << endl;
    squareFigures[2] = new Circle(10);
    cout << "S Circle: " << squareFigures[2]->Square() << endl;
    PrintSquerOfShape(squareFigures,nFigure);
    return 0;
}


