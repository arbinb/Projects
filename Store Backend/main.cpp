#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Store.h"
#include <strstream>
#include <sstream>

using namespace std;

int main() {
    try{
        Store s;
        Store s2("Things to Buy");
        //cout << s2.getName();

        s.addProduct(123, "towel");
        s.getProduct(123).setDescription("For drying.");
        cout << "Towel: " << endl;
        cout << "ID: " << s.getProduct(123).getID() << endl;
        cout << "Name: " << s.getProduct(123).getName() << endl;
        cout << "Inventory Count: " << s.getProduct(123).getInventoryCount() << endl;
        cout << "Total Paid: " << s.getProduct(123).getTotalPaid() << endl;
        cout << "Number Sold: " << s.getProduct(123).getNumberSold() << endl;
        cout << "Description: " << s.getProduct(123).getDescription() << endl;

        s.addProduct(234,"mask");
        s.getProduct(234).setDescription("For hiding.");
        cout << endl << "Mask: " << endl;
        cout << "ID: " << s.getProduct(234).getID() << endl;
        cout << "Name: " << s.getProduct(234).getName() << endl;
        cout << "Inventory Count: " << s.getProduct(234).getInventoryCount() << endl;
        cout << "Total Paid: " << s.getProduct(234).getTotalPaid() << endl;
        cout << "Number Sold: " << s.getProduct(234).getNumberSold() << endl;
        cout << "Description: " << s.getProduct(234).getDescription() << endl;

        //s.addProduct(123,"random");
        //s.getProduct(555);

        cout << endl << "Towel (again): " << endl;
        cout << "ID: " << s.getProduct(123).getID() << endl;
        cout << "Name: " << s.getProduct(123).getName() << endl;
        cout << "Inventory Count: " << s.getProduct(123).getInventoryCount() << endl;
        cout << "Total Paid: " << s.getProduct(123).getTotalPaid() << endl;
        cout << "Number Sold: " << s.getProduct(123).getNumberSold() << endl;
        cout << "Description: " << s.getProduct(123).getDescription() << endl;

        s.addCustomer(987,"Joe Blockhead",true);
        cout << endl << "Customer Joe" << endl;
        cout << "Customer ID: " << s.getCustomer(987).getID() << endl;
        cout << "Customer Name: " << s.getCustomer(987).getName() << endl;
        cout << "Credit: " << s.getCustomer(987).getCredit() << endl;
        cout << "Balance: " << s.getCustomer(987).getBalance() << endl;
        cout << "Products purchased: " << s.getCustomer(987).getProductsPurchased() << endl;

        s.addCustomer(789, "Jane Grooves");
        cout << endl << "Customer Jane" << endl;
        cout << "Customer ID: " << s.getCustomer(789).getID() << endl;
        cout << "Customer Name: " << s.getCustomer(789).getName() << endl;
        cout << "Credit: " << s.getCustomer(789).getCredit() << endl;
        cout << "Balance: " << s.getCustomer(789).getBalance() << endl;
        cout << "Products purchased: " << s.getCustomer(789).getProductsPurchased() << endl;

        //s.addCustomer(987,"Someone new");
        //s.getCustomer(555);

        cout << endl << "Customer Joe (again)" << endl;
        cout << "Customer ID: " << s.getCustomer(987).getID() << endl;
        cout << "Customer Name: " << s.getCustomer(987).getName() << endl;
        cout << "Credit: " << s.getCustomer(987).getCredit() << endl;
        cout << "Balance: " << s.getCustomer(987).getBalance() << endl;
        cout << "Products purchased: " << s.getCustomer(987).getProductsPurchased() << endl;

        s.takeShipment(123, 200, 400);
        cout << endl << "Towel (again but changed): " << endl;
        cout << "ID: " << s.getProduct(123).getID() << endl;
        cout << "Name: " << s.getProduct(123).getName() << endl;
        cout << "Inventory Count: " << s.getProduct(123).getInventoryCount() << endl;
        cout << "Total Paid: " << s.getProduct(123).getTotalPaid() << endl;
        cout << "Number Sold: " << s.getProduct(123).getNumberSold() << endl;
        cout << "Description: " << s.getProduct(123).getDescription() << endl;

        //s.takeShipment(123, -5, 100);
        //s.takeShipment(123, 5, -100);
        //s.takeShipment(555, 2, -2);

        cout << endl << "Towel (again but changed, again): " << endl;
        cout << "ID: " << s.getProduct(123).getID() << endl;
        cout << "Name: " << s.getProduct(123).getName() << endl;
        cout << "Inventory Count: " << s.getProduct(123).getInventoryCount() << endl;
        cout << "Total Paid: " << s.getProduct(123).getTotalPaid() << endl;
        cout << "Number Sold: " << s.getProduct(123).getNumberSold() << endl;
        cout << "Description: " << s.getProduct(123).getDescription() << endl;

        s.takePayment(987, 600);
        cout << endl << "Customer Joe (again but added money to balance)" << endl;
        cout << "Customer ID: " << s.getCustomer(987).getID() << endl;
        cout << "Customer Name: " << s.getCustomer(987).getName() << endl;
        cout << "Credit: " << s.getCustomer(987).getCredit() << endl;
        cout << "Balance: " << s.getCustomer(987).getBalance() << endl;
        cout << "Products purchased: " << s.getCustomer(987).getProductsPurchased() << endl;

        //s.takePayment(987,-50);
        //s.takePayment(555,25);

        cout << endl << "Customer Joe (again with money in balance)" << endl;
        cout << "Customer ID: " << s.getCustomer(987).getID() << endl;
        cout << "Customer Name: " << s.getCustomer(987).getName() << endl;
        cout << "Credit: " << s.getCustomer(987).getCredit() << endl;
        cout << "Balance: " << s.getCustomer(987).getBalance() << endl;
        cout << "Products purchased: " << s.getCustomer(987).getProductsPurchased() << endl;

        s.sellProduct(987,123,10);
        cout << endl << "Customer Joe (buys something)" << endl;
        cout << "Customer ID: " << s.getCustomer(987).getID() << endl;
        cout << "Customer Name: " << s.getCustomer(987).getName() << endl;
        cout << "Credit: " << s.getCustomer(987).getCredit() << endl;
        cout << "Balance: " << s.getCustomer(987).getBalance() << endl;
        cout << "Products purchased: " << endl << s.getCustomer(987).getProductsPurchased() << endl;

        cout << "State of towel after sale: " << endl;
        cout << "ID: " << s.getProduct(123).getID() << endl;
        cout << "Name: " << s.getProduct(123).getName() << endl;
        cout << "Inventory Count: " << s.getProduct(123).getInventoryCount() << endl;
        cout << "Total Paid: " << s.getProduct(123).getTotalPaid() << endl;
        cout << "Number Sold: " << s.getProduct(123).getNumberSold() << endl;
        cout << "Description: " << s.getProduct(123).getDescription() << endl;

        //s.sellProduct(987,987,-10);
        //s.sellProduct(987,123, 1000);

        cout << s.listProducts();

    }
    catch (runtime_error&exc) {
        cout << "Exception caught: "<< exc.what() << endl;
    }

}