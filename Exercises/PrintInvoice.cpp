#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Client
{
public:
	Client();
	Client(string name, string address);
	string getName();
	string getAddress();

private:
	string name;
	string address;
};

Client::Client()
{

}

Client::Client(string name, string addr)
{
	this->name = name;
	address = addr;
}

string Client::getName()
{
	return name;
}

string Client::getAddress()
{
	return address;
}

//===================================================================================================================================

class Product
{
public:
	Product();
	Product(string description, double price);
	string getDescription();
	double getPrice();

private:
	string description;
	double price;
};

Product::Product()
{

}

Product::Product(string descr, double cost)
{
	description = descr;
	price = cost;
}

string Product::getDescription()
{
	return description;
}

double Product::getPrice()
{
	return price;
}

//===================================================================================================================================

class Item
{
public:
	Item();
	Item(Product product, int quantity);
	Product getProduct();
	double getProductPrice();
	int getQuantity();
	double getTotal();

private:
	Product product;
	double productPrice;
	int quantity;
	double total;
};

Item::Item()
{

}

Item::Item(Product myProduct, int amount)
{
	product = myProduct;
	productPrice = myProduct.getPrice();
	quantity = amount;
	total = productPrice * quantity;
}

Product Item::getProduct()
{
	return product;
}

double Item::getProductPrice()
{
	return productPrice;
}

int Item::getQuantity()
{
	return quantity;
}

double Item::getTotal()
{
	return total;
}

//===================================================================================================================================

class Invoice
{
public:
	Invoice(Client client, string, string, string);
	void addNewItem(Item item);
	void deleteLastItem();
	void printInvoice();

	string getLocation();
	string getAddress();
	string getPostalCode();

private:
	Client client;
	vector<Item> items;

	double totalAmount;
	string location;
	string address;
	string postalCode;
};

Invoice::Invoice(Client client, string location, string address, string postalCode)
{
	this->client = client;
	this->location = location;
	this->address = address;
	this->postalCode = postalCode;
}

void Invoice::addNewItem(Item item)
{
	items.push_back(item);
}

void Invoice::deleteLastItem()
{
	items.pop_back();
}

void Invoice::printInvoice()
{
	double totalPrice = 0;
	cout << location << endl;
	cout << address << endl;
	cout << postalCode << endl;
	cout << endl;
	cout << fixed << setw(12) << "Description  " << setw(6) << " Price " << setw(5) << " Qty " << setw(8) << " Total \n";
	cout << fixed << setw(12) << "-----------  " << setw(6) << " ----- " << setw(5) << " --- " << setw(8) << " ----- \n";
	for (int i = 0; i < items.size(); i++)
	{
		Item currentItem = items.at(i);
		int quant = currentItem.getQuantity();
		double price = currentItem.getProductPrice();
		double total = currentItem.getTotal();
		string productName = currentItem.getProduct().getDescription();
		//cout << productName << "          " << price << "      " << quant << "     " << total << endl;
		cout << fixed << setprecision(2) << productName << setw(6) << " " << price << setw(5) << " " << quant << setw(8) << " " << total << endl;
		totalPrice += total;
	}

	cout << "\nAmount due: " << totalPrice << " euro\n";
}

string Invoice::getLocation()
{
	return location;
}

string Invoice::getAddress()
{
	return address;
}

string Invoice::getPostalCode()
{
	return postalCode;
}

//===================================================================================================================================

int main()
{
	Client client("Gil", "Porto");
	Product product1("Batata", 12.0), product2("Spaghetti", 9.99), product3("Chair", 259.99);
	Item item1(product1, 2), item2(product2, 4), item3(product3, 1);

	Invoice invoice(client, "DEI - FEUP", "Rua Dr. Roberto Frias, s/n", "4200-465 Porto");
	invoice.addNewItem(item1);
	invoice.addNewItem(item2);
	invoice.addNewItem(item3);

	invoice.printInvoice();
	
	return 0;
}