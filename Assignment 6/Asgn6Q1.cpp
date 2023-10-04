#include <iostream>
#include <cstring>
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
    void acceptDate()
    {
        cout << "Enter the date: " << endl;
        cin >> this->day;
        cout << "Enter the month: " << endl;
        cin >> this->month;
        cout << "Enter the year: " << endl;
        cin >> this->year;
    }
    void displayDate()
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
        this->name = "";
        this->addr = "";
    }
    Person(string name, string addr, int day, int month, int year) : dob(day, month, year)
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
        dob.acceptDate();
    }
    void displayPerson()
    {
        cout << "Employee name: " << name << endl;
        cout << "Employee address: " << addr << endl;
        dob.displayDate();
    }
};

class Employee
{
private:
    int empid;
    float salary;
    string dept;
    Date doj;

public:
    Employee()
    {
        this->empid = 0;
        this->salary = 0;
        this->dept = "";
    }
    Employee(int empid, float salary, string dept, int day, int month, int year) : doj(day, month, year)
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
        doj.acceptDate();
    }
    void displayEmployee()
    {
        cout << "Employee id: " << empid << endl;
        cout << "Employee salary: " << salary << endl;
        cout << "Employee department: " << dept << endl;
        doj.displayDate();
    }
};

int main()
{
    Employee e;
    e.acceptEmployee();
    e.displayEmployee();

    Person p1;
    p1.acceptPerson();
    p1.displayPerson();

    return 0;
}