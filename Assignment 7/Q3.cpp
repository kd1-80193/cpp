#include <iostream>
using namespace std;
class Employee
{
private:
  int ID;
  int sal;
  string designation;

public:
  Employee()
  {
    cout << "inside Employee constructor" << endl;
    this->ID = 0;
    this->sal = 0;
  }
  Employee(int ID, int sal)
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
  void setDesignation(string designation)
  {
    this->designation = designation;
  }
  string getDesignation()
  {
    return this->designation;
  }
  int getID()
  {
    return this->ID;
  }
  int getSal()
  {
    return this->sal;
  }
  virtual void accept()
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
  int bonus;

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

public:
  Manager()
  {
    cout << "inside Manager constructor" << endl;
    ;
    this->bonus = 0;
    setDesignation("Manager");
  }
  Manager(int bonus)
  {
    this->bonus = bonus;
  }
  void setBonus(int bonus)
  {
    this->bonus = bonus;
  }
  int getBonus(int bonus)
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
};

// Class salesman started.
class Salesman : virtual public Employee
{
private:
  int comm;

public:
  Salesman()
  {
    cout << "inside Salesman constructor" << endl;
    this->comm = 0;
    setDesignation("Salesman");
  }
  Salesman(int comm)
  {
    this->comm = comm;
  }
  void setComm(int comm)
  {
    this->comm;
  }
  int getComm()
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
    setDesignation("Salesmanager");
  }
  SalesManager(int ID, int sal, int bonus, int comm)
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

int menu()
{
  int choice;
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "0.To exit!!" << endl;
  cout << "1.To Enter into  sub menu of accept employee" << endl;
  cout << "2.To display the the count of employees with respect to there designation" << endl;
  cout << "3.To display respective designation employee" << endl;
  cin >> choice;
  return choice;
}
int subMenu()
{
  int subChoice;
  cout << "--------------------------------------------------------------------------------" << endl;
  cout << "0.To EXIT " << endl;
  cout << "1.to give input for manager " << endl;
  cout << "2.to give input for saleman " << endl;
  cout << "3.to give input for salesmanager " << endl;
  cin >> subChoice;
  return subChoice;
}

int main()
{
  Employee *arr[10];
  int choice;
  int index = 0;
  int subChoice;
  int mgrCount = 0;
  int salesmanCount = 0;
  int salesmgrCount = 0;
  while ((choice = menu()) != 0)
  {
    switch (choice)
    {
    case 1:
      while ((subChoice = subMenu()) != 0)
      {
        switch (subChoice)
        {
        case 1:
          arr[index] = new Manager();
          arr[index]->accept();
          mgrCount++;
          index++;
          break;
        case 2:
          arr[index] = new Salesman();
          arr[index]->accept();
          salesmanCount++;
          index++;
          break;
        case 3:
          arr[index] = new SalesManager();
          arr[index]->accept();
          salesmgrCount++;
          index++;
          break;
        default:
          break;
        }
      }
      break;
    case 2:
      cout << "Count of Manager ::" << mgrCount << endl;
      cout << "Count of Salesman ::" << salesmanCount << endl;
      cout << "Count of SalesManager ::" << salesmgrCount << endl;
      break;

    case 3:
      for (int i = 0; i < index; i++)
      {
        if (arr[i]->getDesignation() == "Manager")
        {
          cout << "Below employess belogn to Manager designation" << endl;
          cout << arr[i]->getID() << endl;
        }
        else if (arr[i]->getDesignation() == "Salesman")
        {
          cout << "Below employess belogn to salesman designation" << endl;
          cout << arr[i]->getID() << endl;
        }
        else if (arr[i]->getDesignation() == "Salesmanager")
        {
          cout << "Below employess belogn to salesmanager designation" << endl;
          cout << arr[i]->getID() << endl;
        }
      }

      break;
    default:
      break;
    }
  }

  for (int i = 0; i < index; i++)
  {
    delete arr[i];
  }
  return 0;
}