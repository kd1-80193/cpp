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
    this->day = 15;
    this->month = 03;
    this->year = 2000;
  }
  Date(int day, int month, int year)
  {
    this->day = day;
    this->month = month;
    this->year = year;
  }
  void setDay(int day)
  {
    this->day = day;
  }
  void setMonth(int month)
  {
    this->month = month;
  }
  void setYear(int month)
  {
    this->year = year;
  }
  int getDay()
  {
    return this->day;
  }
  int getMonth()
  {
    return this->month;
  }
  int getYear()
  {
    return this->year;
  }
  void accept()
  {
    cout << "Enter day:" << endl;
    cin >> this->day;
    cout << "Enter month:" << endl;
    cin >> this->month;
    cout << "Enter year:" << endl;
    cin >> this->year;
  }
  void display()
  {
    cout << "DD:MM:YYYY=" << day << ":" << month << ":" << year << endl;
  }
  bool isLeapYear()
  {
    if (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
// Person class started.
class Person
{
private:
  string name;
  string address;
  Date dob;

public:
  Person()
  {
    this->name = " ";
    this->address = " ";
  }
  Person(string name, string address, int day, int month, int year) : dob(day, month, year)
  {
    this->name = name;
    this->address = address;
  }
  void setName(string name)
  {
    this->name = name;
  }
  void setAddress(string address)
  {
    this->address = address;
  }
  string getName()
  {
    return this->name;
  }
  string getaddress()
  {
    return this->address;
  }
  void setBirthDate(int day, int month, int year)
  {
    dob.setDay(day);
    dob.setMonth(month);
    dob.setYear(year);
  }
  Date getBirthDate()
  {
    return dob;
  }
  void accept()
  {
    cout << "Enter name of person:" << endl;
    cin >> name;
    cout << "Enter address of person:" << endl;
    cin >> address;
    cout << "Enter date of birth:" << endl;
    dob.accept();
  }
  void display()
  {
    cout << "Name:" << name << endl;
    cout << "Address:" << address << endl;
    dob.display();
  }
};

// Class employee has started.
class Employee : protected Person
{
private:
  int ID;
  float sal;
  string dept;
  Date doj;

public:
  Employee()
  {
    ID = 0;
    sal = 0;
    dept = " ";
  }
  Employee(int ID, float sal, string dept, int day, int month, int year) : doj(day, month, year)
  {
    this->ID = ID;
    this->sal = sal;
    this->dept = dept;
  }
  void setID(int ID)
  {
    this->ID = ID;
  }
  void setSal(float sal)
  {
    this->sal = sal;
  }
  void setDept(string dept)
  {
    this->dept = dept;
  }
  int getID()
  {
    return this->ID;
  }
  float getSal()
  {
    return this->sal;
  }
  string getDept()
  {
    return this->dept;
  }
  void setJoiningDate(int day, int month, int year)
  {
    doj.setDay(day);
    doj.setMonth(month);
    doj.setYear(year);
  }
  Date getJoiningDate()
  {
    return doj;
  }

  void accept()
  {
    Person::accept();
    cout << "Enter ID of emp:" << endl;
    cin >> this->ID;
    cout << "Enter salary of emp:" << endl;
    cin >> this->sal;
    cout << "Enter name of department:" << endl;
    cin >> this->dept;
    cout << "Enter the date of Joining:" << endl;
    doj.accept();
  }
  void display()
  {
    cout << "------------------------------------" << endl;
    Person::display();
    cout << "ID:" << ID << endl;
    cout << "Salary:" << sal << endl;
    cout << "Department name:" << dept << endl;
    cout << "Date of joining:";
    doj.display();
  }
};

int main()
{
  // Employee e1;
  // e1.accept();
  // Person p1;
  Date d1;
  d1.display();

  return 0;
}