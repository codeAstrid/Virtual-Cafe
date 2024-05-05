#include "patron.h"
#include <iostream>

Patron::Patron(const std::string& name, const std::string& orderType)
    : name(name), orderType(orderType), numItems(0) {}

void Patron::placeOrder() {
    std::cout << "Hello, " << name << "! What would you like to order today? ";
    std::string additionalOrder;
    std::getline(std::cin, additionalOrder);

    orderType += " and " + additionalOrder;
    std::cout << "Thank you, " << name << "! Your order of " << orderType << " will be ready shortly." << std::endl;
}

void Patron::setNumItems(int num) {
    numItems = num;
}

int Patron::getNumItems() const {
    return numItems;
}

void Patron::payForFood(double price, double totalAmount) {
    if (totalAmount >= price) {
        std::cout << "Payment successful. Enjoy your food!" << std::endl;
    } else {
        std::cout << "Insufficient funds. Please enter a valid amount." << std::endl;
    }
}