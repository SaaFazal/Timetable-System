#include "LecturerManager.h"
#include <iostream>
#include "File.h"
#include <sstream>

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
void LecturerManager::editLecturer() {
    if (lecturers.empty()) {
        cout << "\nNo lecturers to edit.\n";
        return;
    }

    string id;
    cout << "Enter Lecturer ID to edit: ";
    getline(cin >> ws, id);

    for (auto& l : lecturers) {
        if (l.getID() == id) {
            string newName;
            cout << "Enter new name: ";
            getline(cin, newName);
            l = Lecturer(id, newName);
            cout << "Lecturer updated successfully!\n";
            return;
        }
    }

    cout << "Lecturer not found.\n";
}

void LecturerManager::deleteLecturer() {
    if (lecturers.empty()) {
        cout << "\nNo lecturers to delete.\n";
        return;
    }

    string id;
    cout << "Enter Lecturer ID to delete: ";
    getline(cin >> ws, id);

    for (auto it = lecturers.begin(); it != lecturers.end(); ++it) {
        if (it->getID() == id) {
            lecturers.erase(it);
            cout << "Lecturer deleted successfully.\n";
            return;
        }
    }

    cout << "Lecturer not found.\n";
}
void LecturerManager::saveToFile(const std::string& filename) const {
    File::saveCSV<Lecturer>(filename, lecturers, [](const Lecturer& l) {
        return l.getID() + "," + l.getName();
    });
}

void LecturerManager::loadFromFile(const std::string& filename) {
    File::loadCSV<Lecturer>(filename, lecturers, [](const std::string& line) {
        std::stringstream ss(line);
        std::string id, name;
        getline(ss, id, ',');
        getline(ss, name, ',');
        return Lecturer(id, name);
    });
}