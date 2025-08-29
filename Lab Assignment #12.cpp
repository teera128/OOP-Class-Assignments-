#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <exception>

using namespace std;

class A
{
private:
    int a;
public:
    A()
    {
        a = 0;
    }

    A(int n)
    {
        a = n;
    }

    virtual ~A()
    {
        cout << "Deleted A" << endl;
    }

    int getA()
    {
        return a;
    }

    virtual void myThrow() throw(int, float, char, char*)
    {
        throw 777;
    }

    void funcA(int i)
    {
        cout << "Throwing from A" << endl;
        throw i;
    }
};

class B : public A
{
private:
    double b;
public:
    B()
    {
        b = 0.0;
    }

    B(double n)
    {
        b = n;
    }

    ~B()
    {
        cout << "Deleted B" << endl;
    }

    double getB()
    {
        return b;
    }

    void myThrow() throw(double)
    {
        throw 25.22;
    }

    void funcB(int i)
    {
        cout << "Throwing from B" << endl;
        funcA(i);
    }
};

class C : public B
{
private:
    char c;
public:
    C()
    {
        c = 'xxxx';
    }

    C(char n)
    {
        c = n;
    }

    ~C()
    {
        cout << "Deleted C" << endl;
    }

    char getC()
    {
        return c;
    }

    void myThrow() throw(char)
    {
        throw 'x';
    }

    void funcC(int i)
    {
        cout << "Throwing from C" << endl;
        funcB(i);
    }
};

class D : public C
{
private:
    char d[5];
public:
    D()
    {
        strcpy(d,"00000");
    }

    D(const char* n)
    {
        strcpy(d,n);
    }

    ~D()
    {
        cout << "Deleted D" << endl;
    }

    char* getD()
    {
        return d;
    }

    void myThrow() throw(char*)
    {
        throw "Throw from D";
    }

    void funcD(int i)
    {
        cout << "Throwing from D" << endl;
        funcC(i);
    }
};

class ExClass : public exception 
{
public:
    virtual const char* what() const throw() 
    {
        return "This Class is an exception";
    }
};

int main()
{
    cout << "Assignment # 12.1" << endl;
    A a(20);
    try
    {
        throw a.getA();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (float i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    cout << "Finished Test 1" << endl;
    cout << endl;

    B b(33.33);
    try
    {
        throw b.getB();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    cout << "Finished Test 2" << endl;
    cout << endl;

    C c('C');
    try
    {
        throw c.getC();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    cout << "Finished Test 3" << endl;
    cout << endl;

    cout << "****************************************************" << endl;
    cout << endl;

    cout << "Assignment # 12.2" << endl;
    const char* charD = "DDDDD";
    D d(charD);
    try
    {
        throw d.getD();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    catch (...)
    {
        cout << "Other Exception" << endl;
    }
    cout << "Finished Test 4" << endl;
    cout << endl;

    cout << "****************************************************" << endl;
    cout << endl;

    cout << "Assignment # 12.3" << endl;
    cout << "*****Throw b*****" << endl;
    try
    {
        throw b;
    }
    catch(B)
    {
        cout << "Catch class B" << endl;
    }
    catch (A)
    {
        cout << "Catch class A" << endl;
    }
    cout << endl;

    cout << "*****Throw b after reordered*****" << endl;
    try
    {
        throw b;
    }
    catch (A)
    {
        cout << "Catch class A" << endl;
    }
    catch (B)
    {
        cout << "Catch class B" << endl;
    }
    cout << endl;

    cout << "****************************************************" << endl;
    cout << endl;

    cout << "Assignment # 12.4" << endl;
    try
    {
        d.funcD(1);
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    catch (...)
    {
        cout << "Other Exception" << endl;
    }
    cout << "Finished Test 12.4" << endl;
    cout << endl;

    /*cout << "****************************************************" << endl;
    cout << endl;

    cout << "Assignment # 12.5" << endl;
    cout << "Throw from class A" << endl;
    try
    {
        a.myThrow();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    catch (...)
    {
        cout << "Other Exception" << endl;
    }
    cout << endl;

    cout << "Throw from class B" << endl;
    try
    {
        b.myThrow();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    catch (...)
    {
        cout << "Other Exception" << endl;
    }
    cout << endl;
    
    cout << "Throw from class C" << endl;
    try
    {
        c.myThrow();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    catch (...)
    {
        cout << "Other Exception" << endl;
    }
    cout << endl;

    cout << "Throw from class D" << endl;
    try
    {
        d.myThrow();
    }
    catch (int i)
    {
        cout << "Exception 1 : " << i << endl;
    }
    catch (double i)
    {
        cout << "Exception 2 : " << i << endl;
    }
    catch (char i)
    {
        cout << "Exception 3 : " << i << endl;
    }
    catch (...)
    {
        cout << "Other Exception" << endl;
    }
    cout << endl;

    cout << "****************************************************" << endl;
    cout << endl;*/

    cout << "Assignment # 12.6" << endl;
    try {
        throw ExClass();
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    cout << endl;
}