
#include <iostream>

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    void printDateOnConsole()
    {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }

    void acceptDateFromConsole()
    {
        std::cout << "Enter day: ";
        std::cin >> day;
        std::cout << "Enter month: ";
        std::cin >> month;
        std::cout << "Enter year: ";
        std::cin >> year;
    }

    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Date date;
    int choice;

    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Initialize Date" << std::endl;
        std::cout << "2. Print Date" << std::endl;
        std::cout << "3. Accept Date from Console" << std::endl;
        std::cout << "4. Check if Leap Year" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            date.initDate();
            std::cout << "Date initialized." << std::endl;
            break;
        case 2:
            date.printDateOnConsole();
            break;
        case 3:
            date.acceptDateFromConsole();
            break;
        case 4:
            if (date.isLeapYear())
            {
                std::cout << "It's a leap year." << std::endl;
            }
            else
            {
                std::cout << "It's not a leap year." << std::endl;
            }
            break;
        case 5:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 5);

    return 0;
}
