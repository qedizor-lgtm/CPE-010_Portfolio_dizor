#include <iostream>
#include <string>

class GroceryItem {
protected:
    std::string name;
    double price;
    int quantity;
    std::string type;

public:
    GroceryItem(std::string n = "", double p = 0.0, int q = 0, std::string t = "") 
        : name(n), price(p), quantity(q), type(t) {}
    
    virtual ~GroceryItem() {}

    GroceryItem(const GroceryItem& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
        type = other.type;
    }

    GroceryItem& operator=(const GroceryItem& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
            type = other.type;
        }
        return *this;
    }

    double calculateSum() const {
        return price * quantity;
    }

    void printDetails() const {
        std::cout << "[" << type << "] " << name 
                  << " | Price: Php " << price 
                  << " | Qty: " << quantity 
                  << " | Total: Php " << calculateSum() << std::endl;
    }
};

class Fruit : public GroceryItem {
public:
    Fruit(std::string n = "", double p = 0.0, int q = 0) 
        : GroceryItem(n, p, q, "Fruit") {}
};

class Vegetable : public GroceryItem {
public:
    Vegetable(std::string n = "", double p = 0.0, int q = 0) 
        : GroceryItem(n, p, q, "Vegetable") {}
};

int main() {
    const int totalItems = 4;
    GroceryItem* GroceryList[totalItems];

    GroceryList[0] = new Fruit("Apple", 10.0, 7);
    GroceryList[1] = new Fruit("Banana", 10.0, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60.0, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50.0, 10);

    double grandTotal = 0.0;
    for (int i = 0; i < totalItems; i++) {
        GroceryList[i]->printDetails();
        grandTotal += GroceryList[i]->calculateSum();
    }

    std::cout << "\nGrand Total: Php " << grandTotal << std::endl;

    for (int i = 0; i < totalItems; i++) {
        delete GroceryList[i];
    }

    return 0;
}

