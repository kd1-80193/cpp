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
    day = 0;
    month = 0;
    year = 0;
  }
  Date(int day, int month, int year)
  {
    this->day = day;
    this->month = month;
    this->year = year;
  }
  void acceptDate()
  {
    cout << "Enter day:" << endl;
    cin >> day;
    cout << "Enter month:" << endl;
    cin >> month;
    cout << "Enter year:" << endl;
    cin >> year;
  }
  void setDay(int day)
  {
    this->day = day;
  }
  void setMonth(int month)
  {
    this->month = month;
  }
  void setYear(int day)
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

  void displayDate()
  {
    cout << "Joining date:";
    cout << day << "/" << month << "/" << year << endl;
  }
  void isLeapyear(int year = 2000)
  {
    this->year = year;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
      printf("Year is leap year\n");
    }
    else
    {
      printf("Year is not leap year\n");
    }
  }
};

// class Employee started.
class Employee
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

  void acceptEmp()
  {
    cout << "Enter ID of emp:" << endl;
    cin >> this->ID;
    cout << "Enter salary of emp:" << endl;
    cin >> this->sal;
    cout << "Enter name of department:" << endl;
    cin >> this->dept;
    doj.acceptDate();
  }
  void displayEmp()
  {
    cout << "ID:" << ID << endl;
    cout << "Salary:" << sal << endl;
    cout << "Department name:" << dept << endl;
    doj.displayDate();
  }
};

// Class person started.
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
  void acceptPerson()
  {
    cout << "Enter name of person:" << endl;
    cin >> name;
    cout << "Enter address of person:" << endl;
    cin >> address;
    dob.acceptDate();
  }
  void displayPerson()
  {
    cout << "Name:" << name << endl;
    cout << "Address:" << address << endl;
    dob.displayDate();
  }
  void isyearisLeap(int year)
  {
    dob.isLeapyear(year);
  }
};
int main()
{
  Employee e1(100, 5000, "MGR", 15, 03, 2000);
  e1.displayEmp();
  e1.acceptEmp();
  e1.displayEmp();
  Person p1("Rutvik", "Bapu colony", 15, 03, 2000);
  p1.acceptPerson();
  p1.displayPerson();
  p1.isyearisLeap(2000);
  return 0;
}