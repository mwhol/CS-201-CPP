#include "pch.h"
#include <string>
#include <fstream>
#include <iostream>


#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
public:

	Student();
	Student(int ID, string firstName, string lastName);
	~Student();

	string getFirstName() const;
	string getLastName() const;
	int getID() const;

	void setFirstName(string name);
	void setLastName(string name);
	void setID(int num);

	int CheckoutCount();
	bool CheckOut(const string& item);
	bool CheckIn(const string& item);
	bool HasCheckedOut(const string& item);
	void Clear();

	friend istream& operator>>(istream& in, Student& item);
	friend ostream& operator<<(ostream& out, const Student& item);

	Student operator+(const string& item);
	void operator+=(const string& item);
	bool operator==(Student& item);
	bool operator!=(Student& item);
	//Student operator*=(const Student& item);


private:
	string firstName, lastName;
	int ID, numItems;
	int arraySize;
	string* items;
};

#endif