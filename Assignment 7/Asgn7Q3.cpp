#include <iostream>
using namespace std;

class Employee // base class
{
private:
    int id;
    float sal;

protected:
    string designation;

public:
    Employee()
    {
        cout << "Employee Class Constructor" << endl;
        this->id = 0;
        this->sal = 0;
    }
    Employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }
    int get_id()
    {
        return this->id;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    float get_sal()
    {
        return this->sal;
    }
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    void accept()
    {
        cout << "Enter the ID = ";
        cin >> this->id;
        cout << "Enter the Salary = ";
        cin >> this->sal;
    }
    virtual void display() = 0;

    string get_Designation()
    {
        return this->designation;
    }
    void set_Designation(string designation)
    {
        this->designation = designation;
    }
    virtual ~Employee(){

    }
};
class Manager : virtual public Employee // derived class1
{
private:
    float bonus;

public:
    Manager()
    {
        cout << "Manager Class Constructor" << endl;
        this->bonus = 0;
        this->designation = "Manager";
    }
    Manager(float bonus, int id, float sal)
    {
        Employee::set_id(id);
        Employee::set_sal(sal);
        this->bonus = bonus;
        this->designation = "Manager";
    }
    string get_Designation()
    {
        return this->designation;
    }
    float get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        cout << "Enter the Bonus = ";
        cin >> this->bonus;
    }
    void display()
    {
        cout << "Employee Manager ID :" << get_id() << endl;
        cout << "Employee Manager Sal :" << get_sal() << endl;
        cout << "Bonus = " << this->bonus << endl;
    }

protected:
    void accept_manager()
    {
        cout << "Bonus = ";
        cin >> this->bonus;
    }
    void display_manager()
    {
        cout << "Bonus is = " << bonus << endl;
    }
};
class Salesman : virtual public Employee // derived class2
{
private:
    float comm;

public:
    Salesman()
    {
        cout << "Salesman Class Constructor" << endl;
        this->comm = 0;
        this->designation = "Salesman";
    }
    Salesman(float comm, float bonus, int id, float sal)
    {
        Employee::set_id(id);
        Employee::set_sal(sal);
        this->comm = comm;
        this->designation = "Salesman";
    }
    string get_Designation()
    {
        return this->designation;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void accept()
    {
        Employee::accept();
        cout << "Enter the Commison = ";
        cin >> this->comm;
    }
    void display()
    {
        cout << "Employee Salesman ID :" << get_id() << endl;
        cout << "Employee Salesman Sal :" << get_sal() << endl;
        cout << "Comm = " << this->comm << endl;
    }

protected:
    void accept_salesman()
    {
        cout << "Commison = ";
        cin >> this->comm;
    }
    void display_salesman()
    {
        cout << "Commision is = " << comm << endl;
    }
};
class Sales_manager : public Salesman, public Manager // indirect derived class
{
public:
    Sales_manager()
    {
        cout << "Sales Manager Class Constructor" << endl;
        this->designation = "Sales_manager";
    }
    Sales_manager(int id, float sal, float bonus, float comm)
    {
        Employee::set_id(id);
        Employee::set_sal(sal);
        Manager::set_bonus(bonus);
        Salesman::set_comm(comm);
        this->designation = "Sales_manager";
    }
    void accept()
    {
        Employee::accept();
        Manager::accept_manager();
        Salesman::accept_salesman();
    }
    void display()
    {

        Manager::display_manager();
        Salesman::display_salesman();
    }
    string get_Designation()
    {
        return this->designation;
    }
};

int displayMenu()
{
    int choice;
    cout << "------------------------------------" << endl;
    cout << "\nMenu:" << endl;
    cout << "0. Quit" << endl;
    cout << "1. Accept Employee" << endl;
    cout << "2. Display Employee" << endl;
    cout << "3. Display Employee Count" << endl;
    cout << "------------------------------------" << endl;
    cin >> choice;
    return choice;
}

void DisplayEmpMenu()
{

    cout << "------------------------------------" << endl;
    cout << "\nDISPLAY OPTIONS:" << endl;
    cout << "1. Display Employees Salesman" << endl;
    cout << "2. Display Employees Sales_manager" << endl;
    cout << "3. Display Employees manager" << endl;
    cout << "3. Display All Employees " << endl;
    cout << "------------------------------------" << endl;
}

void EmployeeMenu()
{
    cout << "------------------------------------" << endl;
    cout << "\nMenu:" << endl;
    cout << "1. Accept Employee Salesman" << endl;
    cout << "2. Accept Employee Sales_manager" << endl;
    cout << "3. Accept Employee manager" << endl;
    cout << "------------------------------------" << endl;
}

void CountMenu()
{
    cout << "------------------------------------" << endl;
    cout << "ENTER CHOICE" << endl;
    cout << "1. Calculate Manager Count " << endl;
    cout << "2. Calculate Sales_manager Count " << endl;
    cout << "3. Calculate Salesman Count " << endl;
    cout << "4. Calculate Employee Count " << endl;
    cout << "------------------------------------" << endl;
}

void DisplayEmp(int empcount, Employee **emp)
{
    int choice;
    DisplayEmpMenu();
    cin >> choice;

    switch (choice)
    {
    case 1:
        for (int i = 0; i < empcount; ++i)
        {

            if (typeid(*emp[i])==typeid(Sales_manager))
                emp[i]->display();
        }

        break;
    case 2:
        for (int i = 0; i < empcount; ++i)
        {

            if (emp[i]->get_Designation() == "Sales_manager")
                emp[i]->display();
        }
        break;
    case 3:
        for (int i = 0; i < empcount; ++i)
        {

            if (emp[i]->get_Designation() == "Manager")
                emp[i]->display();
        }
        break;
    case 4:
        for (int i = 0; i < empcount; ++i)
        {
            emp[i]->display();
        }
        break;

    default:
        cout << "INVALID CHOICE " << endl;
        break;
    }
}

void DisplayEmpCount(int empcount, int managercount, int salesmancount, int salesmanagercount, Employee **emp)
{
    int ch;
    CountMenu();
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Total No of Managers : " << managercount << endl;
        break;
    case 2:
        cout << "Total No of Sales Managers : " << salesmanagercount << endl;
        break;
    case 3:
        cout << "Total No of Salesman : " << salesmancount << endl;
        break;
    case 4:
        cout << "Total No of Employees  : " << managercount + salesmanagercount + salesmancount << endl;
        break;
    default:
        break;
    }
}

int main()
{
    int choice = 0;
    int empcount = 0;
    int managercount = 0;
    int salesmancount = 0;
    int salesmanagercount = 0;
    int MAX = 10;
    Employee *emp[MAX];

    do
    {
        choice = displayMenu();
        switch (choice)
        {
        case 1: // accept
            int ch;
            if (empcount < MAX)
                EmployeeMenu();
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                Salesman *salesman = new Salesman;
                salesman->accept();
                emp[empcount] = salesman;
                empcount++;
                salesmancount++;
                cout << "Salesman Details Added Successfully" << endl;
            }
            break;
            case 2:
            {
                Sales_manager *smanager = new Sales_manager;
                smanager->accept();
                emp[empcount] = smanager;
                empcount++;
                salesmanagercount++;
                cout << "Sales_manager Details Added Successfully" << endl;
            }
            break;
            case 3:
            {
                Manager *manager = new Manager;
                manager->accept();
                emp[empcount] = manager;
                empcount++;
                managercount++;
                cout << "Manager Details Added Successfully" << endl;
            }
            break;
            default:
                cout << "WRONG CHOICE..." << endl;
                break;
            }
            break;

        case 2:
            DisplayEmp(empcount, emp);
            break;
        case 3:
            DisplayEmpCount(empcount, managercount, salesmancount, salesmanagercount, emp);
            break;

        case 0:
            if (empcount != 0)
            {
                for (int i = 0; i < empcount; ++i)
                {
                    delete emp[i];
                }
                cout << "memory is freed" << endl;
            }
           return 0;

        default:
            cout << "WRONG CHOICE TRY AGAIN>>" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}