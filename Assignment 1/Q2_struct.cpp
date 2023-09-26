#include <iostream>
using namespace std;

// Define a structure to represent a Date
struct Date {
    int day;
    int month;
    int year;

    // Function to initialize a Date
    void initDate() {
        day = 0;
        month = 0;
        year = 0;
    }

    // Function to print a Date on the console
    void printDateOnConsole() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    // Function to accept a Date from the console
    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> day;

        cout << "Enter month: ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;
    }

    // Function to check if a year is a leap year
    bool isLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Date myDate;
    int choice;

    do {
        cout << "\nDate Management Menu:" << endl;
        cout << "1. Initialize Date" << endl;
        cout << "2. Print Date" << endl;
        cout << "3. Accept Date" << endl;
        cout << "4. Check Leap Year" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myDate.initDate();
                cout << "Date initialized." << endl;
                break;
            case 2:
                myDate.printDateOnConsole();
                break;
            case 3:
                myDate.acceptDateFromConsole();
                break;
            case 4:
                if (myDate.isLeapYear()) {
                    cout << myDate.year << " is a leap year." << endl;
                } else {
                    cout << myDate.year << " is not a leap year." << endl;
                }
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}