#include <iostream>
#define size 5
using namespace std;
class Student
{
private:
    string name;
    string gender;
    int rollno;
    float *marks;

public:
    Student()
    {
        this->rollno = 0;
        this->name = "";
        this->gender = "";
        this->marks = new float[3];
    }
    Student(int rollno, string name, string gender)
    {
        this->rollno = rollno;
        this->name = name;
        this->gender = gender;
        this->marks = new float[3];
        float marks;
    }
    void acceptData()
    {
        cout << "enter rollno=";
        cin >> this->rollno;
        cout << "enter name=";
        cin >> this->name;
        cout << "enter gender=";
        cin >> this->gender;
        for (int i = 0; i < 3; i++)
        {
            float marks;
            cout << "enter marks=";
            cin >> marks;
            this->marks[i] = marks;
        }
    }
    void printData()
    {
        cout << "rollno=" << this->rollno << endl;
        cout << "name=" << this->name << endl;
        cout << "gender=" << this->gender << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "marks=" << this->marks[i] << endl;
        }
    }
    int getRollno()
    {
        return this->rollno;
    }

    friend void searchRecords();
    friend void sortRecords();
};
void searchRecords(Student s[])
{
    int key;
    cout << "enter rollno for searching: " << endl;
    cin >> key;
    for (int i = 0; i < 3; i++)
    {
        if (s[i].getRollno() == key)
            cout << "index=" << i << endl;
        else
            cout << "rollno not found" << endl;
    }
}
void sortRecords(Student s[])
{
    Student temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (s[i].getRollno() > s[j].getRollno())
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
enum Emenu
{
    EXIT,
    ACCEPT_DATA,
    RECORDS_SEARCHING,
    RECORDS_SORTING,
    PRINT_DATA
};
Emenu menu()
{
    int choice;
    cout << "******************************************" << endl;
    cout << "select any choice" << endl;
    cout << "0.EXIT" << endl;
    cout << "1. For accepting records" << endl;
    cout << "2.For searching records" << endl;
    cout << "3.For sorting records" << endl;
    cout << "4.For printing records" << endl;
    cin >> choice;
    cout << "***********************************************" << endl;
    return Emenu(choice);
}
int main()
{
    Emenu choice;
    Student s[size];
    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case ACCEPT_DATA: 
            for (int i = 1; i < size; i++)
            {
             s[i].acceptData();
            }
            break;

        case RECORDS_SEARCHING: 
            searchRecords(s);
            break;

        case RECORDS_SORTING:
            sortRecords(s); 
            break;

        case PRINT_DATA:
            for (int i = 1; i < size; i++)
            {
                s[i].printData();
            } 
            break;

        default:
            cout<<"enter valid choice"<<endl;
            break;
        }
    }
    return 0;
}
