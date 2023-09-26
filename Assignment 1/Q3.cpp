
#include <iostream>
#include <string>

class Student
{
private:
    int rollNo;
    std::string name;
    double marks;

public:
    void initStudent()
    {
        rollNo = 0;
        name = "";
        marks = 0.0;
    }

    void printStudentOnConsole()
    {
        std::cout << "Roll No: " << rollNo << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: " << marks << std::endl;
    }

    void acceptStudentFromConsole()
    {
        std::cout << "Enter Roll No: ";
        std::cin >> rollNo;
        std::cin.ignore(); // Clear the newline character from the buffer.
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Marks: ";
        std::cin >> marks;
    }
};

int main()
{
    Student student;
    int choice;

    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Initialize Student" << std::endl;
        std::cout << "2. Print Student" << std::endl;
        std::cout << "3. Accept Student from Console" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            student.initStudent();
            std::cout << "Student initialized." << std::endl;
            break;
        case 2:
            student.printStudentOnConsole();
            break;
        case 3:
            student.acceptStudentFromConsole();
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 4);

    return 0;
}
