#include <iostream>
#include <string.h>
using namespace std;

class Point
{
private:
    double x;
    double y;
    string name;
public:
    void setX(double xValue)
    {
        x = xValue;
    }
    void setY(double yValue)
    {
        y = yValue;
    }
    void setName(string nameValue)
    {
        name = nameValue;
    }
    void set(double xValue, double yValue, string nameValue)
    {
        x = xValue;
        y = yValue;
        name = nameValue;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    string getName()
    {
        return name;
    }
    void show(void);
};

void Point::show()
{
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Name = " << name << endl;
    cout << endl;
}


void main()
{
    Point stPoint, ndPoint;
    stPoint.setX(2.0);
    stPoint.setY(3.0);
    stPoint.setName("First Point"); 
    ndPoint.set(4.0, 5.0, "Second Point");
    stPoint.show();
    ndPoint.show();
    cout << "Get X of First Point = " << stPoint.getX() << endl;
    cout << "Get Y of First Point = " << stPoint.getY() << endl;
    cout << "Get Name = " << stPoint.getName() << endl;
    cout << "Get X of Second Point = " << ndPoint.getX() << endl;
    cout << "Get Y of Second Point = " << ndPoint.getY() << endl;
    cout << "Get Name = " << ndPoint.getName() << endl;
}