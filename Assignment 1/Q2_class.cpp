#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor to initialize Date object
    Date() : day(0), month(0), year(0) {}

    // Function to initialize a Date object
    void initDate() {
        day = 0;
        month = 0;
        year = 0;
    }

    // Function to print a Date object on the console
    void printDateOnConsole() {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }

    // Function to accept a Date from the console
    void acceptDateFromConsole() {
        std::cout << "Enter day: ";
        std::cin >> day;

        std::cout << "Enter month: ";
        std::cin >> month;

        std::cout << "Enter year: ";
        std::cin >> year;
    }

    // Function to check the year is a leap year or not
    bool isLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        else
            return false;
    }
};

int main() {
    Date myDate;
    int choice;

    do {
        std::cout << "\nDate Management Menu:\n";
        std::cout << "1. Initialize Date\n";
        std::cout << "2. Print Date\n";
        std::cout << "3. Accept Date\n";
        std::cout << "4. Check Leap Year\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myDate.initDate();
                std::cout << "Date initialized.\n";
                break;
            case 2:
                myDate.printDateOnConsole();
                break;
            case 3:
                myDate.acceptDateFromConsole();
                break;
            case 4:
                if (myDate.isLeapYear()) {
                    std::cout << "It's a leap year.\n";
                } else {
                    std::cout << "It's not a leap year.\n";
                }
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}