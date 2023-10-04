#include <iostream>
using namespace std;

class Factorial
{
private:
    int num1;
    float fact;

public:
    Factorial()
    {
        this->num1 = 1;
        this->fact = 1;
    }
    Factorial(int num1, float fact)
    {
        this->num1 = num1;
        this->fact = fact;
    }
    void acceptNumber()
    {
        cout << "Enter the Number = ";
        cin >> num1;
    }
    void factorial()
    {
        if (num1 < 0)
        {
            throw 2.0f;
        }
        for (int i = 1; i <= num1; i++)
        {
            fact = fact * i;
        }
    }
    void displayFactorial()
    {
        cout << "Factorial of " << num1 << " is = " << fact << endl;
    }
};
int main()
{
    Factorial f1;
    f1.acceptNumber();
    try
    {
        f1.factorial();
        f1.displayFactorial();
    }
    catch (float e)
    {
        cout << "Entered Number is Negitive" << endl;
    }
}
