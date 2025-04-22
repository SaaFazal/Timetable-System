#ifndef FILE_H
#define FILE_H

#include <vector>
#include <string>
#include <fstream>
#include <functional>
#include <iostream>

class File {
    public:
        template<typename T>
        static void saveCSV(const std::string& filename, const std::vector<T>& items, std::function<std::string(const T&)> toCSV) {
            std::ofstream outFile(filename);
            if (!outFile) {
                std::cout<< "Failed to write the " << filename << "\n";
                return;
            }

            for (const auto& item : items){
                outFile << toCSV(item) << "\n";
            }

            outFile.close();
            std::cout << "Saved to the " << filename << "\n";
        }

        template<typename T>
        static void loadCSV(const std::string& filename, std::vector<T>& items, std::function<T(const std::string&)> fromCSV) {
            std::ifstream inFile(filename);
            if (!inFile) {
                std::cout << "No existing file: " << filename << "\n";
                return;
            }

            items.clear();
            std::string line;
            while (getline(inFile, line)) {
                items.push_back(fromCSV(line));
            }

            inFile.close();
            std::cout << "This is Loaded from " << filename << "\n";
        }
};

#endif