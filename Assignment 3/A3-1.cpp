#include <iostream>

using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Default constructor
    Box() : length(0.0), width(0.0), height(0.0) {}

    // Parameterized constructor
    Box(double l, double w, double h) : length(l), width(w), height(h) {}

    // Function to calculate and return the volume of the box
    double calculateVolume() {
        return length * width * height;
    }
};

int main() {
    int choice;
    double length, width, height;
    Box box; // Declare the Box object outside the switch statement

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Calculate Volume" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the length, width, and height of the box: ";
                cin >> length >> width >> height;

                // Update the Box object using the parameterized constructor
                box = Box(length, width, height);

                // Calculate and display the volume
                cout << "Volume of the box: " << box.calculateVolume() << endl;
                break;

            case 2:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
