#include <iostream>
#include <string>
#include "Module.h"
#include "ModuleManager.h"
#include "StudentManager.h"
#include "LecturerManager.h"
#include "RoomManager.h"
#include "TimetableManager.h"
#include "File.h"

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

    cout << "\n-- Timetable Management --\n";
    cout << "17. Add Timetable Entry\n";
    cout << "18. View Timetable (Group + Week)\n";

    cout << "19. Export Timetable to CSV\n";

    cout << "\n-- System --\n";
    cout << "20. Logout\n";

    cout << "================================\n";
}



void studentMenu() {
    cout << "\n========== Student Menu ==========\n";
    cout << "1. View Timetable\n";
    cout << "2. Search Timetable\n";
    cout << "3. Export to CSV\n";
    cout << "4. Logout\n";
    cout << "================================\n";
}

int main() {
    string username, role;
    int choice;
    string studentGroup;

    ModuleManager moduleManager;
    StudentManager studentManager;
    LecturerManager lecturerManager;
    RoomManager roomManager;
    TimetableManager timetableManager;
    moduleManager.loadFromFile("data_modules.csv");
    studentManager.loadFromFile("data_students.csv");
    lecturerManager.loadFromFile("data_lecturers.csv");
    roomManager.loadFromFile("data_rooms.csv");
    timetableManager.loadFromFile("data_timetable.csv");


    cout << "Welcome to NTU Timetabling System\n";
    while (true) {
        cout << "Enter username: ";
        cin >> username;
    
        if (username == "admin") {
            string password;
            cout << "Enter password: ";
            cin >> password;
        
            if (password == "admin123") {
                role = "admin";
                break;
            } else {
                cout << "Incorrect password.\n";
                continue;
            }
        }
        
        else if (username == "student") {
            role = "student";
            cout << "Enter your group name: ";
            cin >> studentGroup; 
            break;
        } else {
            cout << "Invalid username. Try again.\n";
        }
    }
    

    while (true) {
        if (role == "admin") {
            adminMenu();
    cout << "Enter your choice: ";
    if (!(cin >> choice)) {
    cout << "Invalid input. Please enter a number.\n";
    cin.clear();
    cin.ignore(1000, '\n');
    continue;
}
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
                case 17: timetableManager.addTimetableEntry(); break;
                case 18: timetableManager.viewTimetableByGroupAndWeek(); break;
                case 19:
                    timetableManager.exportTimetableToCSV();
                    break;
                case 20: cout << "Logging out and saving data...\n";
                moduleManager.saveToFile("data_modules.csv");
                studentManager.saveToFile("data_students.csv");
                lecturerManager.saveToFile("data_lecturers.csv");
                roomManager.saveToFile("data_rooms.csv");
                timetableManager.saveToFile("data_timetable.csv");
                return 0;
                default:
                    cout << "Invalid option.\n";
            }
            
            
        } else {
            studentMenu();
            cout << "Enter your choice: ";
            if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
            }
            cin.ignore();

            switch (choice) {
                case 1: {
                    int week;
                    cout << "Enter week number: ";
                    cin >> week;
                    timetableManager.viewTimetableByGroupAndWeek(studentGroup, week);
                    break;
                }
                case 2:
                    timetableManager.searchTimetableByGroup(studentGroup);
                    break;

                case 3:
                    timetableManager.exportGroupTimetable(studentGroup);
                    break;
            
                case 4:
                cout << "Logging out and saving data...\n";
                moduleManager.saveToFile("data_modules.csv");
                studentManager.saveToFile("data_students.csv");
                lecturerManager.saveToFile("data_lecturers.csv");
                roomManager.saveToFile("data_rooms.csv");
                timetableManager.saveToFile("data_timetable.csv");
            return 0;
            default:
            cout << "Invalid option.\n";
            }

        }
    }
    return 0;
}