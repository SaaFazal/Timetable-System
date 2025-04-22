#include "TimetableManager.h"
#include <iostream>
#include <fstream>
#include "File.h"
#include <sstream>

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
    
    TimetableEntry entry(week, group, module, lecturer, room, sessionType, day, time);

    if (hasConflict(entry)) {
    cout << "Conflict detected! Entry not added.\n";
    return;
    }

    entries.push_back(entry);
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
bool TimetableManager::hasConflict(const TimetableEntry& newEntry) const {
    for (const auto& e : entries) {
        if (
            e.getWeek() == newEntry.getWeek() &&
            e.getDay() == newEntry.getDay() &&
            e.getTime() == newEntry.getTime() &&
            (
                e.getGroup() == newEntry.getGroup() ||
                e.getLecturer() == newEntry.getLecturer() ||
                e.getRoom() == newEntry.getRoom()
            )
        ) {
            return true;
        }
    }
    return false;
}
void TimetableManager::exportTimetableToCSV() const {
    if (entries.empty()) {
        cout << "No timetable entries to export.\n";
        return;
    }

    ofstream outFile("timetable_export.csv");

    if (!outFile) {
        cout << "Failed to create CSV file.\n";
        return;
    }

    outFile << "Week,Group,Module,Lecturer,Room,Session Type,Day,Time\n";

    for (const auto& e : entries) {
        outFile << e.getWeek() << ","
                << e.getGroup() << ","
                << e.getModule() << ","
                << e.getLecturer() << ","
                << e.getRoom() << ","
                << e.getSessionType() << ","
                << e.getDay() << ","
                << e.getTime() << "\n";
    }

    outFile.close();
    cout << "Timetable exported to 'timetable_export.csv'!\n";
}
void TimetableManager::saveToFile(const std::string& filename) const {
    File::saveCSV<TimetableEntry>(filename, entries, [](const TimetableEntry& e) {
        return std::to_string(e.getWeek()) + "," + e.getGroup() + "," +
               e.getModule() + "," + e.getLecturer() + "," + e.getRoom() + "," +
               e.getSessionType() + "," + e.getDay() + "," + e.getTime();
    });
}

void TimetableManager::loadFromFile(const std::string& filename) {
    File::loadCSV<TimetableEntry>(filename, entries, [](const std::string& line) {
        std::stringstream ss(line);
        int week;
        std::string weekStr, group, module, lecturer, room, session, day, time;

        getline(ss, weekStr, ',');
        week = std::stoi(weekStr);
        getline(ss, group, ',');
        getline(ss, module, ',');
        getline(ss, lecturer, ',');
        getline(ss, room, ',');
        getline(ss, session, ',');
        getline(ss, day, ',');
        getline(ss, time, ',');

        return TimetableEntry(week, group, module, lecturer, room, session, day, time);
    });
}
void TimetableManager::viewTimetableByGroupAndWeek(const string& group, int week) const {
    cout << "\n--- Timetable for Group: " << group << " Week: " << week << " ---\n";
    bool found = false;
    for (const auto& e : entries) {
        if (e.getGroup() == group && e.getWeek() == week) {
            e.display();
            cout << "----------------------\n";
            found = true;
        }
    }
    if (!found) cout << "No entries found.\n";
}

void TimetableManager::exportGroupTimetable(const string& group) const {
    ofstream outFile("timetable_" + group + ".csv");
    if (!outFile) {
        cout << "Failed to create CSV.\n";
        return;
    }

    outFile << "Week,Module,Lecturer,Room,Session Type,Day,Time\n";

    for (const auto& e : entries) {
        if (e.getGroup() == group) {
            outFile << e.getWeek() << ","
                    << e.getModule() << ","
                    << e.getLecturer() << ","
                    << e.getRoom() << ","
                    << e.getSessionType() << ","
                    << e.getDay() << ","
                    << e.getTime() << "\n";
        }
    }

    outFile.close();
    cout << "Exported timetable to timetable_" << group << ".csv\n";
}
void TimetableManager::searchTimetableByGroup(const string& group) const {
    if (entries.empty()) {
        cout << "No timetable data available.\n";
        return;
    }

    cout << "\nSearch by:\n";
    cout << "1. Module\n2. Lecturer\n3. Room\nChoose an option: ";
    int option;
    cin >> option;
    cin.ignore();

    string query;
    cout << "Enter keyword: ";
    getline(cin, query);

    bool found = false;
    for (const auto& e : entries) {
        if (e.getGroup() != group) continue;

        bool match = false;
        switch (option) {
            case 1: match = e.getModule().find(query) != string::npos; break;
            case 2: match = e.getLecturer().find(query) != string::npos; break;
            case 3: match = e.getRoom().find(query) != string::npos; break;
            default: cout << "Invalid option.\n"; return;
        }

        if (match) {
            e.display();
            cout << "----------------------\n";
            found = true;
        }
    }

    if (!found) cout << "No matching entries found.\n";
}
