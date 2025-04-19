#include <iostream>
#include <string>
#include "Module.h"
#include "ModuleManager.h"
#include "StudentManager.h"
#include "LecturerManager.h"
#include "RoomManager.h"

using namespace std;

void adminMenu() {
    cout << "\n========== Admin Menu ==========\n";

    cout << "\n-- Module Management --\n";
    cout << "1. Add Module\n";
    cout << "2. View Modules\n";
    cout << "3. Edit Module\n";
    cout << "4. Delete Module\n";

    cout << "\n-- Student Management --\n";
    cout << "5. Add Student\n";
    cout << "6. View Students\n";
    cout << "7. Edit Student\n";
    cout << "8. Delete Student\n";

    cout << "\n-- Lecturer Management --\n";
    cout << "9. Add Lecturer\n";
    cout << "10. View Lecturers\n";
    cout << "11. Edit Lecturer\n";
    cout << "12. Delete Lecturer\n";

    cout << "\n-- Room Management --\n";
    cout << "13. Add Room\n";
    cout << "14. View Rooms\n";
    cout << "15. Edit Room\n";
    cout << "16. Delete Room\n";

    cout << "\n-- System --\n";
    cout << "17. Logout\n";

    cout << "================================\n";
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
    StudentManager studentManager;
    LecturerManager lecturerManager;
    RoomManager roomManager;



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
                case 1: moduleManager.addModule(); break;
                case 2: moduleManager.viewModules(); break;
                case 3: moduleManager.editModule(); break;
                case 4: moduleManager.deleteModule(); break;
                case 5: studentManager.addStudent(); break;
                case 6: studentManager.viewStudents(); break;
                case 7: studentManager.editStudent(); break;
                case 8: studentManager.deleteStudent(); break;
                case 9: lecturerManager.addLecturer(); break;
                case 10: lecturerManager.viewLecturers(); break;
                case 11: lecturerManager.editLecturer(); break;
                case 12: lecturerManager.deleteLecturer(); break;
                case 13: roomManager.addRoom(); break;
                case 14: roomManager.viewRooms(); break;
                case 15: roomManager.editRoom(); break;
                case 16: roomManager.deleteRoom(); break;
                case 17: cout << "Logging out...\n"; return 0;
                     
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
