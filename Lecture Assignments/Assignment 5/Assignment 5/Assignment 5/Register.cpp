// MIKE WHOLEY
// ASSIGNMENT 5
// 11/8/2018

#include "pch.h"
#include "Register.h"
#include <iomanip>

Register::Register() {
	numProducts = 0;
}

void Register::addProduct(Product* item) {
	//how we add items to our array
	productArray[numProducts] = item;
	numProducts++;
}


ostream& Register::printReceipt(ostream& out) {
	double grandTotal = 0.0;

	//the printing of our header
	out << string(40, '*') << endl;
	out << "*" << string(12, ' ') << "UMKC BOOKSTORE" << string(12, ' ') << "*" << endl;
	out << string(40, '*') << endl << endl;
	out << "Qty ";
	out << setw(28) << left << "Description";
	out << setw(7) << left << "Total";
	out << endl;
	out << "--- --------------------------- --------" << endl;

	//looping through our items and printing them
	for (int i = 0; i < numProducts; i++) {
		productArray[i]->print(out);
		out << endl;
	}

	//we calculate the total bill
	out << endl << "Grand Total: $";
	for (int i = 0; i < numProducts; i++) {
		grandTotal += productArray[i]->calculateTotal();
	}

	//and then print the footer to the receipt
	out << setprecision(2) << fixed << grandTotal << endl;
	out << "Items sold:  " << numProducts << endl << endl;
	out << "* Thank you for shopping at our store! *";

	return out;
}
