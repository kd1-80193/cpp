#include <iostream>
using namespace std;
class Products
{
protected:
  int id;
  string title;
  float price = 0;
  string type;

public:
  virtual void accept()
  {
    cout << "Enter Product ID:" << endl;
    cin >> id;
    cout << "Enter Product title:" << endl;
    cin >> title;
    cout << "Enter Product type:" << endl;
    cin >> type;
  }
  void setPrice(float price)
  {
    this->price = price;
  }
  float getPrice()
  {
    return price;
  }
};
class Book : public Products
{
private:
  string author;
  float discount;

public:
  void accept()
  {
    cout << "----------------------------------------------------------" << endl;
    cout << "Enter book author name:" << endl;
    cin >> author;
    Products::accept();
    cout << "Enter price of book:" << endl;
    cin >> price;
    discount = (price / 100) * 10;
    price = price - discount;
    setPrice(price);
  }
};
class Tapes : public Products
{
private:
  string artist;
  float discount;

public:
  void accept()
  {
    cout << "----------------------------------------------------------" << endl;
    cout << "Enter tape artist name:" << endl;
    cin >> artist;
    Products::accept();
    cout << "Enter price of tape:" << endl;
    cin >> price;
    discount = (price / 100) * 5;
    price = price - discount;
    setPrice(price);
  }
};
int menu()
{
  int choice;
  cout << "----------------------------------------------------------" << endl;
  cout << "0. Exit" << endl;
  cout << "1. To purchase the book" << endl;
  cout << "2. To purchase the Tape" << endl;
  cout << "3.To calculate final bill" << endl;
  cout << "Enter Your Choice = ";
  cin >> choice;
  return choice;
}
int main()
{
  int choice;
  int index = 0;
  float total = 0;
  Products *arr[5];
  while ((choice = menu()) != 0)
  {
    switch (choice)
    {
    case 1:
      if (index < 3)
      {
        arr[index] = new Book();
        arr[index]->accept();
        index++;
      }
      else
        cout << "Your cart is full!!!" << endl;
      break;
    case 2:
      if (index < 3)
      {
        arr[index] = new Tapes();
        arr[index]->accept();
        index++;
      }
      else
        cout << "Your cart is full!!!" << endl;
      break;
    case 3:
      for (int i = 0; i < index; i++)
      {
        total = total + arr[i]->getPrice();
      }
      cout << "----------------------------------------------------------" << endl;
      cout << "Your total cart value :" << total << endl;
      total = 0;

    default:
      break;
    }
  }

  for (int i = 0; i < index; i++)
  {
    delete arr[i];
  }
  return 0;
}