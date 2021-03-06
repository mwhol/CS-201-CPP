//MIKE WHOLEY
//ASSIGNMENT 4
//10/22/2018

//I WOULD VERY MUCH LIKE TO KNOW WHAT THE CODE TO PROPERLY HANDLE
//THE DYNAMIC ARRAY OF STUDENTS LOOKS LIKE. I RAN INTO LOTS OF PROBLEMS
//WHEN TRYING TO COPY OVER THE DYNAMIC STRING ARRAY (ARRAY OF ITEMS) 
//FROM A STUDENT IN THE OLD ARRAY TO A STUDENT IN THE NEW ARRAY

#include "pch.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	//we need a bunch of vars
	int count = 0;
	int studentCount = 0;
	int arraySize = 50;
	ifstream studentsFile, checkoutFile, checkinFile;
	ofstream outFile;
	Student* studentArray;
	Student* newArray;
	string checkout, checkin;
	int ID;

	//we open our file and while it's good we read data into
	//student objects in an array
	studentArray = new Student[arraySize];
	studentsFile.open("Students.txt");
	while (studentsFile.good()) {
		/*if (studentCount == arraySize-1) {
			//Student* newArray[arraySize + 5];
			newArray = new Student[arraySize + 5];
			for (int i = 0; i < arraySize; i++) {
				newArray[i] *= studentArray[i];
				//cout << newArray[i];
			}
			delete[] studentArray;
			studentArray = newArray;
			arraySize += 5;
		}*/
		studentsFile >> studentArray[count];
		if (studentArray[count].getID() >= 1000 && studentArray[count].getID() <= 100000) {
			count++;
			studentCount++;
		}
	}
	studentsFile.close();

	//next we open up our checkouts file, we read the ID and
	//item in and then we search through the array for the
	//correct student and check the item out
	checkoutFile.open("checkouts.txt");
	while (checkoutFile.good()) {
		checkoutFile >> ID >> checkout;
		for (int i = 0; i < studentCount; i++) {
			if (studentArray[i].getID() == ID) {
				studentArray[i] += checkout;
				break;
			}
		}
	}
	checkoutFile.close();

	//we repeats the checkouts process but this time for checkins
	checkinFile.open("checkins.txt");
	while (checkinFile.good()) {
		checkinFile >> checkin;
		for (int i = 0; i < studentCount; i++) {
			if (studentArray[i].HasCheckedOut(checkin)) {
				studentArray[i].CheckIn(checkin);
				break;
			}
		}
	}
	checkinFile.close();

	//now that we've read all of our files, we output and end
	outFile.open("Updated_Students.txt");
	for (int i = 0; i < studentCount; i++) {
		outFile << studentArray[i];
	}
	outFile.close();

	return 0;
}
