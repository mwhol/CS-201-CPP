#include "pch.h"
#include "OfficeSupplies.h"
#include <iomanip>

OfficeSupplies::OfficeSupplies() {
	count = 0;
}

void OfficeSupplies::setCount(int count) {
	this->count = count;
}

ostream& OfficeSupplies::print(ostream& out) {
	//we build a composite string to make our formatting easier
	string fullDescription;
	fullDescription = description + " (" + to_string(count) + " count)";

	out << setw(3) << quantity << " ";
	out << setw(28) << left << fullDescription;
	out << "$" << setw(7) << right << setprecision(2) << fixed << calculateTotal();
	return out;
}