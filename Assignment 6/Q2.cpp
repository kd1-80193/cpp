#include <iostream>
using namespace std;
class Employee
{
private:
  int ID;
  float sal;

public:
  Employee()
  {
    cout << "inside Employee constructor" << endl;
    this->ID = 0;
    this->sal = 000;
  }
  Employee(int ID, float sal)
  {
    this->ID = ID;
    this->sal = sal;
  }
  void setID(int ID)
  {
    this->ID = ID;
  }
  void setSal(int sal)
  {
    this->sal = sal;
  }
  int getID()
  {
    return this->ID;
  }
  float getSal()
  {
    return this->sal;
  }
  void accept()
  {
    cout << "Enter ID:" << endl;
    cin >> this->ID;
    cout << "Enter salary:" << endl;
    cin >> this->sal;
  }
  void display()
  {
    cout << "ID:" << ID << endl;
    cout << "Salary:" << sal << endl;
  }
};

// Class Manager started.
class Manager : virtual public Employee
{
private:
  float bonus;

public:
  Manager()
  {
    cout << "inside Manager constructor" << endl;
    ;
    this->bonus = 0;
  }
  Manager(float bonus)
  {
    this->bonus = bonus;
  }
  void setBonus(float bonus)
  {
    this->bonus = bonus;
  }
  float getBonus(float bonus)
  {
    return bonus;
  }

  void accept()
  {
    Employee::accept();
    acceptManager();
  }

  void display()
  {
    Employee::display();
    displayManager();
  }

protected:
  void acceptManager()
  {
    cout << "Enter the bonus:" << endl;
    cin >> this->bonus;
  }
  void displayManager()
  {
    cout << "Bonus:" << this->bonus << endl;
  }
};

// Class salesman started.
class Salesman : virtual public Employee
{
private:
  float comm;

public:
  Salesman()
  {
    cout << "inside Salesman constructor" << endl;
    this->comm = 0;
  }
  Salesman(float comm)
  {
    this->comm = comm;
  }
  void setComm(float comm)
  {
    this->comm;
  }
  float getComm()
  {
    return this->comm;
  }
  void accept()
  {
    Employee::accept();
    acceptSalesman();
  }
  void display()
  {
    Employee::display();
    displaySalesman();
  }

protected:
  void acceptSalesman()
  {
    cout << "Enter commission:" << endl;
    cin >> this->comm;
  }
  void displaySalesman()
  {
    cout << "commission:" << this->comm << endl;
  }
};

// Class salesmanager started.
class SalesManager : public Manager, public Salesman
{
public:
  SalesManager()
  {
    cout << "inside Salesmanager constructor" << endl;
    ;
  }
  SalesManager(int ID, float sal, float bonus, float comm)
  {
    setID(ID);
    setSal(sal);
    setBonus(bonus);
    setComm(comm);
  }
  void accept()
  {
    Employee::accept();
    acceptManager();
    acceptSalesman();
  }
  void display()
  {
    Employee::display();
    displayManager();
    displaySalesman();
  }
};
int main()
{
  SalesManager sm1;
  sm1.accept();
  sm1.display();

  return 0;
}