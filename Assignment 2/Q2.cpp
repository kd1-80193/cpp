/*Q2. Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
Instead of char[] use string datatype*/

#include <iostream>
using namespace std;
class Address
{
private:
    string building;
    string street;
    string city;
    int pin;

public:
    // Address()
    // {
    //     this->building =building;
    //     this->street = street;
    //     this->city = city;
    //     this->pin = pin;
    // }
    Address(string building="Gymkhana", string street="jm road", string city="pune", int pin=415410)
    {
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }
    void acceptAddress()
    {
        cout << "Enter the Address :- \n"
             << endl;

        cout << "Enter building name" << endl; //>> street >> city >> pin;
        cin >> building;
        cout << "Enter street name " << endl;
        cin >> street;
        cout << "Enter city name " << endl;
        cin >> city;
        cout << " Enter the pin " << endl;
        cin >> pin;
    }
    void dislpayAddress()
    {
        cout << "The address is :- " << endl;
        cout << building << " , " << street << " , " << city << " , " << pin<<endl;
    }
    void setBuilding(string building)
    {
        this->building = building;
    }
    string getBuilding()
    {
        return this->building;
    }
    void setStreet(string street)
    {
        this->street = street;
    }
    string getStreet()
    {
        return this->street;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return this->city;
    }
    void setPin(int pin)
    {
        this->pin = pin;
    }
    int getPin()
    {
        return this->pin;
    }
};

int main()
{
    Address a2("krishna nivas", "MG road", "karad", 415410);
    Address a1;
    // a1.acceptAddress();
    a1.dislpayAddress();
    a2.dislpayAddress();
    // cout << "\nBuilding  = " << a1.getBuilding() << endl;
    // cout << "Street = " << a1.getStreet() << endl;
    // cout << "City = " << a1.getCity() << endl;
    // cout << "Pin = " << a1.getPin() << endl;
}