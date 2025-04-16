#ifndef MODULE_H
#define MODULE_H

#include <string>

class Module {
private:
    std::string moduleCode;
    std::string moduleName;
    std::string lecturer;
    std::string groupName;
    std::string sessionType;
    std::string day;
    std::string time;
    std::string room;

public:
    // Constructors
    Module();
    Module(std::string code, std::string name, std::string lecturer, std::string group,
           std::string session, std::string day, std::string time, std::string room);

    // Getters
    std::string getModuleCode() const;
    std::string getModuleName() const;
    std::string getLecturer() const;
    std::string getGroupName() const;
    std::string getSessionType() const;
    std::string getDay() const;
    std::string getTime() const;
    std::string getRoom() const;

    // Display
    void display() const;
};

#endif
