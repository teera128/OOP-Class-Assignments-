#include <iostream>
#include <cmath>
using namespace std;

class Circle;
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
        num--;
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
        return Point(x, y);
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

    friend bool checkPoint(Point, Circle);

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

class Circle
{
private:
    static int numC;
    double radius;
    Point centerP;

public:
    Circle()
    {
        numC++;
        radius = 0.0;
        centerP.set(0.0,0.0,"N");
    }

    Circle(double r)
    {
        numC++;
        setRadius(r);
        centerP.set(0.0, 0.0, "N");
    }

    Circle(Point cP)
    {
        numC++;
        setRadius(0.0);
        setCenterP(cP);
    }

    Circle(double r, Point cP)
    {
        numC++;
        setRnCP(r,cP);
    }

    ~Circle()
    {
        numC--;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    void setCenterP(Point cP)
    {
        centerP = cP;
    }

    void setRnCP(double r, Point cP)
    {
        radius = r;
        centerP = cP;
    }

    double getRadius()
    {
        return radius;
    }
    
    Point getCenterP()
    {
        return centerP;
    }
    void showCircle(void);

    //friend bool checkPoint(Point, Circle);

    static int countObjCir()
    {
        return numC;
    }

};

void Circle::showCircle()
{
    cout << "Radius = " << radius << endl;
    cout << "Center Point of X = " << centerP.getX() << endl;
    cout << "Center Point of Y = " << centerP.getY() << endl;
}

int Circle::numC;

bool checkPoint(Point chkP, Circle chkC)
{
    double distanceX = pow((chkP.x - chkC.getCenterP().x), 2);
    double distanceY = pow((chkP.y - chkC.getCenterP().y), 2);
    if ((distanceX + distanceY) <= pow(chkC.getRadius(), 2))
        return true;
    else
        return false;
}

void main()
{
    Point centerPoint(4.0,8.0);
    Circle stCircle;
    stCircle.setRadius(5.0);
    stCircle.setCenterP(centerPoint);
    stCircle.showCircle();
    cout << endl;

    cout << "Get Radius of This Circle = " << stCircle.getRadius() << endl;
    cout << "Get Center Point of This Circle X = " << stCircle.getCenterP().getX() << " Y = " << stCircle.getCenterP().getY() << endl;
    ;
    cout << endl;

    bool check1, check2;

    Point inPoint;
    inPoint.set(3.0, 5.0, "Test Point1");
    inPoint.show();
    cout << endl;
    check1 = checkPoint(inPoint, stCircle);
    if (check1 == true)
    {
        cout << "This point is an internal point of this circle." << endl;
        cout << endl;
    }
    else
    {
        cout << "This point is an external point of this circle." << endl;
        cout << endl;
    }

    cout << "----------------------" << endl;


    Point exPoint;
    exPoint.set(12.0, 15.0, "Test Point2");
    exPoint.show();
    cout << endl;
    check2 = checkPoint(exPoint, stCircle);
    if (check2 == true)
    {
        cout << "This point is an internal point of this circle." << endl;
        cout << endl;
    }
    else
    {
        cout << "This point is an external point of this circle." << endl;
        cout << endl;
    }
}
