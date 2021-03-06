// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "pch.h"

#include <iomanip>
#include <fstream>
#include <string>

#include "Product.h"
#include "Shirt.h"
#include "OfficeSupplies.h"
#include "Register.h"

using namespace std;

int main() {
	string productType, description, size;
	int quantity, count;
	double price;
	Shirt* myShirt;
	OfficeSupplies* myOfficeSupplies;
	Register myRegister;
	ifstream fin;
	ofstream fout;
	fin.open("products.txt");
	fout.open("output.txt");

	while (fin.good()) {
		//we read a bit of data
		fin >> productType;
		getline(fin, description);
		getline(fin, description);

		//we check what the product type is, create a new object
		//and then set all the important details
		//afterwards we add it to our register
		if (productType == "SHIRT") {
			myShirt = new Shirt;
			fin >> size >> quantity >> price;
			myShirt->setDescription(description);
			myShirt->setSize(size);
			myShirt->setQuantity(quantity);
			myShirt->setPrice(price);
			myRegister.addProduct(myShirt);
		}
		else if (productType == "SUPPLIES") {
			myOfficeSupplies = new OfficeSupplies;
			fin >> count >> quantity >> price;
			myOfficeSupplies->setDescription(description);
			myOfficeSupplies->setCount(count);
			myOfficeSupplies->setQuantity(quantity);
			myOfficeSupplies->setPrice(price);
			myRegister.addProduct(myOfficeSupplies);
		}
		productType = "";
	}

	//we print out our receipt
	myRegister.printReceipt(fout);
	return 0;
}