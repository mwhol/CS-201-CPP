// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include <string>
#include "Product.h"

#ifndef SHIRT_H
#define SHIRT_H

using namespace std;

class Shirt : public Product {
private:
	string size;

public:
	Shirt();
	void setSize(string size);
	ostream& print(ostream& out);
	double calculateTotal();
};

#endif