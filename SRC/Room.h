#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    std::string roomID;
    std::string name;
    std::string type; // e.g., Lecture Hall, Lab

public:
    Room();
    Room(std::string id, std::string name, std::string type);

    std::string getID() const;
    std::string getName() const;
    std::string getType() const;

    void display() const;
};

#endif
