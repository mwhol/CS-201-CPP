// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "pch.h"
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
protected:
	double price;
	int quantity;
	string description;

public:
	Product();
	Product(double price, int quantity);
	void setPrice(double price);
	void setQuantity(int quantity);
	void setDescription(string description);
	virtual ostream& print(ostream& out) = 0;
	virtual double calculateTotal();
};

#endif