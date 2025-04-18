#ifndef LECTURERMANAGER_H
#define LECTURERMANAGER_H

#include <vector>
#include "Lecturer.h"

class LecturerManager {
private: 
    std::vector<Lecturer> lecturers;

public:
    void addLecturer();
    void viewLecturers() const;

};

#endif