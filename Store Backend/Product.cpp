#include "Product.h"
#include <string>

using namespace std;

Product::Product(int id, string name) : id(id), name(name), inventory(0), numSold(0), totalPaid(0.0)
{
    if (name.length()==0)
        throw runtime_error("Product name cannot be empty.");
}

int Product::getID() const {return id;}

string Product::getName() const {return name;}

void Product::setName(string newName)
{
    if (newName.length()==0)
        throw runtime_error("Product name cannot be empty.");
    this-> name = newName;
}

string Product::getDescription() const {return description;}

void Product::setDescription(string description)
{
    this-> description = description;
}

int Product::getNumberSold() const {return numSold;}

double Product::getTotalPaid() const {return totalPaid;}

int Product::getInventoryCount() const {return inventory;}

void Product::addShipment(int shipmentQuantity, double shipmentCost)
{
    if (shipmentCost < 0 || shipmentQuantity < 0)
        throw runtime_error("Negative shipment quantity or cost.");
    this-> inventory += shipmentQuantity;
    this-> totalPaid += shipmentCost;
}

void Product::reduceInventory(int purchaseQuantity)
{
    if (purchaseQuantity < 1)
        throw runtime_error("Negative purchase quantity");
    if (this-> inventory < purchaseQuantity)
        throw runtime_error("Not enough inventory");
    this-> inventory -= purchaseQuantity;
    this-> numSold += purchaseQuantity;
}

double Product::getPrice() const
{
    if ((inventory + numSold) == 0)
        throw runtime_error("Cannot calculate price");
    return (totalPaid / (inventory + numSold)) * 1.25;
}

ostream & operator<<(ostream &os, const Product &p)
{
    os << "Product Name: " << p.getName() << endl;
    os << "Product ID: " << p.getID() << endl;
    os << "Description: " << p.getDescription() << endl;
    os << "Inventory: " << p.getInventoryCount() << endl;
    os << "Number Sold: " << p.getNumberSold() << endl;
    os << "Total Paid: " << p.getTotalPaid() << endl;
    bool priceError = false;
    try {
        p.getPrice();
    }
    catch (runtime_error&exc){
        os << "Price: Unavailable" << endl << endl;
        priceError = true;
    }
    if (!priceError)
        os << "Price: " << p.getPrice() << endl;

    return os;
}
