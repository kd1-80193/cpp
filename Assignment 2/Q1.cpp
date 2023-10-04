/*Q1. Create a namespace NStudent. Create the Student class(created as per assignment-1 Q3) inside
namespace. Test the functionalities.*/

#include <iostream>
using namespace std;
namespace NStudent
{
    class student
    {
    private:
        int rollno;
        string name;
        float marks;

    public:
        void initStudent()
        {
            this->rollno = 1;
            this->name = 'king';
            this->marks = 70;
        }
        void acceptStudentFromConsole()
        {
            cout << "student roll no\n";
            cin >> this->rollno;
            cout << "student name \n";
            cin >> this->name;
            cout << "student marks\n";
            cin >>this->marks;
        }

        void printStudentOnConsole()
        {
            cout << " The details are \n";
            cout << "roll no = " << this->rollno << endl;
            cout << "Name = " << this->name << endl;
            cout << "marks is = " << this->marks << endl;
        }
    };
}
using namespace NStudent;
int main()
{
    int choice;
    student s1;
    do
    {
        printf("\nEnter choice 1 \n 2. \n 3. \n 0.exit \n"); // ctrl shift i
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            s1.initStudent();
            s1.printStudentOnConsole();
            break;

        case 2:
            s1.acceptStudentFromConsole();

            break;
        case 3:
            // acceptDateFromConsole(&d1);
            s1.printStudentOnConsole();

        default:
            break;
        }
    } while (choice != 0);
}