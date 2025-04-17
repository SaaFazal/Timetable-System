#include "StudentManager.h"
#include <iostream>

using namespace std;

void StudentManager::addStudent() {
    string id, name, group;

    cout << "\n--- Add New Student ---\n";
    cout << "Enter Student ID: ";
    getline(cin >> ws, id);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Group: ";
    getline(cin, group);

    Student s(id, name, group);
    students.push_back(s);

    cout << "Student added successfully!\n";
}

void StudentManager::viewStudents() const {
    cout << "\n--- All Students ---\n";
    if (students.empty()) {
        cout << "No students found.\n";
    } else {
        for (const Student& s : students) {
            s.display();
            cout << "-----------------------\n";
        }
    }
}
