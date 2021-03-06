// Lab 14
// MIKE WHOLEY
// CS 201L
// We loop through all three input files to get our data into arrays
// then we run a test harness on each array to make sure our templated
// functions work correctly - they do.

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//Basic swapping function using a temp variable
template <class T>
void mySwap(T array[], int posOne, int posTwo) {
	T swapKey;
	swapKey = array[posOne];
	array[posOne] = array[posTwo];
	array[posTwo] = swapKey;
}

//basic Max finder
template <class T>
T myMin(T array[]) {
	T myMin = array[0];
	for (int i = 0; i < 100; i++) {
		if (array[i] < myMin) { myMin = array[i]; }
	}
	return myMin;
}

template <class T>
T myMax(T array[]) {
	T myMaxVal = array[0];
	for (int i = 0; i < 100; i++) {
		if (array[i] > myMaxVal) { myMaxVal = array[i]; }
	}
	return myMaxVal;
}

template <class T>
int mySearch(T array[], T toFind) {
	for (int i = 0; i < 100; i++) {
		if (array[i] == toFind) { return i; }
	}
	return -1;
}

//Helper function which prints what is needed to the file
template <class T>
void testAndPrint(T array[], string title, ofstream& out, T findOne, T findTwo) {
	out << title << ":" << endl;
	out << "Swapped items at positions 10 and 20" << endl;

	out << "Before: [10] " << array[10] << " [20] " << array[20] << endl;
	mySwap(array, 10, 20);
	out << "After: [10] " << array[10] << " [20] " << array[20] << endl;

	out << "Minimum: " << myMin(array) << endl;
	out << "Maximum: " << myMax(array) << endl;

	out << "The value " << findOne << " is at position " << mySearch(array, findOne) << endl;
	out << "The value " << findTwo << " is at position " << mySearch(array, findTwo) << endl << endl;
}



int main() {

	ifstream intFile, doubleFile, stringFile;
	ofstream outFile;

	//read ints into array
	intFile.open("integers.txt");
	int intArray[100];
	for (int i = 0; i < 100; i++) {
		intFile >> intArray[i];
	}
	intFile.close();

	//read doubles into array
	doubleFile.open("doubles.txt");
	double doubleArray[100];
	for (int i = 0; i < 100; i++) {
		doubleFile >> doubleArray[i];
	}
	doubleFile.close();

	//read strings into array
	stringFile.open("strings.txt");
	string stringArray[100];
	for (int i = 0; i < 100; i++) {
		stringFile >> stringArray[i];
	}
	stringFile.close();

	//open the outFile
	outFile.open("outfile.txt");

	//If we don't declare these and pass directly, they get imputed to
	//char arrays and so break the template function
	string findOne = "Shoes";
	string findTwo = "Pumpkin";

	//We pass the relevant information to our harness three times,
	//it will print the relevant data to the outFile
	testAndPrint(intArray, "Integers", outFile, 1, 5);
	testAndPrint(doubleArray, "Doubles", outFile, 4.62557, 1.23456);
	testAndPrint(stringArray, "Strings", outFile, findOne, findTwo);

	outFile.close();

    return 0;
}

