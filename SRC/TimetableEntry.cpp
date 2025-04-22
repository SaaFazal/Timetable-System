#include "TimetableEntry.h"
#include <iostream>

using namespace std;

TimetableEntry::TimetableEntry() {}

TimetableEntry::TimetableEntry(int week, string group, string module, string lecturer,
                               string room, string sessionType, string day, string time)
    : weekNumber(week), group(group), module(module), lecturer(lecturer),
      room(room), sessionType(sessionType), day(day), time(time) {}

int TimetableEntry::getWeek() const { return weekNumber; }
string TimetableEntry::getGroup() const { return group; }
std::string TimetableEntry::getDay() const { return day;}

std::string TimetableEntry::getTime() const { return time; }

std::string TimetableEntry::getLecturer() const { return lecturer; }

std::string TimetableEntry::getRoom() const { return room; }
std::string TimetableEntry::getModule() const { return module; }
std::string TimetableEntry::getSessionType() const { return sessionType; }


void TimetableEntry::display() const {
    cout << "Week: " << weekNumber << ", Group: " << group << endl;
    cout << "Module: " << module << " | Lecturer: " << lecturer << endl;
    cout << "Session Type: " << sessionType << " | Day: " << day << " | Time: " << time << endl;
    cout << "Room: " << room << endl;
}
