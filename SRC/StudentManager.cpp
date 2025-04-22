#include "StudentManager.h"
#include <iostream>
#include "File.h"
#include <sstream>


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

void StudentManager::editStudent() {
    if (students.empty()) {
        cout << "\nNo students to edit.\n";
        return;
    }

    string id;
    cout << "Enter Student ID to edit: ";
    getline(cin >> ws, id);

    for (auto& s : students) {
        if (s.getID() == id) {
            string newName, newGroup;
            cout << "Enter new name: ";
            getline(cin, newName);
            cout << "Enter new group: ";
            getline(cin, newGroup);
            s = Student(id, newName, newGroup);
            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void StudentManager::deleteStudent() {
    if (students.empty()) {
        cout << "\nNo students to delete.\n";
        return;
    }

    string id;
    cout << "Enter Student ID to delete: ";
    getline(cin >> ws, id);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getID() == id) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void StudentManager::saveToFile(const std::string& filename) const {
    File::saveCSV<Student>(filename, students, [](const Student& s) {
        return s.getID() + "," + s.getName() + "," + s.getGroup();
    });
}

void StudentManager::loadFromFile(const std::string& filename) {
    File::loadCSV<Student>(filename, students, [](const std::string& line) {
        std::stringstream ss(line);
        std::string id, name, group;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, group, ',');
        return Student(id, name, group);
    });
}