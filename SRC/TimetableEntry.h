#ifndef TIMETABLEENTRY_H
#define TIMETABLEENTRY_H

#include <string>

class TimetableEntry {
private:
    int weekNumber;
    std::string group;
    std::string module;
    std::string lecturer;
    std::string room;
    std::string sessionType;
    std::string day;
    std::string time;

public:
    TimetableEntry();
    TimetableEntry(int week, std::string group, std::string module,
                   std::string lecturer, std::string room,
                   std::string sessionType, std::string day, std::string time);

    int getWeek() const;
    std::string getGroup() const;
    void display() const;
    std::string getLecturer() const;
    std::string getRoom() const;
    std::string getDay() const;
    std::string getTime() const;
    std::string getModule() const;
    std::string getSessionType() const;

};

#endif
