#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
    int day;
    char* month;
    int year;
public:
    Date()
    {
        month = 0;
        setBDay(0, "Month", 0);
    }
    Date(int d, const char* m, int y)
    {
        month = 0;
        setBDay(d, m, y);
    }
    Date(const Date& cpy)
    {
        cout << "Copy Constructor" << endl;
        day = cpy.day;
        year = cpy.year;
        if (cpy.month != 0)
        {
            month = new char[strlen(cpy.month) + 1];
            strcpy(month, cpy.month);
        }
        else
            month = 0;
    }
    ~Date()
    {
        delete[] month;
        cout << "Delete Date" << endl;
        cout << endl;
    }
    void setBDay(int d, const char* m, int y)
    {
        day = d;
        year = y;
        delete[] month;
        month = new char[strlen(m) + 1];
        strcpy(month, m);
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(const char* m)
    {
        delete[] month;
        month = new char[strlen(m) + 1];
        strcpy(month, m);
    }
    void setYear(int y)
    {
        year = y;
    }
    int getDay()
    {
        return day;
    }
    char* getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    void showBDay()
    {
        cout << " Birthday :" << endl;
        cout << " Date = " << day << endl;
        cout << " Month = " << month << endl;
        cout << " Year = " << year << endl;
        cout << endl;
    }

    Date& operator = (const Date& d)
    {
        if (this == &d)
            return *this;
        day = d.day;
        year = d.year;
        delete[] month;
        if (d.month != 0)
        {
            month = new char[strlen(d.month) + 1];
            strcpy(month, d.month);
        }
        else
            month = 0;
        return *this;
    }

    void print(ostream& os)
    {
        os << " Birthday :" << endl;
        os << " Date = " << day << endl;
        os << " Month = " << month << endl;
        os << " Year = " << year << endl;
        cout << endl;
    }

    void input(istream& is)
    {
        char temp[10];
        cout << "Fill your birthday" << endl;
        cout << "Date ? " << endl;
        is >> day;
        cout << "Month ? " << endl;
        is >> temp;
        setMonth(temp);
        cout << "Year ? " << endl;
        is >> year;
        cout << endl;
    }
};

//*************************************************************

class Address
{
private:
    char houseNo[10];
    char district[20];
    char city[20];
    char* province;
    char post[7];
public:
    Address()
    {
        province = 0;
        setAdr("HouseNo", "District", "City", "Province", "Post");
    }
    Address(const char* house, const char* dis, const char* ci, const char* prov, const char* pos)
    {
        province = 0;
        setAdr(house, dis, ci, prov, pos);
    }
    Address(const Address& cpy)
    {
        cout << "Copy Constructor" << endl;
        strcpy(houseNo, cpy.houseNo);
        strcpy(district, cpy.district);
        strcpy(city, cpy.city);
        if (cpy.province != 0)
        {
            province = new char[strlen(cpy.province) + 1];
            strcpy(province, cpy.province);
        }
        else
            province = 0;
        strcpy(post, cpy.post);
    }
    ~Address()
    {
        delete[] province;
        cout << "Delete Address" << endl;
        cout << endl;
    }
    void setAdr(const char* house, const char* dis, const char* ci, const char* prov, const char* pos)
    {
        strcpy(houseNo, house);
        strcpy(district, dis);
        strcpy(city, ci);
        delete[] province;
        province = new char[strlen(prov) + 1];
        strcpy(province, prov);
        strcpy(post, pos);
    }
    void setHouseNo(const char* house)
    {
        strcpy(houseNo, house);
    }
    void setDistrict(const char* dis)
    {
        strcpy(district, dis);
    }
    void setCity(const char* ci)
    {
        strcpy(city, ci);
    }
    void setProvince(const char* prov)
    {
        delete[] province;
        province = new char[strlen(prov) + 1];
        strcpy(province, prov);
    }
    void setPost(const char* pos)
    {
        strcpy(post, pos);
    }
    char* getHouseNo()
    {
        return houseNo;
    }
    char* getDistrict()
    {
        return district;
    }
    char* getCity()
    {
        return city;
    }
    char* getProvince()
    {
        return province;
    }
    char* getPost()
    {
        return post;
    }
    void showAdr()
    {
        cout << "Address : " << houseNo << ", " << district << ", " << city << ", " << province << ", " << post << endl;
    }

    Address& operator = (const Address& a)
    {
        if (this == &a)
            return *this;
        strcpy(houseNo, a.houseNo);
        strcpy(district, a.district);
        strcpy(city, a.city);
        strcpy(post, a.post);
        delete[] province;
        if (a.province != 0)
        {
            province = new char[strlen(a.province) + 1];
            strcpy(province, a.province);
        }
        else
            province = 0;
        return *this;
    }

    void print(ostream& os)
    {
        os << "Address : " << houseNo << ", " << district << ", " << city << ", " << province << ", " << post << endl;
        cout << endl;
    }

    void input(istream& is)
    {
        char temp[20];
        cout << "Fill your address" << endl;
        cout << "House No. ? " << endl;
        is >> houseNo;
        cout << "District ? " << endl;
        is >> district;
        cout << "City ? " << endl;
        is >> city;
        cout << "Province ? " << endl;
        is >> temp;
        setProvince(temp);
        cout << "Post Code ? " << endl;
        is >> post;
        cout << endl;
    }
};

//*************************************************************

class Person
{
private:
    char* fname;
    char* lname;
    Date birthday;
    Address adr;
public:
    Person()
    {
        fname = 0;
        lname = 0;
        setName("First Name", "Last Name");
        birthday.setBDay(0, "Month", 0);
        adr.setAdr("HouseNo", "District", "City", "Province", "Post");
    }
    Person(const char* f, const char* l)
    {
        fname = 0;
        lname = 0;
        setName(f, l);
        birthday.setBDay(0, 0, 0);
        adr.setAdr("HouseNo", "District", "City", "Province", "Post");
    }
    Person(const char* f, const char* l, Date d, Address a)
    {
        fname = 0;
        lname = 0;
        setPerson(f, l, d, a);
    }
    virtual ~Person()
    {
        delete[] fname;
        delete[] lname;
        cout << "Delete Person" << endl;
        cout << endl;
    }
    Person(const Person& cpy)
    {
        cout << "Copy Constructor" << endl;
        birthday = cpy.birthday;
        adr = cpy.adr;
        if (cpy.fname && cpy.lname != 0)
        {
            fname = new char[strlen(cpy.fname) + 1];
            strcpy(fname, cpy.fname);
            lname = new char[strlen(cpy.lname) + 1];
            strcpy(lname, cpy.lname);
        }
        else
        {
            fname = 0;
            lname = 0;
        }
    }
    void setName(const char* f, const char* l)
    {
        delete[] fname;
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
        delete[] lname;
        lname = new char[strlen(l) + 1];
        strcpy(lname, l);
    }
    void setFname(const char* f)
    {
        delete[] fname;
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
    }
    void setLname(const char* l)
    {
        delete[] lname;
        lname = new char[strlen(l) + 1];
        strcpy(lname, l);
    }
    void setBirthday(Date bd)
    {
        birthday = bd;
    }
    void setAddress(Address ad)
    {
        adr = ad;
    }
    void setPerson(const char* f, const char* l, Date bd, Address ad)
    {
        delete[] fname;
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
        delete[] lname;
        lname = new char[strlen(l) + 1];
        strcpy(lname, l);
        birthday = bd;
        adr = ad;
    }
    char* getFname()
    {
        return fname;
    }
    char* getLname()
    {
        return lname;
    }
    Date getBirthday()
    {
        return birthday;
    }
    Address getAddress()
    {
        return adr;
    }
    void showPerson()
    {
        cout << "First Name: " << fname << endl;
        cout << "Last Name: " << lname << endl;
        cout << "Birthday: " << birthday.getDay() << "-" << birthday.getMonth() << "-" << birthday.getYear() << endl;
        cout << "Address: " << adr.getHouseNo() << ", " << adr.getDistrict() << ", " << adr.getCity() << ", " << adr.getProvince() << ", " << adr.getPost() << endl;
    }

    Person& operator = (const Person& p)
    {
        if (this == &p)
            return *this;
        birthday = p.birthday;
        adr = p.adr;
        delete[] fname;
        delete[] lname;
        if (p.fname && p.lname != 0)
        {
            fname = new char[strlen(p.fname) + 1];
            strcpy(fname, p.fname);
            lname = new char[strlen(p.lname) + 1];
            strcpy(lname, p.lname);
        }
        else
        {
            fname = 0;
            lname = 0;
        }
        return *this;
    }

    virtual void print(ostream& os)
    {
        os << "Personal Information : " << endl;
        os << "First Name: " << fname << endl;
        os << "Last Name: " << lname << endl;
        os << "Birthday: " << birthday.getDay() << "-" << birthday.getMonth() << "-" << birthday.getYear() << endl;
        os << "Address: " << adr.getHouseNo() << ", " << adr.getDistrict() << ", " << adr.getCity() << ", " << adr.getProvince() << ", " << adr.getPost() << endl;
        os << endl;
    }

    virtual void input(istream& is)
    {
        int d, y;
        char tempF[15], tempL[15];
        char m[10], house[10], dis[20], ci[20], prov[20], pos[10];
        cout << "Fill your personal information" << endl;
        cout << "First Name ? " << endl;
        is >> tempF;
        setFname(tempF);
        cout << "Last Name ? " << endl;
        is >> tempL;
        setLname(tempL);

        cout << "Date ? " << endl;
        is >> d;
        cout << "Month ? " << endl;
        is >> m;
        cout << "Year ? " << endl;
        is >> y;
        birthday.setBDay(d, m, y);

        cout << "House No. ? " << endl;
        is >> house;
        cout << "District ? " << endl;
        is >> dis;
        cout << "City ? " << endl;
        is >> ci;
        cout << "Province ? " << endl;
        is >> prov;
        cout << "Post Code ? " << endl;
        is >> pos;
        adr.setAdr(house, dis, ci, prov, pos);
        cout << endl;
    }
};
//****************************************************
class Student : virtual public Person
{
private:
    char* stuID;
public:
    Student()
    {
        stuID = 0;
        setID("0000000000");
    }
    Student(const char* f, const char* l, Date bd, Address ad, const char* id) : Person(f, l, bd, ad)
    {
        stuID = 0;
        setID(id);
    }
    ~Student()
    {
        delete[] stuID;
        cout << "Delete Student" << endl;
        cout << endl;
    }
    Student(const Student& cpy) : Person(cpy)
    {
        cout << "Copy Constructor" << endl;
        if (cpy.stuID != 0)
        {
            stuID = new char[strlen(cpy.stuID) + 1];
            strcpy(stuID, cpy.stuID);
        }
        else
        {
            stuID = 0;
        }
    }
    void setID(const char* id)
    {
        delete[] stuID;
        stuID = new char[strlen(id) + 1];
        strcpy(stuID, id);
    }
    char* getID()
    {
        return stuID;
    }
    void showStudent()
    {
        cout << "First Name: " << getFname() << endl;
        cout << "Last Name: " << getLname() << endl;
        cout << "Student ID: " << stuID << endl;
        getBirthday().showBDay();
        getAddress().showAdr();
    }

    Student& operator = (const Student& s)
    {
        if (this == &s)
            return *this;
        Person::operator=(s);
        delete[] stuID;
        if (s.stuID != 0)
        {
            stuID = new char[strlen(s.stuID) + 1];
            strcpy(stuID, s.stuID);
        }
        else
            stuID = 0;
        return *this;
    }

    void print(ostream& os)
    {
        Person::print(os);
        os << "Student ID : " << stuID << endl;
        os << endl;
    }

    void input(istream& is)
    {
        char temp[12];
        Person::input(is);
        cout << "Student ID ? " << endl;
        is >> temp;
        setID(temp);
        cout << endl;
    }
};

//*******************************************************
class Teacher : virtual public Person
{
private:
    char* department;
public:
    Teacher()
    {
        department = 0;
        setDep("Department");
    }
    Teacher(const char* f, const char* l, Date bd, Address ad, const char* dep) : Person(f, l, bd, ad)
    {
        department = 0;
        setDep(dep);
    }
    ~Teacher()
    {
        delete[] department;
        cout << "Delete Teacher" << endl;
        cout << endl;
    }
    Teacher(const Teacher& cpy) : Person(cpy)
    {
        cout << "Copy Constructor" << endl;
        if (cpy.department != 0)
        {
            department = new char[strlen(cpy.department) + 1];
            strcpy(department, cpy.department);
        }
        else
        {
            department = 0;
        }
    }
    void setDep(const char* dep)
    {
        delete[] department;
        department = new char[strlen(dep) + 1];
        strcpy(department, dep);
    }
    char* getDep()
    {
        return department;
    }
    void showTeacher()
    {
        cout << "First Name: " << getFname() << endl;
        cout << "Last Name: " << getLname() << endl;
        cout << "Department: " << department << endl;
        getBirthday().showBDay();
        getAddress().showAdr();
    }

    Teacher& operator = (const Teacher& s)
    {
        if (this == &s)
            return *this;
        Person::operator=(s);
        delete[] department;
        if (s.department != 0)
        {
            department = new char[strlen(s.department) + 1];
            strcpy(department, s.department);
        }
        else
            department = 0;
        return *this;
    }

    void print(ostream& os)
    {
        Person::print(os);
        os << "Department : " << department << endl;
        os << endl;
    }

    void input(istream& is)
    {
        char temp[20];
        Person::input(is);
        cout << "Department ? " << endl;
        is >> temp;
        setDep(temp);
        cout << endl;
    }
};

//******************************************************
class TeachingAssistant : public Student, public Teacher
{
private:
    char* subject;
public:
    TeachingAssistant()
    {
        subject = 0;
        setSubject("Subject");
    }
    TeachingAssistant(const char* f, const char* l, Date bd, Address ad, const char* id, const char* dep, const char* subj) : Person(f, l, bd, ad), Student(f, l, bd, ad, id), Teacher(f, l, bd, ad, dep)
    {
        subject = 0;
        setSubject(subj);
    }
    ~TeachingAssistant()
    {
        delete[] subject;
        cout << "Delete Teaching Assistant" << endl;
        cout << endl;
    }
    TeachingAssistant(const TeachingAssistant& cpy) : Person(cpy), Student(cpy), Teacher(cpy)
    {
        cout << "Copy Constructor" << endl;
        if (cpy.subject != 0)
        {
            subject = new char[strlen(cpy.subject) + 1];
            strcpy(subject, cpy.subject);
        }
        else
        {
            subject = 0;
        }
    }
    void setSubject(const char* subj)
    {
        delete[] subject;
        subject = new char[strlen(subj) + 1];
        strcpy(subject, subj);
    }
    char* getSubject()
    {
        return subject;
    }

    void showTA()
    {
        showPerson();
        cout << "Student ID: " << getID() << endl;
        cout << "Department: " << getDep() << endl;
        cout << "Subject: " << subject << endl;
    }

    TeachingAssistant& operator = (const TeachingAssistant& ta)
    {
        if (this == &ta)
            return *this;
        Student::operator=(ta);
        Teacher::setDep(ta.getDep());
        delete[] subject;
        if (ta.subject != 0)
        {
            subject = new char[strlen(ta.subject) + 1];
            strcpy(subject, ta.subject);
        }
        else
            subject = 0;
        return *this;
    }

    void print(ostream& os)
    {
        Person::print(os);
        os << "Student ID: " << getID() << endl;
        os << "Department: " << getDep() << endl;
        os << "Subject : " << subject << endl;
        os << endl;
    }

    void input(istream& is)
    {
        char id[12], dep[20], tempSubj[20];
        Person::input(is);
        cout << "Student ID ? " << endl;
        is >> id;
        setID(id);
        cout << "Department ? " << endl;
        is >> dep;
        setDep(dep);
        cout << "Subject ? " << endl;
        is >> tempSubj;
        setSubject(tempSubj);
        cout << endl;
    }
};

ostream& operator << (ostream& os, Date& out)
{
    out.print(os);
    return os;
}
istream& operator >> (istream& is, Date& in)
{
    in.input(is);
    return is;
}
//********************************************
ostream& operator << (ostream& os, Address& out)
{
    out.print(os);
    return os;
}
istream& operator >> (istream& is, Address& in)
{
    in.input(is);
    return is;
}
//********************************************
ostream& operator << (ostream& os, Person& out)
{
    out.print(os);
    return os;
}
istream& operator >> (istream& is, Person& in)
{
    in.input(is);
    return is;
}
//********************************************

int main()
{
    cout << "-----Test Class Date-----" << endl;
    Date dateTest1, dateTest2;
    cout << "-----Istream and Ostream Operator-----" << endl;
    cin >> dateTest1;
    cout << dateTest1;
    cout << "-----Assignment Operator-----" << endl;
    dateTest2 = dateTest1;
    cout << dateTest2;
    cout << "-----Copy Constructor-----" << endl;
    Date dateTest3 = dateTest1;
    cout << dateTest3;
    //***********************************************
    cout << "-----Test Class Address-----" << endl;
    Address adrTest1, adrTest2;
    cout << "-----Istream and Ostream Operator-----" << endl;
    cin >> adrTest1;
    cout << adrTest1;
    cout << "-----Assignment Operator-----" << endl;
    adrTest2 = adrTest1;
    cout << adrTest2;
    cout << "-----Copy Constructor-----" << endl;
    Address adrTest3 = adrTest1;
    cout << adrTest3;
    //***********************************************
    cout << "-----Test Class Person-----" << endl;
    Person psTest1, psTest2;
    cout << "-----Istream and Ostream Operator-----" << endl;
    cin >> psTest1;
    cout << psTest1;
    cout << "-----Assignment Operator-----" << endl;
    psTest2 = psTest1;
    cout << psTest2;
    cout << "-----Copy Constructor-----" << endl;
    Person psTest3(psTest1);
    cout << psTest3;
    //***********************************************
    cout << "-----Test Class Student-----" << endl;
    Student stuTest1, stuTest2;
    cout << "-----Istream and Ostream Operator-----" << endl;
    cin >> stuTest1;
    cout << stuTest1;
    cout << "-----Assignment Operator-----" << endl;
    stuTest2 = stuTest1;
    cout << stuTest2;
    cout << "-----Copy Constructor-----" << endl;
    Student stuTest3(stuTest1);
    cout << stuTest3;
    //***********************************************
    cout << "-----Test Class Teacher-----" << endl;
    Teacher teachTest1, teachTest2;
    cout << "-----Istream and Ostream Operator-----" << endl;
    cin >> teachTest1;
    cout << teachTest1;
    cout << "-----Assignment Operator-----" << endl;
    teachTest2 = teachTest1;
    cout << teachTest2;
    cout << "-----Copy Constructor-----" << endl;
    Teacher teachTest3(teachTest1);
    cout << teachTest3;
    //***********************************************
    cout << "-----Test Class Teaching Assistant-----" << endl;
    TeachingAssistant taTest1, taTest2;
    cout << "-----Istream and Ostream Operator-----" << endl;
    cin >> taTest1;
    cout << taTest1;
    cout << "-----Assignment Operator-----" << endl;
    taTest2 = taTest1;
    cout << taTest2;
    cout << "-----Copy Constructor-----" << endl;
    TeachingAssistant taTest3 = taTest1;
    cout << taTest3;

    return 0;
}