#include <iostream>

using namespace std;

class TollBooth {
private:
    unsigned int totalCars;
    double totalMoney;

public:
    // Constructor to initialize data members
    TollBooth() : totalCars(0), totalMoney(0.0) {}

    // Function to handle paying cars
    void payingCar() {
        totalCars++;
        totalMoney += 0.50;
    }

    // Function to handle non-paying cars
    void nopayCar() {
        totalCars++;
    }

    // Function to display the totals
    void printOnConsole() {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Money Collected: $" << totalMoney << endl;
        cout << "Paying Cars: " << totalMoney / 0.50 << endl;
        cout << "Non-paying Cars: " << totalCars - (totalMoney / 0.50) << endl;
    }
};

int main() {
    TollBooth booth;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Car Paid" << endl;
        cout << "2. Car Didn't Pay" << endl;
        cout << "3. Display Totals" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                booth.payingCar();
                cout << "Car paid the toll of $0.50." << endl;
                break;

            case 2:
                booth.nopayCar();
                cout << "Car didn't pay the toll." << endl;
                break;

            case 3:
                booth.printOnConsole();
                break;

            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
