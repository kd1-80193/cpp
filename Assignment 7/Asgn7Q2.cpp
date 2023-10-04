#include <iostream>
using namespace std;
class Product
{
private:
    int id;
    string title;
    float price;
    char type;

public:
    Product()
    {
        this->id = 0;
        this->title = " ";
        this->price = 0;
        this->type = ' ';
    }
    Product(int id, string title, float price, char type)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->type = type;
    }
    void acceptProduct()
    {
        cout << "Enter product id: ";
        cin >> this->id;
        cout << "Enter product title: ";
        cin >> this->title;
        cout << "Enter product price: ";
        cin >> this->price;
        cout << "Enter product type:('B' or 'T') ";
        cin >> this->type;
    }
    void displayProduct()
    {
        cout << "Product id: " << this->id << endl;
        cout << "Product title: " << this->title << endl;
        cout << "Product price: " << this->price << endl;
        cout << "Product type: " << this->type << endl;
    }
    friend void calculateBill(Product *arr[3], int index);
};
class Book : public Product
{
private:
    string author;
    // Product p1;

public:
    Book()
    {
        this->author = "";
    }
    Book(string author)
    {
        this->author = author;
    }
    void acceptBook()
    {
        acceptProduct();
        cout << "Enter the Author name:";
        cin >> this->author;
    }
    void displayProduct()
    {
        displayProduct();
        cout << "Author name: " << this->author << endl;
    }
};
class Tape : public Product
{
private:
    string artist;
    // Product p2;

public:
    Tape()
    {
        this->artist = "";
    }
    Tape(string artist)
    {
        this->artist = artist;
    }
    void acceptTape()
    {
        acceptProduct();
        cout << "Enter the Artist name: ";
        cin >> this->artist;
    }
    void displayTape()
    {
        displayProduct();
        cout << "Artist name: " << this->artist << endl;
    }
};
void calculateBill(Product *arr[], int index)
{
    float totalBill = 0;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->type == 'B')
        {
            float discount = arr[i]->price * 0.1;
            float price = arr[i]->price - discount;
            totalBill = price + totalBill;
        }
        else
        {
            float discount = arr[i]->price * 0.05;
            float price = arr[i]->price - discount;
            totalBill = price + totalBill;
        }
    }
    cout<<"Total Ammount: "<<totalBill<<endl;
}
int menu()
{
    int choice;
    cout << "*****************************" << endl;
    cout << "0.EXIT." << endl;
    cout << "1.ACCEPT A BOOK." << endl;
    cout << "2.ACCEPT A TAPE." << endl;
    cout << "3.GENERATE BILL." << endl;
    cout << "4.DISPLAY PRODUCTS." << endl;
    cout << "Enter the choice: ";
    cin >> choice;
    cout << "*****************************" << endl;
    return choice;
}
int main()
{
    int choice;
    Product *arr[3];
    int index = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (index < 3)
            {
                arr[index] = new Book();
                arr[index]->acceptProduct();
                arr[index]->displayProduct();
                index++;
            }
            else
                cout << "Cart is full, cannot add Book to the cart." << endl;
            break;
        case 2:
            if (index < 3)
            {
                arr[index] = new Tape();
                arr[index]->acceptProduct();
                arr[index]->displayProduct();
                index++;
            }
            else
                cout << "Cart is full, cannot add Tape to the cart." << endl;
            break;
        case 3:
            calculateBill(arr,3);
            break;
        case 4:
            for (int i = 0; i < 3; i++)
            {
                arr[i]->displayProduct();
            }
            break;
            
        default:
        cout<<"wrong choice entered.."<<endl;
        }
    }
    cout<<"Thank you for visiting our shop.."<<endl;
    return 0;
}