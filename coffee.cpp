#include "coffee.h"

std::vector<std::pair<std::string, double> > getCoffeeOptions() {
    std::vector<std::pair<std::string, double> > coffeeOptions;
    coffeeOptions.push_back(std::make_pair("Espresso", 1.99));
    coffeeOptions.push_back(std::make_pair("Latte", 2.99));
    coffeeOptions.push_back(std::make_pair("Cappuccino", 3.49));
    coffeeOptions.push_back(std::make_pair("Americano", 2.49));
    coffeeOptions.push_back(std::make_pair("Mocha", 3.99));
    return coffeeOptions;
}