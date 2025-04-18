#include "Lecturer.h"
#include <iostream>

using namespace std;

Lecturer::Lecturer() {}

Lecturer::Lecturer(string id, string name)
    : lecturerID(id), name(name) {}

string Lecturer::getID() const { return lecturerID; }
string Lecturer::getName() const { return name; }

void Lecturer::display() const {
    cout << "Lecturer ID: " << lecturerID << endl;
    cout << "Name: " << name << endl;
}
