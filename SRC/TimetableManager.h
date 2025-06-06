#ifndef TIMETABLEMANAGER_H
#define TIMETABLEMANAGER_H

#include <vector>
#include <string>
#include "TimetableEntry.h"

class TimetableManager {
private:
    std::vector<TimetableEntry> entries;

public:
    void addTimetableEntry();
    void viewTimetableByGroupAndWeek();
    bool hasConflict(const TimetableEntry& newEntry) const;
    void exportTimetableToCSV() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void viewTimetableByGroupAndWeek(const std::string& group, int week) const;
    void exportGroupTimetable(const std::string& group) const;
    void searchTimetableByGroup(const std::string& group) const;


};

#endif
