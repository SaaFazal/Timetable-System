#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string studentID;
    std::string name;
    std::string group;

public:
    Student();
    Student(std::string id, std::string name, std::string group);

    std::string getID() const;
    std::string getName() const;
    std::string getGroup() const;

    void display() const;
};

#endif
