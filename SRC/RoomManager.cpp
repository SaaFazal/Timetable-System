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

void RoomManager::editRoom() {
    if (rooms.empty()) {
        cout << "\nNo rooms to edit.\n";
        return;
    }

    string id;
    cout << "Enter Room ID to edit: ";
    getline(cin >> ws, id);

    for (auto& r : rooms) {
        if (r.getID() == id) {
            string newName, newType;
            cout << "Enter new Room Name: ";
            getline(cin, newName);
            cout << "Enter new Room Type: ";
            getline(cin, newType);
            r = Room(id, newName, newType);
            cout << "Room updated successfully!\n";
            return;
        }
    }

    cout << "Room not found.\n";
}

void RoomManager::deleteRoom() {
    if (rooms.empty()) {
        cout << "\nNo rooms to delete.\n";
        return;
    }

    string id;
    cout << "Enter Room ID to delete: ";
    getline(cin >> ws, id);

    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (it->getID() == id) {
            rooms.erase(it);
            cout << "Room deleted successfully.\n";
            return;
        }
    }

    cout << "Room not found.\n";
}
