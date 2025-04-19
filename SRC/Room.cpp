#include "Room.h"
#include <iostream>

using namespace std;

Room::Room() {}

Room::Room(string id, string name, string type)
    : roomID(id), name(name), type(type) {}

string Room::getID() const { return roomID; }
string Room::getName() const { return name; }
string Room::getType() const { return type; }

void Room::display() const {
    cout << "Room ID: " << roomID << endl;
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
}
