#include <iostream>
#include <string>
#include <vector>
#include "food.h"

class Manager {
private:
    std::string name;

public:
    // Constructor
    Manager(const std::string& name) : name(name) {}

    // Getter for name
    std::string getName() const {
        return name;
    }
};