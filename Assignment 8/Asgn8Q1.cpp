#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inch;

public:
    Distance()
    {
        this->feet = 0;
        this->inch = 0;
    }

    Distance(int feet, int inch)
    {
        this->feet = feet;
        this->inch = inch;
    }

    Distance operator+(Distance d1)
    {
        Distance result;
        result.feet = this->feet + d1.feet;
        result.inch = this->inch + d1.inch;
        return result;
    }

    void operator++()
    {
        this->feet = this->feet + 1;
        this->inch = this->inch + 1;
    }

    friend bool operator==(Distance d1, Distance d2);
    friend void operator--(Distance &d1);
    friend void operator<<(ostream &print, Distance d1);
    friend void operator>>(istream &input, Distance &d1);
};

bool operator==(Distance d1, Distance d2)
{
    if (d1.inch == d2.inch && d1.feet == d2.feet)
        return true;
    return false;
}

void operator--(Distance &d1)
{
    d1.feet = d1.feet - 1;
    d1.inch = d1.inch - 1;
}

void operator<<(ostream &print, Distance d1)
{
    print << "(Feet,Inch) : (" << d1.feet << "," << d1.inch << ")" << endl;
}

void operator>>(istream &input, Distance &d1)
{
    cout << "Enter No. of Feet: \t";
    input >> d1.feet;
    cout << "Enter No. of Inch: \t";
    input >> d1.inch;
}

int main()
{
    Distance d1(1, 12);
    cout << d1;
    cin >> d1;
    cout << d1;
    ++d1;
    cout << d1;
    --d1;
    cout << d1;
    if (d1 == Distance(1, 1))
        cout << "Both distances are same." << endl;
    else
        cout << "Both distances are different." << endl;

    return 0;
}