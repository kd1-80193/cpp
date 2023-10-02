#include <iostream>
#include <iomanip>

using namespace std;

class Cylinder {
private:
    double radius;
    double height;

public:
    // Constructor with member initializer list
    Cylinder() : radius(0.0), height(0.0) {}

    // Parameterized constructor
    Cylinder(double r, double h) : radius(r), height(h) {}

    // Getter for radius
    double getRadius() {
        return radius;
    }

    // Setter for radius
    void setRadius(double r) {
        radius = r;
    }

    // Getter for height
    double getHeight() {
        return height;
    }

    // Setter for height
    void setHeight(double h) {
        height = h;
    }

    // Calculate and return the volume of the cylinder
    double getVolume() {
        return 3.14 * radius * radius * height;
    }

    // Print the volume of the cylinder
    void printVolume() {
        cout << "Volume of the cylinder: " << fixed << setprecision(2) << getVolume() << endl;
    }
};

int main() {
    Cylinder cyl;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Set Radius" << endl;
        cout << "2. Set Height" << endl;
        cout << "3. Calculate Volume" << endl;
        cout << "4. Print Volume" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                double newRadius;
                cout << "Enter the radius: ";
                cin >> newRadius;
                cyl.setRadius(newRadius);
                break;

            case 2:
                double newHeight;
                cout << "Enter the height: ";
                cin >> newHeight;
                cyl.setHeight(newHeight);
                break;

            case 3:
                cout << "Volume calculated." << endl;
                break;

            case 4:
                cyl.printVolume();
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
