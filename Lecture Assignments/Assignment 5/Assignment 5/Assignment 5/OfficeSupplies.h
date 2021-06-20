// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "Product.h"

#ifndef OFFICESUPPLIES_H
#define OFFICESUPPLIES_H

using namespace std;


class OfficeSupplies : public Product {
private:
	int count;

public:
	OfficeSupplies();
	void setCount(int count);
	ostream& print(ostream& out);
};

#endif