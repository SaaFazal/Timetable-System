#include "ModuleManager.h"
#include <iostream>

using namespace std;

void ModuleManager::addModule() {
    string code, name, lecturer, group, session, day, time, room;

    cout << "\n--- Add New Module ---\n";
    cout << "Enter Module Code: ";
    getline(cin >> ws, code);  // ws clears leading whitespace
    cout << "Enter Module Name: ";
    getline(cin, name);
    cout << "Enter Lecturer Name: ";
    getline(cin, lecturer);
    cout << "Enter Group Name: ";
    getline(cin, group);
    cout << "Enter Session Type (Lecture/Lab): ";
    getline(cin, session);
    cout << "Enter Day: ";
    getline(cin, day);
    cout << "Enter Time: ";
    getline(cin, time);
    cout << "Enter Room: ";
    getline(cin, room);

    Module m(code, name, lecturer, group, session, day, time, room);
    modules.push_back(m);

    cout << "\nModule added successfully!\n";
}

void ModuleManager::viewModules() const {
    cout << "\n--- All Modules ---\n";
    if (modules.empty()) {
        cout << "No modules available.\n";
    } else {
        for (const Module& m : modules) {
            m.display();
            cout << "-----------------------\n";
        }
    }
}

void ModuleManager::editModule() {
    if (modules.empty()) {
        cout << "\nNo modules available to edit.\n";
        return;
    }

    string code;
    cout << "\nEnter Module Code to edit: ";
    getline(cin >> ws, code);

    bool found = false;
    for (auto& m : modules) {
        if (m.getModuleCode() == code) {
            found = true;

            string newName, newLecturer, newGroup, newSession, newDay, newTime, newRoom;

            cout << "Enter new Module Name: ";
            getline(cin, newName);
            cout << "Enter new Lecturer: ";
            getline(cin, newLecturer);
            cout << "Enter new Group: ";
            getline(cin, newGroup);
            cout << "Enter new Session Type: ";
            getline(cin, newSession);
            cout << "Enter new Day: ";
            getline(cin, newDay);
            cout << "Enter new Time: ";
            getline(cin, newTime);
            cout << "Enter new Room: ";
            getline(cin, newRoom);

            // Replace the module entirely
            m = Module(code, newName, newLecturer, newGroup, newSession, newDay, newTime, newRoom);

            cout << "\nModule updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Module not found.\n";
    }
}
void ModuleManager::deleteModule() {
    if (modules.empty()) {
        cout << "\nNo modules available to delete.\n";
        return;
    }

    string code;
    cout << "\nEnter Module Code to delete: ";
    getline(cin >> ws, code);

    for (auto it = modules.begin(); it != modules.end(); ++it) {
        if (it->getModuleCode() == code) {
            modules.erase(it);
            cout << "Module deleted successfully.\n";
            return;
        }
    }

    cout << "Module not found.\n";
}
