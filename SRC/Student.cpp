#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {}

Student::Student(string id, string name, string group)
    : studentID(id), name(name), group(group) {}

string Student::getID() const { return studentID; }
string Student::getName() const { return name; }
string Student::getGroup() const { return group; }

void Student::display() const {
    cout << "Student ID: " << studentID << endl;
    cout << "Name: " << name << endl;
    cout << "Group: " << group << endl;
}
