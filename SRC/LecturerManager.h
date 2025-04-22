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
    void editLecturer();
    void deleteLecturer();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

};

#endif