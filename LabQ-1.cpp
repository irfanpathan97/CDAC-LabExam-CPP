#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

void addRecord() {
    Student student;
    cout << "Enter Student ID: ";
    cin >> student.id;
    cout << "Enter Student Name: ";
    cin >> student.name;
    cout << "Enter Student Age: ";
    cin >> student.age;

    ofstream outFile("students.dat", ios::app | ios::binary);
    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
    outFile.close();
    cout << "Record added successfully.\n";
}

void listRecords() {
    Student student;
    ifstream inFile("students.dat", ios::binary);
    
    cout << "Student Records:\n";
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << endl;
    }
    
    inFile.close();
}

void modifyRecord() {
    int id;
    cout << "Enter Student ID to modify: ";
    cin >> id;

    fstream file("students.dat", ios::in | ios::out | ios::binary);
    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.id == id) {
            found = true;
            cout << "Current Name: " << student.name << ", Current Age: " << student.age << endl;
            cout << "Enter new Name: ";
            cin >> student.name;
            cout << "Enter new Age: ";
            cin >> student.age;

            file.seekp(file.tellg() - sizeof(Student)); // Move the pointer back to update
            file.write(reinterpret_cast<char*>(&student), sizeof(Student));
            cout << "Record updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }

    file.close();
}

void deleteRecord() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    ifstream inFile("students.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.id != id) {
            outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Database Management System\n";
        cout << "1. Add Record\n";
        cout << "2. List Records\n";
        cout << "3. Modify Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                listRecords();
                break;
            case 3:
                modifyRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
