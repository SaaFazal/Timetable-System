#include "RoomManager.h"
#include <iostream>

using namespace std;

void RoomManager::addRoom(){
    string id, name, type;

    cout << "\n--- Add New Room ---\n";
    cout << "Enter Room ID: ";
    getline(cin >> ws, id);
    cout << "Enter Room Name: ";
    getline(cin, name);
    cout << "Enter Room Type (Lecture Hall / Lab): ";
    getline(cin, type);

    rooms.push_back(Room(id, name, type));
    cout << "Room added Successfully!\n";
}

void RoomManager::viewRooms() const {
    cout << "\n--- All Rooms ---\n";
    if (rooms.empty()) {
        cout << "No rooms available.\n";
    } else {
        for (const Room& r : rooms) {
            r.display();
            cout << "------------------------\n";
        }
    }
}