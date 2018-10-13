#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>
#include <iostream>
#include <strstream>

class Product {
public:
    Product(int productID, std::string productName);
    int getID() const;
    std::string getName() const;
    void setName(std::string newName);
    std::string getDescription() const;
    void setDescription(std::string description);
    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);
    double getPrice() const;
private:
    int id;
    int inventory;
    int numSold;
    std::string name;
    std::string description;
    double totalPaid;
};

std::ostream & operator<<(std::ostream &os, const Product &p);


#endif //STORE_BACKEND_PRODUCT_H
