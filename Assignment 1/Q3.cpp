#include <iostream>
#include <string>

class Student {
private:
    int rollNo;
    std::string name;
    float marks;

public:
    // Constructor to initialize a Student object
    Student() : rollNo(0), name(""), marks(0.0) {}

    // Function to initialize a Student object
    void initStudent() {
        rollNo = 0;
        name = "";
        marks = 0.0;
    }

    // Function to print a Student object on the console
    void printStudentOnConsole() {
        std::cout << "Roll No: " << rollNo << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: " << marks << std::endl;
    }

    // Function to accept student information from the console
    void acceptStudentFromConsole() {
        std::cout << "Enter Roll No: ";
        std::cin >> rollNo;

        std::cin.ignore(); // Clear the input buffer
        std::cout << "Enter Name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Marks: ";
        std::cin >> marks;
    }
};

int main() {
    Student student;
    int choice;

    do {
        std::cout << "\nStudent Management Menu:\n";
        std::cout << "1. Initialize Student\n";
        std::cout << "2. Print Student\n";
        std::cout << "3. Accept Student\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                student.initStudent();
                std::cout << "Student initialized.\n";
                break;
            case 2:
                student.printStudentOnConsole();
                break;
            case 3:
                student.acceptStudentFromConsole();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}