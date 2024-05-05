#include <string>

class Patron {
public:
    Patron(const std::string& name, const std::string& orderType);

    void placeOrder();
    void setNumItems(int num);
    int getNumItems() const;
    void payForFood(double price, double totalAmount); // Add this line

private:
    std::string name;
    std::string orderType;
    int numItems;
};