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

    void setRectObj(Rectangle recObj)
    {
        width = recObj.getWidth();
        length = recObj.getLength();
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
};

void Rectangle::show()
{
    cout << "Width = " << width << endl;
    cout << "Length = " << length << endl;
    cout << "Area = " << calArea() << endl;
    cout << "Perimeter = " << calPerimeter() << endl;
}

int Rectangle::num;

class MyRect
{
    int row, col;
    Rectangle** rec;
public:
    MyRect()
    {
        row = 0; 
        col = 0;
        rec = 0;
    }

    MyRect(int r, int c)
    {
        row = r;
        col = c;
        rec = new Rectangle * [row];
        for (int i = 0; i < row; i++)
            rec[i] = new Rectangle[col];
    }

    ~MyRect()
    {
        if (rec != 0)
        {
            for (int i = 0; i < row; i++)
                delete[] rec[i];
            delete[] rec;
        }
    }

    void fillRect()
    {
        double fillW, fillL;
        for (int i =0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cout << "Input Rectangle[" << i << "][" << j << "]" << endl;
                cout << "Width = ";
                cin >> fillW;
                cout << "Length = ";
                cin >> fillL;
                setRect(i,j,fillW,fillL);
            }
        cout << endl;
    }

    void setRect(int ro, int co, double wi, double le)
    {
            rec[ro][co].set(wi, le);
    }

    void setRect(Rectangle exRec, int ro, int co) {
        rec[ro][co]=exRec;
    }

    void reset(int ro, int co)
    {
        if (rec != 0)
        {
            for (int i = 0; i < row; i++)
                delete[] rec[i];
            delete[] rec;
        }

        row = ro;
        col = co;
        rec = new Rectangle * [row];
        for (int i = 0; i < row; i++)
            rec[i] = new Rectangle[col];
    }

    Rectangle getRect(int ro, int co)
    {
        return rec[ro][co];
    }

    void showMyRect()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Width of Rectangle[" << i << "][" << j << "] = " << rec[i][j].getWidth() << endl;
                cout << "Length of Rectangle[" << i << "][" << j << "] = " << rec[i][j].getLength() << endl;
                cout << "Area of Rectangle[" << i << "][" << j << "] = " << rec[i][j].calArea() << endl;
                cout << "Perimeter of Rectangle[" << i << "][" << j << "] = " << rec[i][j].calPerimeter() << endl;
                cout << endl;
            }

        }
    }
};

int main()
{
    MyRect rec1;
    cout << "-----First Set of My Rectangles-----" << endl;
    rec1.fillRect();
    rec1.showMyRect();

    rec1.reset(2, 2);
    rec1.fillRect();
    rec1.showMyRect();

    Rectangle infoRec1;
    infoRec1 = rec1.getRect(0, 0);
    infoRec1.show();
    cout << endl;

    infoRec1 = rec1.getRect(0, 1);
    infoRec1.show();
    cout << endl;

    infoRec1 = rec1.getRect(1, 0);
    infoRec1.show();
    cout << endl;

    infoRec1 = rec1.getRect(1, 1);
    infoRec1.show();
    cout << endl;

    MyRect rec2;
    cout << "-----Second Set of My Rectangles-----" << endl;
    rec2.fillRect();
    rec2.showMyRect();

    rec2.reset(2, 2);
    rec2.fillRect();
    rec2.showMyRect();

    Rectangle infoRec2(2,3);
 
    rec2.setRect(infoRec2, 1, 1);
    rec2.showMyRect();

    infoRec2 = rec2.getRect(0, 0);
    infoRec2.show();
    cout << endl;

    infoRec2 = rec2.getRect(0, 1);
    infoRec2.show();
    cout << endl;

    infoRec2 = rec2.getRect(1, 0);
    infoRec2.show();
    cout << endl;

    infoRec2 = rec2.getRect(1, 1);
    infoRec2.show();
    cout << endl;

    MyRect rec3(2,2);
    cout << "-----Third Set of My Rectangles-----" << endl;
    rec2.fillRect();
    rec2.showMyRect();

    Rectangle infoRec3;
    rec3.setRect(1, 1, 2.0, 6.0);
    rec3.showMyRect();

    infoRec3 = rec3.getRect(0, 0);
    infoRec3.show();
    cout << endl;

    infoRec3 = rec3.getRect(0, 1);
    infoRec3.show();
    cout << endl;

    infoRec3 = rec3.getRect(1, 0);
    infoRec3.show();
    cout << endl;

    infoRec3 = rec3.getRect(1, 1);
    infoRec3.show();
    cout << endl;

}