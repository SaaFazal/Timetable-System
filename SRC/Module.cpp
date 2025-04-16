#include "Module.h"
#include <iostream>

using namespace std;

Module::Module() {}

Module::Module(string code, string name, string lecturer, string group,
               string session, string day, string time, string room)
    : moduleCode(code), moduleName(name), lecturer(lecturer),
      groupName(group), sessionType(session), day(day), time(time), room(room) {}

string Module::getModuleCode() const { return moduleCode; }
string Module::getModuleName() const { return moduleName; }
string Module::getLecturer() const { return lecturer; }
string Module::getGroupName() const { return groupName; }
string Module::getSessionType() const { return sessionType; }
string Module::getDay() const { return day; }
string Module::getTime() const { return time; }
string Module::getRoom() const { return room; }

void Module::display() const {
    cout << "Module Code: " << moduleCode << endl;
    cout << "Module Name: " << moduleName << endl;
    cout << "Lecturer: " << lecturer << endl;
    cout << "Group: " << groupName << endl;
    cout << "Session Type: " << sessionType << endl;
    cout << "Day: " << day << endl;
    cout << "Time: " << time << endl;
    cout << "Room: " << room << endl;
}
