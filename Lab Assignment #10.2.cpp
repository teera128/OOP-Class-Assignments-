#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class Shape
{
public:
	Shape()
	{
		cout << "Shape Constructor" << endl;
        cout << endl;
	}
	virtual ~Shape()
	{
		cout << "Delete Shape" << endl;
        cout << endl;

	}
    virtual double area() = 0;
	virtual void print(ostream& os) = 0;
	virtual void input(istream& is) = 0;
};

class TwoDimensional : public Shape
{
public:
	TwoDimensional()
    {
	    cout << "TwoDimensional Constructor" << endl;
        cout << endl;

    }
	~TwoDimensional()
    {
	    cout << "Delete TwoDimensional" << endl;
        cout << endl;
    }
	double area() = 0 ;
	void print(ostream& os) = 0;
	void input(istream& is) = 0;
};

class ThreeDimensional : public Shape
{
public:
	ThreeDimensional()
	{
		cout << "ThreeDimensional Constructor" << endl;
        cout << endl;
	}
	~ThreeDimensional()
	{
		cout << "Delete ThreeDimensional" << endl;
        cout << endl;
	}
	virtual double volume() = 0;
    double area() = 0;
	void print(ostream& os) = 0;
	void input(istream& is) = 0;
};

class Rectangle : public TwoDimensional
{
private:
    double width;
    double length;
public:
    Rectangle()
    {
        cout << "Rectangle Constructor" << endl;
        cout << endl;
        set(0.0, 0.0);
    }

    Rectangle(double w, double l)
    {
        cout << "Rectangle Constructor" << endl;
        cout << endl;
        set(w, l);
    }

    ~Rectangle()
    {
        cout << "Delete Rectangle" << endl;
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

    double area()
    {
        double area = width * length;
        return area;
    }

    double getWidth()
    {
        return width;
    }

    double getLength()
    {
        return length;
    }

    void print(ostream& os)
    {
        os << "Rectangle Details" << endl;
        os << "Width = " << width << endl;
        os << "Length = " << length << endl;
        os << "Area = " << area() << endl;
        os << endl;
    }

    void input(istream& is)
    {
        cout << "Create Rectangle" << endl;
        cout << "Width ? " << endl;
        is >> width;
        cout << "Length ? " << endl;
        is >> length;
        cout << endl;
    }
};

class Triangle : public TwoDimensional
{
private:
    double height;
    double base;
public:
    Triangle()
    {
        cout << "Triangle Constructor" << endl;
        cout << endl;
        set(0.0, 0.0);
    }

    Triangle(double h, double b)
    {
        cout << "Triangle Constructor" << endl;
        cout << endl;
        set(h, b);
    }

    ~Triangle()
    {
        cout << "Delete Triangle" << endl;
        cout << endl;
    }

    void setHeight(double h)
    {
        height = h;
    }

    void setBase(double b)
    {
        base = b;
    }

    void set(double h, double b)
    {
        height = h;
        base = b;
    }

    double area()
    {
        double area = 0.5 * height * base;
        return area;
    }

    double getHeight()
    {
        return height;
    }

    double getBase()
    {
        return base;
    }

    void print(ostream& os)
    {
        os << "Triangle Details" << endl;
        os << "Height = " << height << endl;
        os << "Base = " << base << endl;
        os << "Area = " << area() << endl;
        os << endl;
    }

    void input(istream& is)
    {
        cout << "Create Triangle" << endl;
        cout << "Height ? " << endl;
        is >> height;
        cout << "Base ? " << endl;
        is >> base;
        cout << endl;
    }
};

class Circle : public TwoDimensional
{
private:
    double radius;
public:
    Circle()
    {
        cout << "Circle Constructor" << endl;
        cout << endl;
        set(0.0);
    }

    Circle(double r)
    {
        cout << "Circle Constructor" << endl;
        cout << endl;
        set(r);
    }

    ~Circle()
    {
        cout << "Delete Circle" << endl;
        cout << endl;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    void set(double r)
    {
        radius = r;
    }

    double area()
    {
        double area = 3.14 * radius * radius;
        return area;
    }

    double getRadius()
    {
        return radius;
    }

    void print(ostream& os)
    {
        os << "Circle Details" << endl;
        os << "Radius = " << radius << endl;
        os << "Area = " << area() << endl;
        os << endl;
    }

    void input(istream& is)
    {
        cout << "Create Circle" << endl;
        cout << "Radius ? " << endl;
        is >> radius;
        cout << endl;
    }
};

class Cylinder : public ThreeDimensional
{
private:
    double height;
    double radius;
public:
    Cylinder()
    {
        cout << "Cylinder Constructor" << endl;
        cout << endl;
        set(0.0, 0.0);
    }

    Cylinder(double h, double r)
    {
        cout << "Cylinder Constructor" << endl;
        cout << endl;
        set(h, r);
    }

    ~Cylinder()
    {
        cout << "Delete Cylinder" << endl;
        cout << endl;
    }

    void setHeight(double h)
    {
        height = h;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    void set(double h, double r)
    {
        height = h;
        radius = r;
    }

    double area()
    {
        double area = (2 * 3.14 * radius * radius) + (2 * 3.14 * radius * height);
        return area;
    }

    double volume()
    {
        double vol = 3.14 * radius * radius * height;
        return vol;
    }

    double getHeight()
    {
        return height;
    }

    double getRadius()
    {
        return radius;
    }

    void print(ostream& os)
    {
        os << "Cylinder Details" << endl;
        os << "Height = " << height << endl;
        os << "Radius = " << radius << endl;
        os << "Area = " << area() << endl;
        os << "Volume = " << volume() << endl;
        os << endl;
    }

    void input(istream& is)
    {
        cout << "Create Cylinder" << endl;
        cout << "Height ? " << endl;
        is >> height;
        cout << "Radius ? " << endl;
        is >> radius;
        cout << endl;
    }
};

class Sphere : public ThreeDimensional
{
private:
    double radius;
public:
    Sphere()
    {
        cout << "Sphere Constructor" << endl;
        cout << endl;
        set(0.0);
    }

    Sphere(double r)
    {
        cout << "Sphere Constructor" << endl;
        cout << endl;
        set(r);
    }

    ~Sphere()
    {
        cout << "Delete Sphere" << endl;
        cout << endl;
    }

    void setRadius(double r)
    {
        radius = r;
    }

    void set(double r)
    {
        radius = r;
    }

    double area()
    {
        double area = 4 * 3.14 * radius * radius;
        return area;
    }

    double volume()
    {
        double vol = 1.33 * 3.14 * radius * radius * radius;
        return vol;
    }

    double getRadius()
    {
        return radius;
    }

    void print(ostream& os)
    {
        os << "Sphere Details" << endl;
        os << "Radius = " << radius << endl;
        os << "Area = " << area() << endl;
        os << "Volume = " << volume() << endl;
        os << endl;
    }

    void input(istream& is)
    {
        cout << "Create Sphere" << endl;
        cout << "Radius ? " << endl;
        is >> radius;
        cout << endl;
    }
};

ostream& operator << (ostream& os, Shape &out)
{
    out.print(os);
    return os;
}
istream& operator >> (istream& is, Shape &in)
{
    in.input(is);
    return is;
}

ostream& operator << (ostream& os, TwoDimensional &out)
{
    out.print(os);
    return os;
}
istream& operator >> (istream& is, TwoDimensional &in)
{
    in.input(is);
    return is;
}

ostream& operator << (ostream& os, ThreeDimensional &out)
{
    out.print(os);
    return os;
}
istream& operator >> (istream& is, ThreeDimensional &in)
{
    in.input(is);
    return is;
}


int main()
{
    cout << "-----Test Class Rectangle-----" << endl;
    Rectangle rec;
    cin >> rec;
    cout << "Area = " << rec.area() << endl;
    cout << rec;

    cout << "-----Test Class Triangle-----" << endl;
    Triangle tri;
    cin >> tri;
    cout << "Area = " << tri.area() << endl;
    cout << tri;

    cout << "-----Test Class Circle-----" << endl;
    Circle cir;
    cin >> cir;
    cout << "Area = " << cir.area() << endl;
    cout << cir;

    cout << "-----Test Class Cylinder-----" << endl;
    Cylinder cyl;
    cin >> cyl;
    cout << "Area = " << cyl.area() << endl;
    cout << "Volume = " << cyl.volume() << endl;
    cout << cyl;

    cout << "-----Test Class Sphere-----" << endl;
    Sphere sph;
    cin >> sph;
    cout << "Area = " << sph.area() << endl;
    cout << "Volume = " << sph.volume() << endl;
    cout << sph;

    cout << "-----Test Class TwoDimensional-----" << endl;
    TwoDimensional *twoD[3];
    twoD[0] = new Rectangle;
    twoD[1] = new Triangle;
    twoD[2] = new Circle;

    for (int i = 0; i < 3; i++)
    {
        cin >> *twoD[i];
        cout << "Area = " << twoD[i] -> area() << endl;
        cout << endl;
        cout << *twoD[i];
    }

    for (int i = 0; i < 3; i++)
    {
        delete twoD[i];
    }

    cout << "-----Test Class ThreeDimensional-----" << endl;
    ThreeDimensional* threeD[2];
    Cylinder a;
    Sphere b;
    threeD[0] = &a; 
    threeD[1] = &b;

    for (int i = 0; i < 2; i++)
    {
        cin >> *threeD[i];
        cout << "Area = " << threeD[i] -> area() << endl;
        cout << "Volume = " << threeD[i] -> volume() << endl;
        cout << endl;
        cout << *threeD[i];
    }

    return 0;
}