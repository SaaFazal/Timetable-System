#ifndef LECTURER_H
#define LECTURER_H

#include <string>

class Lecturer {
private:
    std::string lecturerID;
    std::string name;

public:
    Lecturer();
    Lecturer(std::string id, std::string name);

    std::string getID() const;
    std::string getName() const;

    void display() const;
};

#endif
