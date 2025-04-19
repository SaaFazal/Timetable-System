#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent();
    void viewStudents() const;
    void editStudent();
    void deleteStudent();

};

#endif
