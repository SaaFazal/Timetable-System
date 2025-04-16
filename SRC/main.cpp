#include <iostream>
#include <string>
#include "Module.h"

using namespace std;

void adminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Manage Modules\n";
    cout << "2. Manage Groups\n";
    cout << "3. Manage Sessions\n";
    cout << "4. Manage Students\n";
    cout << "5. Manage Lecturers\n";
    cout << "6. Manage Rooms\n";
    cout << "7. Create/Update Timetable\n";
    cout << "8. Search Timetable Conflicts\n";
    cout << "9. Logout\n";
}

void studentMenu() {
    cout << "\n--- Student Menu ---\n";
    cout << "1. View Timetable\n";
    cout << "2. Search Timetable\n";
    cout << "3. Export Timetable to CSV\n";
    cout << "4. Logout\n";
}

int main() {
    string username, role;
    
    cout << "Welcome to NTU Timetabling System\n";
    cout << "Enter username: ";
    cin >> username;

    // Basic login simulation
    if (username == "admin") {
        role = "admin";
    } else {
        role = "student";
    }

    int choice;
    while (true) {
        if (role == "admin") {
            adminMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 9) break;
            // Call admin functions here
        } else {
            studentMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 4) break;
            // Call student functions here
        }
    }
    Module m("CS2001", "Data Structures", "Dr. Smith", "Group A", "Lecture", "Monday", "10 AM", "MAE 202");
    m.display();
    cout << "Logged out successfully.\n";
    return 0;
}
