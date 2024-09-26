#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int Roll_No;
    string Student_Name;
    string Class;

    // Static data member to count the number of students
    static int studentCount;

public:
    // Constructor
    Student() {
        Roll_No = 0;
        Student_Name = "";
        Class = "";
    }

    // Member function to accept student information
    void acceptInfo() {
        cout << "Enter Roll Number: ";
        cin >> Roll_No;
        cin.ignore(); // To ignore the newline character after integer input
        cout << "Enter Student Name: ";
        getline(cin, Student_Name);
        cout << "Enter Class: ";
        getline(cin, Class);
        
        // Increment the student count
        studentCount++;
    }

    // Member function to display student information
    void displayInfo() const {
        cout << "Roll Number: " << Roll_No << endl;
        cout << "Student Name: " << Student_Name << endl;
        cout << "Class: " << Class << endl;
    }

    // Static member function to get the count of students
    static int getStudentCount() {
        return studentCount;
    }
};

// Initialize the static member
int Student::studentCount = 0;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student* students = new Student[n]; // Dynamically allocate array of students

    // Accept information for each student
    for (int i = 0; i < n; i++) {
        cout << "\nEntering details for Student " << (i + 1) << endl;
        students[i].acceptInfo();
    }

    // Display information for each student
    cout << "\nStudent Information:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nDetails of Student " << (i + 1) << ":" << endl;
        students[i].displayInfo();
    }

    // Display the total count of students
    cout << "\nTotal number of students: " << Student::getStudentCount() << endl;

    delete[] students; // Free dynamically allocated memory
    return 0;
}
