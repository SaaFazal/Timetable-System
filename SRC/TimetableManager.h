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
};

#endif
