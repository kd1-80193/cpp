#include <iostream>

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    // Constructors
    Time() : hour(0), minute(0), second(0) {}
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Getters
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

    // Setters
    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s; }

    // Print the time
    void printTime() const
    {
        std::cout << hour << ":" << minute << ":" << second << std::endl;
    }
};

int main()
{
    int numObjects;
    std::cout << "Enter the number of Time objects to create: ";
    std::cin >> numObjects;

    // Dynamically allocate an array of Time objects
    Time *timeArray = new Time[numObjects];

    // Initialize and print the Time objects
    for (int i = 0; i < numObjects; i++)
    {
        int h, m, s;
        std::cout << "Enter time for object " << i + 1 << " (hh mm ss): ";
        std::cin >> h >> m >> s;
        timeArray[i] = Time(h, m, s);
    }

    std::cout << "Time objects created:" << std::endl;
    for (int i = 0; i < numObjects; i++)
    {
        std::cout << "Object " << i + 1 << ": ";
        timeArray[i].printTime();
    }

    // Deallocate the dynamically allocated memory
    delete[] timeArray;

    return 0;
}
