#include <iostream>
#include <map>
#include <string>
#include "manager.cpp" // Include the implementation of Manager class
#include "patron.cpp" // Include the implementation of Patron class
#include "coffee.cpp" // Include the implementation of coffee functions
#include "food.cpp" // Include the implementation of food functions
#include "main.h" // Include the function declarations


// Function to display the coffee options and get the patron's selection
std::pair<std::string, double> getCoffeeOrder(const std::vector<std::pair<std::string, double> >& coffeeOptions) {
    std::cout << "Here are our coffee options:\n";
    for (int i = 0; i < coffeeOptions.size(); i++) {
        std::cout << i + 1 << ". " << coffeeOptions[i].first << ": $" << coffeeOptions[i].second << std::endl;
    }
    std::cout << "Please enter the number of your selection: ";
    int selection;
    std::cin >> selection;
    return coffeeOptions[selection - 1];
}

// Function to display the food options and get the patron's selection
std::pair<std::string, double> getFoodOrder(const std::vector<std::pair<std::string, double> >& foodOptions) {
    std::cout << "Here are our food options:\n";
    for (int i = 0; i < foodOptions.size(); i++) {
        std::cout << i + 1 << ". " << foodOptions[i].first << ": $" << foodOptions[i].second << std::endl;
    }
    std::cout << "Please enter the number of your selection: ";
    int selection;
    std::cin >> selection;
    return foodOptions[selection - 1];
}

// Function to process the payment
void processPayment(double totalCost) {
    double paymentReceived;
    do {
        std::cout << "Your total cost is: $" << totalCost << "\n";
        std::cout << "Please enter your payment: ";
        std::cin >> paymentReceived;

        if (paymentReceived < totalCost) {
            std::cout << "Insufficient payment. Please enter a valid amount.\n";
        }
    } while (paymentReceived < totalCost);

    double change = paymentReceived - totalCost;
    std::cout << "Payment received. Your change is: $" << change << "\n";
}

int main() {
    // Ask for the user's role
    std::cout << "Welcome to the cafe! Please enter your role (Patron/Manager): ";
    std::string role;
    std::getline(std::cin, role);

    // Ask for the user's name if they are a patron
    std::string name;
    if (role == "Patron" || role == "patron") {
        std::cout << "Please enter your name: ";
        std::getline(std::cin, name);
    }

    double totalCost = 0.0;
    std::vector<std::pair<std::string, double> > orders;

    while (true) {
        // Display the options
        std::cout << "Hello, " << name << "! What would you like to do today?" << std::endl;
        std::cout << "1. Order Coffee" << std::endl;
        std::cout << "2. Order Food" << std::endl;
        std::cout << "3. Checkout" << std::endl;
        if (role == "Manager" || role == "manager") {
            std::cout << "4. Add Food Item" << std::endl;
        }

        // Ask the user to choose an option
        std::cout << "Please enter the number of your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::vector<std::pair<std::string, double> > coffeeOptions = getCoffeeOptions();
            std::pair<std::string, double> coffeeOrder = getCoffeeOrder(coffeeOptions);
            std::cout << "You have selected " << coffeeOrder.first << ".\n";
            orders.push_back(coffeeOrder);
            totalCost += coffeeOrder.second;
            break;
        }
        case 2: {
            std::vector<std::pair<std::string, double> > foodOptions = getFoodOptions();
            std::pair<std::string, double> foodOrder = getFoodOrder(foodOptions);
            std::cout << "You have selected " << foodOrder.first << ".\n";
            orders.push_back(foodOrder);
            totalCost += foodOrder.second;
            break;
        }
        case 3:
            goto checkout;
        case 4: {
    if (role == "Manager" || role == "manager") {
        std::cout << "Enter the name of the food item: ";
        std::string foodName;
        std::getline(std::cin >> std::ws, foodName); // Use getline to read the entire line
        std::cout << "Enter the price of the food item: ";
        double price;
        std::cin >> price;
        std::cout << "Food item added successfully.\n";
    } else {
        std::cerr << "Invalid choice! Please select a valid option." << std::endl;
    }
    return 0;
}
        }
    }

checkout:
    // Display the confirmation message
    std::cout << "Thank you! You have ordered:\n";
    for (std::vector<std::pair<std::string, double> >::iterator it = orders.begin(); it != orders.end(); ++it) {
        std::cout << "- " << it->first << ": $" << it->second << "\n";
    }
    std::cout << "Total cost: $" << totalCost << "\n";

    // Process the payment
    processPayment(totalCost);

    std::cout << "Your order will be ready shortly!" << std::endl;

    return 0;
}