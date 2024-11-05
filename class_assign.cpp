#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    string parentName;
    string regNo;
    int age;
    int semester;
    int rollNumber;
    int classesAttended;
    float marks[5];
    int totalClasses = 30;

public:
    void getDetails()
    {
        cout << "Enter student's name: ";
        cin >> name;

        cout << "Enter parent's name: ";
        cin >> parentName;

        cout << "Enter registration number: ";
        cin >> regNo;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter semester: ";
        cin >> semester;

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter classes attended (out of 30): ";
        cin >> classesAttended;

        cout << "Enter marks for 5 subjects:" <<endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void showDetails()
    {
        cout << "Roll No: "<<endl << rollNumber << "Name: "<< endl << name << "Parent's Name: "<<endl << parentName
             << "Registration Number: " <<endl << regNo << "Age: " <<endl << age << "Semester: "<<endl << semester
             << "Classes Attended: " <<endl << classesAttended << "/" << totalClasses << "Marks: " <<endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    float getAttendancePercentage()
    {
        return (classesAttended * 100) / totalClasses;
    }

    void printAttendance()
    {
        cout << "Roll No: " << rollNumber << ", Name: " << name << ", Attendance: " << getAttendancePercentage() << "%" << endl;
    }

    void checkAttendanceShortage()
    {
        if (getAttendancePercentage() < 75)
        {
            cout << "Roll No: " << rollNumber << ", Name: " << name << " has attendance shortage."  <<endl;
        }
        else
        {
            cout << "Roll No: " << rollNumber << ", Name: " << name << " has sufficient attendance." <<endl;
        }
    }

    float getAverageMarks()
    {
        float total = 0;
        for (int i = 0; i < 5; ++i)
        {
            total += marks[i];
        }
        return total / 5;
    }

    
    void checkHighAverageMarks()
    {
        if (getAverageMarks() >= 90)
        {
            cout << "Roll No: " << rollNumber << ", Name: " << name
                 << ", Average Marks: " << getAverageMarks() << " (90% or above)" <<endl;
        }
    }

    
    int getRollNumber() { return rollNumber; }
    string getName() { return name; }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];

    //  To show input details for each student.
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter details for student " << i + 1 << ":" <<endl;
        students[i].getDetails();
    }

    // To show details of all students.
    cout << "Details of all students:" <<endl;
    for (int i = 0; i < n; ++i)
    {
        students[i].showDetails();
    }

    //  To show attendance of all students.
    cout << "Attendance of all students:" <<endl;
    for (int i = 0; i < n; ++i)
    {
        students[i].printAttendance();
    }

    // For Checking attendance shortage for each student
    cout << "Checking attendance shortage (< 75%):" <<endl;
    for (int i = 0; i < n; ++i)
    {
        students[i].checkAttendanceShortage();
    }

    // for showing students with 90% or more average marks
    cout << "Students with 90% or more average marks:" <<endl;
    for (int i = 0; i < n; ++i)
    {
        students[i].checkHighAverageMarks();
    }

    return 0;
}
