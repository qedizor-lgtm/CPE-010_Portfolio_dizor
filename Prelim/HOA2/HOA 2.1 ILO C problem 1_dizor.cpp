#include <iostream>
#include <string>

class Fruit {
private:
    std::string name;
    double price;
    int quantity;

public:
    Fruit(std::string n = "", double p = 0.0, int q = 0) : name(n), price(p), quantity(q) {}
    
    ~Fruit() {}

    Fruit(const Fruit& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double calculateSum() const {
        return price * quantity;
    }

    void printDetails() const {
        std::cout << name << " | Price: Php " << price << " | Qty: " << quantity << " | Total: Php " << calculateSum() << std::endl;
    }
};

class Vegetable {
private:
    std::string name;
    double price;
    int quantity;

public:
    Vegetable(std::string n = "", double p = 0.0, int q = 0) : name(n), price(p), quantity(q) {}

    ~Vegetable() {}

    Vegetable(const Vegetable& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double calculateSum() const {
        return price * quantity;
    }

    void printDetails() const {
        std::cout << name << " | Price: Php " << price << " | Qty: " << quantity << " | Total: Php " << calculateSum() << std::endl;
    }
};

int main() {
    Fruit apple("Apple", 10.0, 7);
    Fruit banana("Banana", 10.0, 8);
    Vegetable broccoli("Broccoli", 60.0, 12);
    Vegetable lettuce("Lettuce", 50.0, 10);

    std::cout << "==== Grocery Items ====" << std::endl;
    apple.printDetails();
    banana.printDetails();
    broccoli.printDetails();
    lettuce.printDetails();

    double totalCost = apple.calculateSum() + banana.calculateSum() + broccoli.calculateSum() + lettuce.calculateSum();
    std::cout << "\nGrand Total: Php " << totalCost << std::endl;

    return 0;
}

