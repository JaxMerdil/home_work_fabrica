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
    Shape()  :m_x(0),m_y(0)      //Конструктор по умолчанию
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Shape(float x, float y) :m_x(x),m_y(y)// Конструктор класса с параметрами
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual ~Shape() // Деструктор
    {
        cout << __PRETTY_FUNCTION__ << endl;
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
    Rectangle(int x, int y, float w, float h) : Shape(x, y), m_width(w), m_height(h)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Rectangle() // Деструктор
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    float Square() override
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
    Triangle(int x, int y, float cA, float cB) : Shape(x, y), m_cathetusA(cA), m_cathetusB(cB)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Triangle() // Деструктор
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    float Square() override
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
   Circle(int x, int y, int r) : Shape(x, y), m_radius(r)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Circle() // Деструктор
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    float Square() override
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
    squareFigures[0] = new Rectangle(5, 5, 10, 10);
    cout << "S Rectangle: " << squareFigures[0]->Square() << endl;
    squareFigures[1] = new Triangle(5, 5, 10, 15);
    cout << "S Triangle: " << squareFigures[1]->Square() << endl;
    squareFigures[2] = new Circle(5, 5, 10);
    cout << "S Circle: " << squareFigures[2]->Square() << endl;
    PrintSquerOfShape(squareFigures,nFigure);
    return 0;
}
