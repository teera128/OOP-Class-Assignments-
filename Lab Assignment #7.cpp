#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date()
    {
        setBDay(0, 0, 0);
    }
    Date(int d, int m, int y)
    {
        setBDay(d, m, y);
    }
    ~Date()
    {
    }
    void setBDay(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        year = y;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
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
    }
};

//*************************************************************

class Address
{
private:
    char houseNo[10];
    char district[20];
    char city[20];
    char province[20];
    char post[7];
public:
    Address()
    {
        setAdr("HouseNo", "District", "City", "Province", "Post");
    }
    Address(const char* house, const char* dis, const char* ci, const char* prov, const char* pos)
    {
        setAdr(house, dis, ci, prov, pos);
    }
    ~Address()
    {
    }
    void setAdr(const char* house, const char* dis, const char* ci, const char* prov, const char* pos)
    {
        strcpy(houseNo, house);
        strcpy(district, dis);
        strcpy(city, ci);
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
        strcpy(province, prov);
    }
    void setPost(const char* pos)
    {
        strcpy(post, pos);
    }
    const char* getHouseNo()
    {
        return houseNo;
    }
    const char* getDistrict()
    {
        return district;
    }
    const char* getCity()
    {
        return city;
    }
    const char* getProvince()
    {
        return province;
    }
    const char* getPost()
    {
        return post;
    }
    void showAdr()
    {
        cout << "Address : " << houseNo << ", " << district << ", " << city << ", " << province << ", " << post << endl;
    }
};

//*************************************************************

class Person
{
private:
    string fname;
    string lname;
    Date birthday;
    Address adr;
public:
    Person()
    {
        setName("First Name", "Last Name");
        birthday.setBDay(0, 0, 0);
        adr.setAdr("HouseNo", "District", "City", "Province", "Post");
    }
    Person(string f, string l)
    {
        setName(f, l);
        birthday.setBDay(0, 0, 0);
        adr.setAdr("HouseNo", "District", "City", "Province", "Post");
    }
    Person(string f, string l, Date d, Address a)
    {
        setPerson(f, l, d, a);
    }
    ~Person()
    {
        cout << " Delete Person" << endl;
    }
    void setName(string f, string l)
    {
        fname = f;
        lname = l;
    }
    void setFname(string f)
    {
        fname = f;
    }
    void setLname(string l)
    {
        lname = l;
    }
    void setBirthday(Date bd)
    {
        birthday = bd;
    }
    void setAddress(Address ad)
    {
        adr = ad;
    }
    void setPerson(string f, string l, Date bd, Address ad)
    {
        fname = f;
        lname = l;
        birthday = bd;
        adr = ad;
    }
    string getFname()
    {
        return fname;
    }
    string getLname()
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
};
//****************************************************
class Student : virtual public Person
{
private:
    char stuID[10];
public:
    Student()
    {
        setID("0000000000");
    }
    Student(string f, string l, Date bd, Address ad, const char* id) : Person(f, l, bd, ad)
    {
        setID(id);
    }
    ~Student()
    {
        cout << " Delete Student" << endl;
    }
    void setID(const char* id)
    {
        strcpy(stuID, id);
    }
    const char* getID()
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
};

//*******************************************************
class Teacher : virtual public Person
{
private:
    string department;
public:
    Teacher()
    {
        setDep("Department");
    }
    Teacher(string f, string l, Date bd, Address ad, string dep) : Person(f, l, bd, ad)
    {
        setDep(dep);
    }
    ~Teacher()
    {
        cout << " Delete Teacher" << endl;
    }
    void setDep(string dep)
    {
        department = dep;
    }
    string getDep()
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
};

class TeachingAssistant : public Student, public Teacher
{
private:
    string subject;
public:
    TeachingAssistant()
    {
        setSubject("Subject");
    }
    TeachingAssistant(string f, string l, Date bd, Address ad, const char* id, string dep, string subj) : Person(f,l,bd,ad), Student(f,l,bd,ad,id), Teacher(f,l,bd,ad,dep)
    {
        setSubject(subj);
    }
    ~TeachingAssistant()
    {
        cout << " Delete Teaching Assistant" << endl;
    }
    void setSubject(string subj)
    {
        subject = subj;
    }
    string getSubject()
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
};

int main()
{
    cout << "-----Test Class Date 1-----" << endl;
    Date dateTest1;
    dateTest1.showBDay();
    cout << "-----Press Date-----" << endl;
    dateTest1.setBDay(04, 07, 1998);
    dateTest1.showBDay();
    cout << endl;

    cout << "-----Test Class Date 2-----" << endl;
    Date dateTest2;
    cout << "-----Press Date-----" << endl;
    dateTest2.setDay(17);
    dateTest2.setMonth(04);
    dateTest2.setYear(1985);
    cout << dateTest2.getDay() << " / " << dateTest2.getMonth() << " / " << dateTest2.getYear() << endl;
    cout << endl;

    cout << "-----Test Class Address 1-----" << endl;
    Address adrTest1;
    adrTest1.showAdr();
    cout << "-----Press Address-----" << endl;
    adrTest1.setAdr("20/38", "Taiban", "Muang", "Samut Prakan", "10280");
    adrTest1.showAdr();
    cout << endl;

    cout << "-----Test Class Address 2-----" << endl;
    Address adrTest2;
    cout << "-----Press Address-----" << endl;
    adrTest2.setHouseNo("29/81");
    adrTest2.setDistrict("Hua Mak");
    adrTest2.setCity("Bangkapi");
    adrTest2.setProvince("Bangkok");
    adrTest2.setPost("10240");
    cout << adrTest2.getHouseNo() << ", " << adrTest2.getDistrict() << ", " << adrTest2.getCity() << ", " << adrTest2.getProvince() << ", " << adrTest2.getPost() << endl;
    cout << endl;

    cout << "-----Test Class Person 1-----" << endl;
    Person personTest1;
    cout << "-----Press Name-----" << endl;
    personTest1.setPerson("Somchai", "Chankaew", dateTest1, adrTest1);
    personTest1.showPerson();
    cout << endl;

    cout << "-----Test Class Person 2-----" << endl;
    Person personTest2;
    cout << "-----Press Name-----" << endl;
    personTest2.setFname("Sukanya");
    personTest2.setLname("Bunkwan");
    personTest2.setBirthday(dateTest2);
    personTest2.setAddress(adrTest2);
    cout << personTest2.getFname() << " " << personTest2.getLname() << endl;
    personTest2.getBirthday();
    personTest2.getAddress();
    cout << endl;

    cout << "-----Test Class Student-----" << endl;
    Student stuTest(personTest1.getFname(), personTest1.getLname(), dateTest1, adrTest1, "0000000000");
    stuTest.showStudent();
    cout << "-----Press ID-----" << endl;
    stuTest.setID("6605006680");
    cout << "ID: " << stuTest.getID() << endl;
    stuTest.showStudent();
    cout << endl;

    cout << "-----Test Class Teacher-----" << endl;
    Teacher teaTest(personTest2.getFname(), personTest2.getLname(), dateTest2, adrTest2, "No Info");
    teaTest.showTeacher();
    cout << "-----Press Department-----" << endl;
    teaTest.setDep("History");
    cout << "Department: " << teaTest.getDep() << endl;
    teaTest.showTeacher();
    cout << endl;

    cout << "-----Test Class Teaching Assistant-----" << endl;
    TeachingAssistant taTest(personTest1.getFname(), personTest1.getLname(), dateTest1, adrTest1, stuTest.getID(), "Humanities", "No Info");
    taTest.showTA();
    cout << "-----Press Subject-----" << endl;
    taTest.setSubject("ENL3103 (English Syntax)");
    cout << "Subject: " << taTest.getSubject() << endl;
    taTest.showTA();
    cout << endl;
    return 0;
}