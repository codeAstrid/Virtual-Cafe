#include "food.h"

std::vector<std::pair<std::string, double> > foodOptions;

void initializeFoodOptions() {
    foodOptions.push_back(std::make_pair("Sandwich", 5.00));
    foodOptions.push_back(std::make_pair("Burger", 7.50));
    foodOptions.push_back(std::make_pair("Salad", 6.00));
    foodOptions.push_back(std::make_pair("Pasta", 8.50));
    foodOptions.push_back(std::make_pair("Pizza", 9.00));
}

std::vector<std::pair<std::string, double> > getFoodOptions() {
    if (foodOptions.empty()) {
        initializeFoodOptions();
    }
    return foodOptions;
}
