#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <vector>
#include "Room.h"

class RoomManager {
private:
    std::vector<Room> rooms;

public:
    void addRoom();
    void viewRooms() const;
    void editRoom();
    void deleteRoom();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

};

#endif
