#include "Customer.h"
#include <ostream>
#include <sstream>

using namespace std;

Customer::Customer(int customerID, string name, bool credit) : id(customerID), name(name), credit(credit), balance(0)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
}

int Customer::getID() const {return id;}

string Customer::getName() const {return name;}

void Customer::setName(string name)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
    this-> name = name;
}

bool Customer::getCredit() const {return credit;}

void Customer::setCredit(bool hasCredit)
{
    this-> credit = hasCredit;
}

double Customer::getBalance() const {return balance;}

void Customer::processPayment(double amount)
{
    if (amount < 0)
        throw runtime_error("Can't add negative dollars to balance.");
    this -> balance += amount;
}

void Customer::processPurchase(double amount, Product product)
{
    if (amount < 0)
        throw runtime_error("Can't purchase something with negative price.");
    this-> balance -= amount;
    if (!credit) {
        if (balance < 0)
            throw runtime_error("Can't have negative balance without credit.");
    }
    this -> productsPurchased.push_back(product);
}

string Customer::getProductsPurchased() const
{
    ostringstream prodPurchased;
    if (productsPurchased.size() == 0)
        return prodPurchased.str();

    for (int i = 0; i < productsPurchased.size(); ++i) {
        prodPurchased << "Product Name: " << productsPurchased.at(i).getName() << endl;
        prodPurchased << "Product ID: " << productsPurchased.at(i).getID();
        prodPurchased << endl << endl;
    }
    return prodPurchased.str();
}

ostream& operator<<(ostream& os, const Customer& c)
{
    os << "Customer Name: " << c.getName() << endl;
    os << "Customer ID: " << c.getID() << endl;
    if (c.getCredit())
        os << "Has Credit: true" << endl;
    else
        os << "Has Credit: false" << endl;
    os << "Balance: " << c.getBalance() << endl;
    os << "Products Purchased --" << endl << endl;
    os << c.getProductsPurchased();
    return os;
}