#include "TimetableManager.h"
#include <iostream>

using namespace std;

void TimetableManager::addTimetableEntry() {
    int week;
    string group, module, lecturer, room, sessionType, day, time;

    cout << "\n--- Add Timetable Entry ---\n";
    cout << "Enter Week Number (1–53): ";
    cin >> week;
    cin.ignore();
    cout << "Enter Group: ";
    getline(cin, group);
    cout << "Enter Module Name: ";
    getline(cin, module);
    cout << "Enter Lecturer Name: ";
    getline(cin, lecturer);
    cout << "Enter Room: ";
    getline(cin, room);
    cout << "Enter Session Type (Lecture/Lab): ";
    getline(cin, sessionType);
    cout << "Enter Day: ";
    getline(cin, day);
    cout << "Enter Time (e.g. 10 AM): ";
    getline(cin, time);

    entries.push_back(TimetableEntry(week, group, module, lecturer, room, sessionType, day, time));
    cout << "Timetable entry added successfully!\n";
}

void TimetableManager::viewTimetableByGroupAndWeek() {
    if (entries.empty()) {
        cout << "No timetable entries available.\n";
        return;
    }

    int week;
    string group;
    cout << "\nEnter Group: ";
    getline(cin >> ws, group);
    cout << "Enter Week Number: ";
    cin >> week;

    cout << "\n--- Timetable for Group " << group << ", Week " << week << " ---\n";

    bool found = false;
    for (const TimetableEntry& e : entries) {
        if (e.getGroup() == group && e.getWeek() == week) {
            e.display();
            cout << "---------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No entries found for that group and week.\n";
    }
}
