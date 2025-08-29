#include <iostream>
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
        set(1, j);
    }

    Rectangle(double w, double l)
    {
        num++;
        set(w, l);
    }

    ~Rectangle()
    {
        //cout << "Show Destructor" << endl;
        num--;
        //cout << num << endl;
        //cout << endl;
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
        double area = width * length;
        return area;
    }
    double calPerimeter()
    {
        double perimeter = 2 * (width + length);
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

    Rectangle operator ++()
    {
        ++length;
        return *this;
    }
    
    Rectangle operator ++(int)
    {
        Rectangle keep = *this;
        ++width;
        return keep;
    }

    friend Rectangle operator --(Rectangle& l)
    {
        if (l.length <= 1)
        {
            cout << "Length must be at least 1." << endl;
            cout << endl;
            return l;
        }
        else
        {
            l.length--;
            return l;
        }
    }

    friend Rectangle operator --(Rectangle& w, int)
    {
        if (w.width <= 1)
        {
            cout << "Width must be at least 1." << endl;
            cout << endl;
            return w;
        }
        else
        {
            Rectangle keep = w;
            w.width--;
            return keep;
        }
    }

    bool operator < (Rectangle a)
    {
        if (calArea() < a.calArea())
            return true;
        else
            return false;
    }

    bool operator <= (Rectangle a)
    {
        if (calArea() <= a.calArea())
            return true;
        else
            return false;
    }

    bool operator > (Rectangle a)
    {
        if (calArea() > a.calArea())
            return true;
        else
            return false;
    }

    bool operator >= (Rectangle a)
    {
        if (calArea() >= a.calArea())
            return true;
        else
            return false;
    }

    bool operator != (Rectangle a)
    {
        if (calArea() != a.calArea())
            return true;
        else
            return false;
    }

    int operator [] (int n)
    {
        switch (n)
        {
        case 1: return width;
        case 2: return length;
        case 3: return calArea();
        case 4: return calPerimeter();
        defualt: return 0;
        }
    }

    void operator ()(double w, double l)
    {
        width = w;
        length = l;

        if (width > length)
            cout << "This rectangle is vertical" << endl;
        else 
            cout << "This rectangle is horizontal" << endl;
    }

    double operator ()(int p)
    {
        return calArea()*p;
    }

    double operator ()()
    {
        return calArea()/2;
    }

    operator double()
    {
        return width * length;
    }
};

void Rectangle::show()
{
    cout << "Width = " << width << endl;
    cout << "Length = " << length << endl;
    cout << "Area = " << calArea() << endl;
    cout << "Perimeter = " << calPerimeter() << endl;
    cout << endl;
}

int Rectangle::num;

void main()
{
    {
        cout << "จำนวน Object = " << Rectangle::countObj() << endl; //if without any objects

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

    cout << "---Operator Overloading---" << endl;

    Rectangle rec1, rec2(1.0), rec3(3.0), rec4(3.0, 7.0), rec5(7.0, 3.0), rec6(0.2,0.3), rec7(9.0,9.0);

    cout << "---Test Unary Operation---" << endl;
    cout << "Show all of values before operating" << endl;
    cout << "Values of rec1" << endl;
    rec1.show();
    cout << "Values of rec2" << endl;
    rec2.show();

    rec1 = ++rec2;
    cout << "rec1 after operating ++length as a prefix" << endl;
    rec1.show();
    cout << "rec2 after operating ++length as a prefix" << endl;
    rec2.show();

    rec1 = rec2++;
    cout << "rec1 after operating ++width as a postfix" << endl;
    rec1.show();
    cout << "rec2 after operating ++width as a postfix" << endl;
    rec2.show();

    rec1 = --rec2;
    cout << "rec1 after operating --length as a prefix" << endl;
    rec1.show();
    cout << "rec2 after operating --length as a prefix" << endl;
    rec2.show();

    rec1 = rec2--;
    cout << "rec1 after operating --width as a postfix" << endl;
    rec1.show();
    cout << "rec2 after operating --width as a postfix" << endl;
    rec2.show();

    cout << "Test -- operation if values of rec6 are less than 1" << endl;
    --rec6;
    cout << "Values of rec6" << endl;
    rec6.show();

    cout << "Test -- operation if values of rec6 are less than 1" << endl;
    rec6--;
    cout << "Values of rec6" << endl;
    rec6.show();

    cout << "---Test Binary Operation---" << endl;
    cout << "Values of rec4" << endl;
    rec4.show();
    cout << "Values of rec5" << endl;
    rec5.show();
    cout << "Values of rec6" << endl;
    rec6.show();
    cout << "Values of rec7" << endl;
    rec7.show();

    cout << "---Test > Operator---" << endl;
    if (rec5 > rec7)
        cout << "The area of rec 5 is bigger than rec 7" << endl;
    else 
        cout << "The area of rec 7 is bigger than rec 5" << endl;

    cout << "---Test >= Operator---" << endl;
    if (rec4 >= rec5)
        cout << "The area of rec 4 is bigger than or equal rec 5" << endl;
    else
        cout << "The area of rec 5 is bigger than or equal rec 4" << endl;

    cout << "---Test < Operator---" << endl;
    if (rec5 < rec7)
        cout << "The area of rec 5 is smaller than rec 7" << endl;
    else
        cout << "The area of rec 7 is smaller than rec 5" << endl;

    cout << "---Test <= Operator---" << endl;
    if (rec6 <= rec5)
        cout << "The area of rec 6 is smaller than or equal rec 5" << endl;
    else
        cout << "The area of rec 5 is smaller than or equal rec 6" << endl;

    cout << "---Test != Operator---" << endl;
    if (rec4 != rec5)
        cout << "The area of rec 4 is not equal with rec 5" << endl;
    else
        cout << "The area of rec 4 is equal with rec 5" << endl;

    cout << endl;

    cout << "---[] Operator---" << endl;
    cout << "Width = " << rec3[1] << endl;
    cout << "Length = " << rec3[2] << endl;
    cout << "Area = " << rec3[3] << endl;
    cout << "Perimeter = " << rec3[4] << endl;
    cout << endl;

    cout << "---() Operator Overloading---" << endl;
    cout << "Rectangle Check" << endl;
    Rectangle recCheck1, recCheck2;
    recCheck1(9,3);
    cout << "Values of recCheck1" << endl;
    recCheck1.show();

    recCheck2(3,8);
    cout << "Values of recCheck2" << endl;
    recCheck2.show();

    cout << "Make the area triple as large" << endl;
    double tri = recCheck1(3);
    cout << "The triple area of recCheck1 = " << tri << endl;
    cout << endl;

    cout << "Divide the area into two parts" << endl;
    double divTwo = recCheck2();
    cout << "The area of recCheck2 after divided = " << divTwo << endl;
    cout << endl;

    cout << "---Cast Operator---" << endl;

    cout << "---Convert Rectangle to double---" << endl;
    Rectangle recCast1(2.7, 3.8), recCast2(5,5);
    double a, b;
    a = double(recCast1);
    cout << "Converting Rectangle to double as an area of recCast1 will be " << a << endl;
    b = recCast2;
    cout << "Converting Rectangle to double as an area of recCast2 will be " << b << endl;
    cout << endl;

    cout << "---Convert double to Rectangle---" << endl;
    Rectangle recCast3, recCast4;
    recCast3 = 5.0;
    cout << "Show recCast3" << endl;
    recCast3.show();

    recCast4 = 8.0;
    cout << "Show recCast4" << endl;
    recCast4.show();
}