// #include<iostream>

// using namespace std;
// class Student
// {
//  private:
//  string name;
//  char gender;
//  int rollNo;
//  int marks1;
//  int marks2;
//  int marks3;
//  int total;
//  float per;
//  static int count;

//  public:
//  void acceptStudent()
//  {
//   ++count;
//   cout<<"2.Enter the name of student:"<<endl;
//   cin>>name;
//   cout<<"3.Enter the gender of student:"<<endl;
//   cin>>gender;
//   cout<<"3.Enter the Rollno. of student:"<<endl;
//   cin>>rollNo;
//   cout<<"3.Enter the marks of 1st sub student:"<<endl;
//   cin>>marks1;
//   cout<<"3.Enter the marks of 2nd sub student:"<<endl;
//   cin>>marks2;
//   cout<<"3.Enter the marks of 3rd sub student:"<<endl;
//   cin>>marks3;  
//  }
//  void displayStudent()
//  {
//   cout<<"Name:"<<name<<endl;
//   cout<<"Gender:"<<gender<<endl;
//   cout<<"Roll No.:"<<rollNo<<endl;
//   cout<<"Marks1:"<<marks1<<endl;
//   cout<<"Marks2:"<<marks2<<endl;
//   cout<<"Marks3:"<<marks3<<endl;
//   cout<<"Percentage:"<<calPer()<<endl;
//  }
//  float calPer()
//  {
//   total=marks1+marks2+marks3;
//   per=(total*100)/300;
//   return per;
//  }


// };
// int Student::count=0;
// int main()
// {
//   int size;
//   int choice; 
//   int key;
//   cout<<"Enter the no. of student data you want to store want:"<<endl;
//   cin>>size;
//   Student **arr=new Student *[size];
//   for (int i = 0; i < size; i++)
//   {
//     arr[i]=new Student();
//     arr[i]->acceptStudent();
//     arr[i]->displayStudent();
//   }
//  /* do
//   {
//     cout<<"select\n 1.To give input for no. of student whose data you want store"<<endl;   
//   cin>>choice;
//   } while (choice!=0);*/

//   //linearSearch(arr,size);
//   cout<<"Enter rollno. to find:"<<endl;
//   cin>>key;
//   for (int i = 0; i < size; i++)
//   {
//      delete arr[i];
//   }

//   delete[] arr;
//   return 0;

// }
// /*int linearSearch(Student **ptr,int size)
// {


// }*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    string gender;
    int rollNumber;
    float marks[3];
    float percentage;

    void calculatePercentage() {
        float totalMarks = 0;
        for (int i = 0; i < 3; i++) {
            totalMarks += marks[i];
        }
        percentage = (totalMarks / 3.0);
    }

    void inputStudent() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Marks for 3 subjects:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }

        calculatePercentage();
    }

    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
    }
};

void sortRecords(Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].percentage < arr[j + 1].percentage) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int searchRecords(Student arr[], int size, int rollNumber) {
    for (int i = 0; i < size; i++) {
        if (arr[i].rollNumber == rollNumber) {
            return i; // Found the student
        }
    }
    return -1; // Student not found
}

int main() {
    int choice;
    const int maxSize = 100;
    Student studentArray[maxSize];
    int numStudents = 0;
    int index; // Declare index here

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Sort Students by Percentage\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (numStudents < maxSize) {
                    studentArray[numStudents].inputStudent();
                    numStudents++;
                } else {
                    cout << "Maximum number of students reached." << endl;
                }
                break;
            case 2:
                for (int i = 0; i < numStudents; i++) {
                    studentArray[i].displayStudent();
                }
                break;
            case 3:
                int searchRollNumber;
                cout << "Enter Roll Number to Search: ";
                cin >> searchRollNumber;
                index = searchRecords(studentArray, numStudents, searchRollNumber); // Assign index here
                if (index != -1) {
                    studentArray[index].displayStudent();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            case 4:
                sortRecords(studentArray, numStudents);
                cout << "Students sorted by Percentage:" << endl;
                for (int i = 0; i < numStudents; i++) {
                    studentArray[i].displayStudent();
                }
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
