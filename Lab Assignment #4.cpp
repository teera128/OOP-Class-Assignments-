#include <iostream>
#include <string.h>
using namespace std;

class Point
{
private:
    static int num;
    double x;
    double y;
    string name;
public:
    Point()
    {
        num++;
        set(0.0, 0.0, "N");
    }

    Point(string i)
    {
        num++;
        set(0.0, 0.0, i);
    }

    Point(double i, double j)
    {
        num++;
        set(i, j, "N");
    }

    Point(double i, double j, string k)
    {
        num++;
        set(i, j, k);
    }

    ~Point()
    {
        cout << "Show Destructor" << endl;
        num--;
        cout << num << endl;
        cout << endl;
    }

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

    double dot(Point& d)
    {
        return (d.x * x) + (d.y * y);
    }

    /*Point midPoint(Point& m1, Point& m2)
    {
        x = (m1.x + m2.x) / 2;
        y = (m1.y + m2.y) / 2;
        return *this;
    }*/

    Point midPoint(Point& m1, Point& m2)
    {
        x = (m1.x + m2.x) / 2;
        y = (m1.y + m2.y) / 2;
        return Point(x,y);
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

    static int countObj()
    {
        return num;
    }
};

void Point::show()
{
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    cout << "Name = " << name << endl;
}

int Point::num;

void main()
{
    {cout << "จำนวน Object = " << Point::countObj() << endl; //if without any objects

    cout << "Start testing count object" << endl;

    Point testCon1;
    testCon1.show();
    cout << "จำนวน Object =  " << Point::countObj() << endl;
    cout << endl;

    Point testCon2("Test Constructor A");
    testCon2.show();
    cout << "จำนวน Object =  " << Point::countObj() << endl;
    cout << endl;

    Point testCon3(5.7, 4.2);
    testCon3.show();
    cout << "จำนวน Object =  " << Point::countObj() << endl;
    cout << endl;

    Point testCon4(2.3, 7.4, "Test Constructor B");
    testCon4.show();
    cout << "จำนวน Object =  " << Point::countObj() << endl;
    cout << endl;
    }

    Point stPoint;
    stPoint.setX(2.0);
    stPoint.setY(3.0);
    stPoint.setName("First Point");
    stPoint.show();
    cout << "จำนวน Object =  " << Point::countObj() << endl;
    cout << endl;

    Point ndPoint;
    ndPoint.set(4.0, 5.0, "Second Point");
    ndPoint.show();
    cout << "จำนวน Object =  " << Point::countObj() << endl;
    cout << endl;

    cout << "Get X of First Point = " << stPoint.getX() << endl;
    cout << "Get Y of First Point = " << stPoint.getY() << endl;
    cout << "Get Name = " << stPoint.getName() << endl;
    cout << "Dot Product = " << stPoint.dot(stPoint) << endl;
    cout << endl;

    cout << "Get X of Second Point = " << ndPoint.getX() << endl;
    cout << "Get Y of Second Point = " << ndPoint.getY() << endl;
    cout << "Get Name = " << ndPoint.getName() << endl;
    cout << "Dot Product = " << ndPoint.dot(ndPoint) << endl;
    cout << endl;

    Point midXnY, midVal;
    midVal = midXnY.midPoint(stPoint,ndPoint);
    cout << "Mid Point between First Point & Second Point = " << endl;
    midVal.show();
    midXnY.show();
}

