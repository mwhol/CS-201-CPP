#include "pch.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Student.h"

using namespace std;

Student::Student() {
	ID = 0;
	firstName = "";
	lastName = "";
	//we also set these here for convenience
	arraySize = 0;
	numItems = 0;
}

Student::Student(int ID, string firstName, string lastName) {
	this->ID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	arraySize = 0;
}

//Our Getters
string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

int Student::getID() const {
	return ID;
}

int Student::CheckoutCount() {
	return numItems;
}


//Our Setters
void Student::setFirstName(string name) {
	firstName = name;
}

void Student::setLastName(string name) {
	lastName = name;
}

void Student::setID(int num) {
	//used 100,000 for upper range since all IDs are > 10,000
	if ((num >= 1000) && (num <= 100000)) { ID = num; }
}


bool Student::CheckOut(const string& item) {
	//if no array we create one
	if (arraySize == 0) {
		arraySize = 5;
		items = new string[arraySize];
		numItems = 0;
	}
	//if the item is already in our array, we don't add
	//it and instead return false
	for (int i = 0; i < numItems; i++) {
		if (items[i].find(item) != -1) {
			return false;
		}
	}
	//if our array is maxed out we initalize a new one that is
	//5 indexes larger, copy our current items over, delete the
	//old one and set our pointer to the address of the new one
	if (numItems == arraySize) {
		string* newItems;
		newItems = new string[arraySize + 5];
		for (int i = 0; i < arraySize; i++) {
			newItems[i] = items[i];
		}
		delete[] items;
		items = newItems;
		arraySize += 5;
	}
	//we add the item, adjust the numItems up and return true
	items[numItems] = item;
	numItems += 1;
	return true;
}

bool Student::CheckIn(const string& item) {
	int i;
	bool returnValue = false;
	//first we look for the matching item
	for (i = 0; i < numItems; i++) {
		if (items[i] == item) {
			returnValue = true;
			break;
		}
	}
	//if we didn't find it, we return false
	if (!returnValue) {
		return false;
	}
	//to delete the item we shift every item after it down
	//one spot and then we reduce numItems and return true
	for (int j = i; j < numItems - 1; j++) {
		items[j] = items[j + 1];
	}
	numItems -= 1;
	return true;
}

bool Student::HasCheckedOut(const string& item) {
	//we loop through the students items searching for a
	//match, if we find it we return true, otherwise false
	for (int i = 0; i < numItems; i++) {
		if (items[i].find(item) != -1) { return true; }
	}
	return false;
}

void Student::Clear() {
	//we set everything to 0s or empty strings
	ID = 0;
	firstName = "";
	lastName = "";
	//then we delete the array items
	for (int i = 0; i < arraySize; i++) {
		delete &items[i];
	}
}

Student::~Student() {
	//if our array has been initialized then we delete it
	if (arraySize != 0) {
		delete[] items;
	}
	delete items;
}

istream& operator>>(istream& in, Student& item) {
	string firstName, lastName, checkout;
	unsigned int ID = 0;
	unsigned int itemCount = 0;

	//first we clear our student and then we read in our data directly
	item.Clear();
	in >> ID >> firstName >> lastName >> itemCount;

	item.setID(ID);
	item.setFirstName(firstName);
	item.setLastName(lastName);

	//we loop through and checkout our items one at a time
	//(I prefer this way because all of my dynamic array expanding
	//and handling is contained in my CheckOut function)
	for (int i = 0; i < itemCount; i++) {
		in >> checkout;
		item += checkout;
	}
	return in;
}

ostream& operator<<(ostream& out, const Student& item) {
	//we print in the format specified in the function spec in the pdf
	out << item.getID() << " " << item.firstName << " " << item.lastName << endl;
	out << item.numItems << endl;
	for (int i = 0; i < item.numItems; i++) {
		out << item.items[i] << " ";
	}
	out << endl;
	return out;
}

Student Student::operator+(const string& item) {
	//we create a new student and initalize it with the same ID and names
	Student student2;
	student2 = Student(this->ID, this->firstName, this->lastName);
	//we loop through items and check them out for our new user
	for (int i = 0; i < numItems; i++) {
		student2.CheckOut(items[i]);
	}
	//then we check out the specified item and return the object
	student2.CheckOut(item);
	return student2;
}

void Student::operator+=(const string& item) {
	//we checkout in place like so
	this->CheckOut(item);
}

bool Student::operator==(Student& item) {
	//we check if the IDs match
	if (item.ID == this->ID) { return true; }
	return false;
}

bool Student::operator!=(Student& item) {
	//same as == but with flipped return
	if (item.ID == this->ID) { return false; }
	return true;
}
/*Rigged this up as an equivalent to assignment, for copying in
//our dynamic student array
Student Student::operator*=(const Student& item) {
	//Student newStudent;
	//newStudent = Student(item.ID, item.firstName, item.lastName);
	ID = item.ID;
	firstName = item.firstName;
	lastName = item.lastName;
	arraySize = item.arraySize;
	numItems = item.numItems;
	items = new string[arraySize];
	for (int i = 0; i < numItems; i++) {
		items[i] = item.items[i];
	}
	return *this;
	//cout << *this;
}
*/