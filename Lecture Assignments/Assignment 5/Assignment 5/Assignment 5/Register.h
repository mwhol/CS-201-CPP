// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "Product.h"

#ifndef REGISTER_H
#define REGISTER_H

using namespace std;

class Register {
private:
	int numProducts;
	Product* productArray[50];

public:
	Register();
	void addProduct(Product* item);
	ostream& printReceipt(ostream& out);

};

#endif