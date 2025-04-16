#include <iostream>
#include <string>
#include "Module.h"
#include "ModuleManager.h"

using namespace std;

void adminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Manage Modules\n";
    cout << "2. View Modules\n";
    cout << "9. Logout\n";
}

void studentMenu() {
    cout << "\n--- Student Menu ---\n";
    cout << "1. View Timetable\n";
    cout << "2. Search Timetable\n";
    cout << "3. Export to CSV\n";
    cout << "4. Logout\n";
}

int main() {
    string username, role;
    int choice;

    ModuleManager moduleManager;

    cout << "Welcome to NTU Timetabling System\n";
    cout << "Enter username: ";
    cin >> username;

    // Very basic login simulation
    if (username == "admin") {
        role = "admin";
    } else {
        role = "student";
    }

    while (true) {
        if (role == "admin") {
            adminMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // clear input buffer

            switch (choice) {
                case 1:
                    moduleManager.addModule();
                    break;
                case 2:
                    moduleManager.viewModules();
                    break;
                case 9:
                    cout << "Logging out...\n";
                    return 0;
                default:
                    cout << "Invalid option.\n";
            }
        } else {
            studentMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 4) {
                cout << "Logging out...\n";
                return 0;
            } else {
                cout << "Feature coming soon!\n";
            }
        }
    }

    return 0;
}
