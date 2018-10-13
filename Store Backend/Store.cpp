#include "Store.h"

using namespace std;

Store::Store() {}

Store::Store(string name) : name(name) {
//    if (name.length()==0)
//        throw runtime_error("Store name cannot be empty.");
}

string Store::getName() const {return name;}

void Store::setName(string name) {
    this-> name = name;
}

void Store::addProduct(int productID, string productName)
{
    for (int i = 0; i < products.size(); ++i) {
        if (productID == products.at(i).getID())
            throw runtime_error("Same Product ID exists.");
    }
    Product newProduct(productID, productName);
    this-> products.push_back(newProduct);
}

Product& Store::getProduct(int productID)
{
    bool returnException = true;
    for (int i = 0; i < products.size(); ++i) {
        if (productID == products.at(i).getID()) {
            returnException = false;
            return products.at(i);
        }
    }
    if (returnException)
        throw runtime_error("Could not find product.");

}

void Store::addCustomer(int customerID, std::string customerName, bool credit)
{
    for (int i = 0; i < customers.size(); ++i) {
        if (customerID == customers.at(i).getID())
            throw runtime_error("Same Customer ID exists.");
    }
    Customer newCustomer(customerID, customerName, credit);
    this-> customers.push_back(newCustomer);
}

Customer& Store::getCustomer(int customerID)
{
    bool returnException = true;
    for (int i = 0; i < customers.size(); ++i) {
        if (customerID == customers.at(i).getID()) {
            returnException = false;
            return customers.at(i);
        }
    }
    if (returnException)
        throw runtime_error("Could not find customer.");
}

void Store::takeShipment(int productID, int quantity, double cost)
{
    bool returnException = true;
    for (int i = 0; i < products.size(); ++i) {
        if (productID == products.at(i).getID()) {
            returnException = false;
            products.at(i).addShipment(quantity, cost);
        }
    }
    if (returnException)
        throw runtime_error("Could not find product");

}

void Store::takePayment(int customerID, double amount)
{
    bool returnException = true;
    for (int i = 0; i < customers.size(); ++i) {
        if (customerID == customers.at(i).getID()) {
            returnException = false;
            customers.at(i).processPayment(amount);
        }
    }
    if (returnException)
        throw runtime_error("Could not find customer.");
}

void Store::sellProduct(int customerID, int productID, int quantity)
{
    getCustomer(customerID).processPurchase(getProduct(productID).getPrice() * quantity, getProduct(productID));
    getProduct(productID).reduceInventory(quantity);
}

string Store::listProducts()
{
    stringstream output;
    for (int i = 0; i < products.size(); ++i) {
        output << products.at(i);
        if (i != products.size() - 1) {
            output << endl;
        }
    }
    return output.str();
}

string Store::listCustomers()
{
    stringstream output;
    for (int i = 0; i < customers.size(); ++i) {
        output << customers.at(i);
        output << endl;
    }
    return output.str();
}