#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <vector>
#include "Module.h"

class ModuleManager {
private:
    std::vector<Module> modules;

public:
    void addModule();
    void viewModules() const;
    void editModule();
    void deleteModule();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
