#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int id;
    double price;
    int quantity;
    int maxQuantity;

public:
    Product(string pName, int pID, double pPrice, int pQuantity, int pMaxQuantity) {
        name = pName;
        id = pID;
        price = pPrice;
        quantity = pQuantity;
        maxQuantity = pMaxQuantity;
    }

    void addToInventory(int addedQuantity) {
        if (quantity + addedQuantity <= maxQuantity) {
            quantity += addedQuantity;
            cout << addedQuantity << " items added to inventory." << endl;
        } else {
            cout << "Cannot add more than maximum allowed quantity!" << endl;
        }
    }

    bool isAvailable() {
        return quantity > 0;
    }

    void purchase(int purchasedQuantity) {
        if (isAvailable()) {
            if (purchasedQuantity <= quantity) {
                quantity -= purchasedQuantity;
                cout << purchasedQuantity << " items purchased." << endl;
            } else {
                cout << "Insufficient stock to complete purchase!" << endl;
            }
        } else {
            cout << "Product is out of stock!" << endl;
        }
    }

    void updatePrice(int discountPercent) {
        price = price - (price * discountPercent / 100);
        cout << "Price updated with " << discountPercent << "% discount." << endl;
    }

    void displayInventoryValue() {
        cout << "Total Inventory Value for " << name << ": $" << quantity * price << endl;
    }

    void displayDetails() {
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Availability: " << (isAvailable() ? "Available" : "Out of Stock") << endl;
    }

    double getTotalInventoryValue() {
        return quantity * price;
    }
};

void displayTotalInventoryValue(Product p1, Product p2, Product p3) {
    double totalValue = p1.getTotalInventoryValue() + p2.getTotalInventoryValue() + p3.getTotalInventoryValue();
    cout << "Total Inventory Value of all products: $" << totalValue << endl;
}

int main() {
    Product prod1("Laptop", 101, 1000.0, 50, 100);
    prod1.addToInventory(20);
    prod1.purchase(10);
    prod1.updatePrice(5);
    prod1.displayInventoryValue();
    prod1.displayDetails();

    cout << "----" << endl;

    Product prod2("Smartphone", 102, 500.0, 30, 50);
    Product prod3("Tablet", 103, 300.0, 40, 60);

    prod2.displayDetails();
    cout << "----" << endl;
    prod3.displayDetails();
    cout << "----" << endl;

    displayTotalInventoryValue(prod1, prod2, prod3);

    return 0;
}
