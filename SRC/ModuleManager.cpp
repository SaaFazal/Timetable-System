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
