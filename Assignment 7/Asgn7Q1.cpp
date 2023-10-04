#include <iostream>
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
        cout<<"Inside the Date class constructor."<<endl;
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int getDay()
    {
        return day;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    int getMonth()
    {
        return month;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    int getYear()
    {
        return year;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    void accept()
    {
        cout << "Enter the date: " << endl;
        cin >> this->day;
        cout << "Enter the month: " << endl;
        cin >> this->month;
        cout << "Enter the year: " << endl;
        cin >> this->year;
    }
    void display()
    {
        cout << "Date is=>" << this->day << "/" << this->month << "/" << this->year << endl;
        if (isLeapYear())
            cout << "The year " << year << " is a leap year." << endl;
        else
            cout << "The year " << year << " is not a leap year." << endl;
    }
    bool isLeapYear()
    {

        if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        else
            return false;
    }
};

class Person
{
private:
    string name;
    string addr;
    Date dob;

public:
    Person()
    {
        cout<<"Inside the Person class constructor."<<endl;
        this->name = "";
        this->addr = "";
    }
    Person(string name, string addr, Date dob) : dob(dob)
    {
        this->name = name;
        this->addr = addr;
    }
    string getName()
    {
        return name;
    }
    void setName()
    {
        this->name = name;
    }
    string getnAddr()
    {
        return addr;
    }
    void setAddr()
    {
        this->addr = addr;
    }
    void acceptPerson()
    {
        cout << "Enter the name: " << endl;
        cin >> this->name;
        cout << "Enter the address: " << endl;
        cin >> this->addr;
        dob.accept();
    }
    void displayPerson()
    {
        cout << "Employee name: " << name << endl;
        cout << "Employee address: " << addr << endl;
        dob.display();
    }
};

class Employee : public Person
{
private:
    int empid;
    float salary;
    string dept;
    Date doj;

public:
    Employee()
    {
        cout<<"Inside the Employee class constructor."<<endl;
        this->empid = 0;
        this->salary = 0;
        this->dept = "";
    }
    Employee(int empid, float salary, string dept, Date doj) : doj(doj)
    {
        this->empid = empid;
        this->salary = salary;
        this->dept = dept;
    }
    int getEmpid()
    {
        return empid;
    }
    void setEmpid(int empid)
    {
        this->empid = empid;
    }
    float getSalary()
    {
        return salary;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    string getDept()
    {
        return dept;
    }
    void setDept(string dept)
    {
        this->dept = dept;
    }
    void acceptEmployee()
    {
        cout << "Enter the employee id: " << endl;
        cin >> this->empid;
        cout << "Enter the employee salary: " << endl;
        cin >> this->salary;
        cout << "Enter the employee department: " << endl;
        cin >> this->dept;
        doj.accept();
    }
    void displayEmployee()
    {
        cout << "Employee id: " << empid << endl;
        cout << "Employee salary: " << salary << endl;
        cout << "Employee department: " << dept << endl;
        doj.display();
    }
};

int main()
{
    // Person *dptr=new Employee; //upcasting
    // dptr->acceptPerson();
    // dptr->displayPerson();

    Employee e;
    e.acceptEmployee();
    e.displayEmployee();

    // Date dob(16,12,1995);
    // Date doj(23, 02, 2002);
    // Employee e(16, 50000, "Developer", doj);
    // e.displayEmployee();

    Person p1;
    p1.acceptPerson();
    p1.displayPerson();
    return 0;
}