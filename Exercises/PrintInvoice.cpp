#include <iostream>
#include <string>

using namespace std;

class Client
{
public:
	Client();
	Client(string name, string address);
	string getName();
	string getLocation();
	string getAddress();
	string getPostalCode();

private:
	string name;
	string location;
	string address;
	string postalCode;
};

Client::Client(string name, string addr)
{
	this->name = name;
	address = addr;
}

string Client::getName()
{
	return name;
}

string Client::getLocation()
{
	return location;
}

string Client::getAddress()
{
	return address;
}

string Client::getPostalCode()
{
	return postalCode;
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

Item::Item(Product myProduct, int amount)
{
	product = myProduct;
	productPrice = myProduct.getPrice();
	quantity = amount;
	total = productPrice * total;
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


private:
	Client client;
	Item items[1];

	double totalAmount;

};

//===================================================================================================================================

int main()
{

}