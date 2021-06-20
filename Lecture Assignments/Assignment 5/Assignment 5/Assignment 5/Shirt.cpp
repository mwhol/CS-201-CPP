// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "pch.h"
#include "Shirt.h"
#include <iomanip>


Shirt::Shirt() {
	size = "";
}


void Shirt::setSize(string size) {
	this->size = size;
}

ostream& Shirt::print(ostream& out) {
	//we use a temporary string to compile our information, which makes
	//the setwidth a little easier
	string fullDescription;
	fullDescription = size + " " + description;
	out << setw(3) << right << quantity << " ";
	out << setw(28) << left << fullDescription;
	out << "$" << setw(7) << right << setprecision(2) << fixed << calculateTotal();
	return out;
}

double Shirt::calculateTotal() {
	if (size == "2XL" || size == "3XL") {
		return (price + 1) * quantity;
	}
	return price * quantity;
}