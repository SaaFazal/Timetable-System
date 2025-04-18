#include "LecturerManager.h"
#include <iostream>

using namespace std;

void LecturerManager::addLecturer(){
    string id, name;

    cout << "\n Add New Lecturer \n";
    cout << " Enter Lecturer ID: ";
    getline(cin >> ws, id);
    cout << " Enter Name: ";
    getline(cin, name);

    lecturers.push_back(Lecturer(id, name));
    cout << "Lecturer Added Successfully\n";
}

void LecturerManager::viewLecturers() const {
    cout << "\n---------All Lecturers---------\n";
    if (lecturers.empty()){
        cout << "No Lecturers Found. \n";
    }
    else {
        for (const auto& l : lecturers) {
            l.display();
            cout << "--------------\n";
        }
    }
}