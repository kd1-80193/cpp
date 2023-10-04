#include <iostream>
using namespace std;
// parent class (or) base class
class Employee
{
private:
    int id;
    float salary;
public:
    Employee()
    {
        cout << "employee::constructor" << endl;
        this->id = 0;
        this->salary = 0;
    }
    Employee(int id, float salary)
    {
        cout << "employee::para::constructor" << endl;
        this->id = id;
        this->salary = salary;
    }
    int getid()
    {
        return this->id = id;
    }
    float getsalary()
    {
        return this->salary = salary;
    }
    void setid(int id)
    {
        this->id = id;
    }
    void setsalary(float salary)
    {
        this->salary = salary;
    }
    void accept()
    {
        // cout << "enter employee data" << endl;
        cout << "enter id=";
        cin >> id;
        cout << "enter salary=";
        cin >> salary;
    }
    void display()
    {
        cout << "id=" << this->id<<endl;
        cout << "salary=" << this->salary<<endl;
    }
};
// child class (or) derived class
class Manager : virtual public Employee                     //virtual
{
private:
    float bonus;
protected:
    void accept_manager()
    {
        cout << "enter bonus=";
        cin >> bonus;
    }
     void display_manager()
    {
        cout << "bonus=" << this->bonus<<endl;
    }
public:
    Manager()
    {
        cout << "manager::constructor" << endl;
        this->bonus = 0;
    }
    Manager(float bonus, int id, float salary)
    {
        cout << "manager::para::constructor"<< endl;
        setid(id);
        setsalary(salary);
        this->bonus = bonus;
    }
    float getbonus()
    {
        return this->bonus;
    }
    void setbonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        cout << "enter bonus=";
        cin >> bonus;
    }
    void display()
    {
        Employee::display();
        cout << "bonus=" << this->bonus<<endl;
    }
};
// child class (or) derived class
class Salesman : virtual public Employee                    //virtual
{
private:
    float comm;
protected:
    void accept_salesman()
    {
        cout << "enter comm=";
        cin >> comm;
    }
    void display_Salesman()
    {
        cout << "comm=" << this->comm<<endl;
    }
public:
    Salesman()
    {
        cout<<"salesman::constucctor"<< endl;
        this->comm = 0;
    }
    Salesman(int id, float salary, float comm)
    {
        cout<<"salesman::para::constucctor"<< endl;
        Employee::setid(id);
        Employee::setsalary(salary);
        this->comm = comm;
    }
    float getcomm()
    {
        return this->comm;
    }
    void setcomm(float comm)
    {
        this->comm = comm;
    }
    void accept()
    {
        Employee::accept();
        cout << "enter comm=";
        cin >> comm;
    }
    void display()
    {
        Employee::display();
        cout << "comm=" << this->comm<<endl<<endl;
    }
};
//indirect derived class
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout<<"SalesManager::constucctor"<< endl;
    }
    SalesManager(int id,float salary,float bonus, float comm)
    {
        cout<<"SalesManager::para::constucctor"<< endl;
        Employee::setid(id);
        Employee::setsalary(salary);
        Manager::setbonus(bonus);
        Salesman::setcomm(comm);
    }
    void accept()
    {
        Employee::accept();
        Manager::accept_manager();
        Salesman::accept_salesman();
    }
    void display()
    {
        Employee::display();
        Manager::display_manager();
        Salesman::display_Salesman();
    }
};
int main()
{
    // Manager m1(100,101,1000);
    // m1.display();

    // Manager m2;
    // m2.accept();
    // m2.display();

    // Salesman s1(888, 505,1000);
    // s1.display();

    // SalesManager m0;
    // m0.display();

    // SalesManager m2(501,3251.42,10.5,100);
    // m2.display();

    SalesManager m1;
    m1.accept();
    m1.display();

    // Manager m1;
    // m1.display();
}