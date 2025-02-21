#include <iostream>
#include <string.h>
using namespace std;

class Rectangle
{
private:
    static int num;
    double width;
    double length;
public:
    Rectangle()
    {
        num++;
        set(0.0, 0.0);
    }

    Rectangle(double j)
    {
        num++;
        set(j, j);
    }

    Rectangle(double w, double l)
    {
        num++;
        set(w, l);
    }

    ~Rectangle()
    {
        cout << "Show Destructor" << endl;
        num--;
        cout << num << endl;
        cout << endl;
    }

    void setWidth(double w)
    {
        width = w;
    }

    void setLength(double l)
    {
        length = l;
    }

    void set(double w, double l)
    {
        width = w;
        length = l;
    }

    double calArea()
    {
        double area = width*length;
        return area;
    }
    double calPerimeter()
    {
        double perimeter = 2*(width + length);
        return perimeter;
    }

    double getWidth()
    {
        return width;
    }
    double getLength()
    {
        return length;
    }

    void show(void);

    static int countObj()
    {
        return num;
    }
};

void Rectangle::show()
{
    cout << "Width = " << width << endl;
    cout << "Length = " << length << endl;
    cout << "Area = " << calArea() << endl;
    cout << "Perimeter = " << calPerimeter() << endl;
}

int Rectangle::num;

void main()
{
    {cout << "จำนวน Object = " << Rectangle::countObj() << endl; //if without any objects

    cout << "Start testing count object" << endl;

    Rectangle testCon1;
    testCon1.calArea();
    testCon1.calPerimeter();
    testCon1.show();
    cout << "จำนวน Object =  " << Rectangle::countObj() << endl;
    cout << endl;

    Rectangle testCon2(5.0);
    testCon2.calArea();
    testCon2.calPerimeter();
    testCon2.show();
    cout << "จำนวน Object =  " << Rectangle::countObj() << endl;
    cout << endl;

    Rectangle testCon3(3.0, 7.0);
    testCon3.calArea();
    testCon3.calPerimeter();
    testCon3.show();
    cout << "จำนวน Object =  " << Rectangle::countObj() << endl;
    cout << endl;
    }

    Rectangle stRec;
    stRec.setWidth(4.0);
    stRec.setLength(5.0);
    stRec.calArea();
    stRec.calPerimeter();
    stRec.show();
    cout << "จำนวน Object =  " << Rectangle::countObj() << endl;
    cout << endl;

    Rectangle ndRec;
    ndRec.set(7.0, 9.0);
    ndRec.calArea();
    ndRec.calPerimeter();
    ndRec.show();
    cout << "จำนวน Object =  " << Rectangle::countObj() << endl;
    cout << endl;

    cout << "Get Width of First Rectangle = " << stRec.getWidth() << endl;
    cout << "Get Length of First Rectangle = " << stRec.getLength() << endl;
    cout << "Area of First Rectangle = " << stRec.calArea() << endl;
    cout << "Perimeter of First Rectangle = " << stRec.calPerimeter() << endl;
    cout << endl;

    cout << "Get Width of Second Rectangle = " << ndRec.getWidth() << endl;
    cout << "Get Length of Second Rectangle = " << ndRec.getLength() << endl;
    cout << "Get Area of Second Rectangle = " << ndRec.calArea() << endl;
    cout << "Get Perimeter of Second Rectangle = " << ndRec.calPerimeter() << endl;
    cout << endl;
}