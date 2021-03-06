// ProgramThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void printCustomersData(const int id[], const string first[], const string last[], const double before_Discount[], int size);
void printNames(const int id[], const string first[], const string last[], int size);
void printTotal(const int id[], const double before_Discount[], int size);
void printMenu();


int main() {
	//here we declare our arrays
	const int size = 10;
	int id[size];
	string first[size];
	string last[size];
	double before_Discount[size];
	//helper vars for our loop and input
	bool contin = true;
	char option;

	//reading in our file
	ifstream fin;
	fin.open("input.txt");

	//for the size of our input we loop through each line and read it in
	//"5. Read and store the data from the input file in your arrays using a single “for” loop."
	for (int i = 0; i < size; i++) {
		if (fin.good()) {
			fin >> id[i] >> first[i] >> last[i] >> before_Discount[i];
		}
		//if the file isn't good we print an error for the user
		else {
			cout << "FILE READING ERROR, TRY AGAIN" << endl;
			break;
		}
	}

	//while the user wants to continue we loop
	while (contin) {
		printMenu();
		cin >> option;

		//after printing the menu and reading in the user's input we enter
		// a big switch case depending on the char, each of the three options
		//calls the function associated with it and then breaks
		switch (option) {
		case '1':
			printCustomersData(id, first, last, before_Discount, size);
			break;
		case '2':
			printNames(id, first, last, size);
			break;
		case '3':
			printTotal(id, before_Discount, size);
			break;
		case '4':
		case 'q':
		case 'Q':
			cout << endl << "Thanks for using my program. Goodbye!!" << endl;
			contin = false;
			break;
			//if the user's input is bad we let them now and then try again
		default:
			cout << endl << "Wrong input. Try again..." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}



void printCustomersData(const int id[], const string first[], const string last[], const double before_Discount[], int size) {
	//This function prints all the data from the input file
	//we use setw and left to get our columns formatted correctly
	cout << setw(10) << left << "Trans_ID";
	cout << setw(10) << left << "First";
	cout << setw(15) << left << "Last";
	cout << setw(10) << left << "Before Discount" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(10) << left << id[i];
		cout << setw(10) << left << first[i];
		cout << setw(15) << left << last[i];
		//setprecision to print doubles correctly
		cout << left << fixed << setprecision(2) << before_Discount[i];
		cout << endl;
	}
}


void printNames(const int id[], const string first[], const string last[], int size) {
	//here we print data but not the price, similar to the previous function
	cout << setw(10) << left << "Trans_ID";
	cout << setw(10) << left << "First";
	cout << setw(10) << left << "Last" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(10) << left << id[i];
		cout << setw(10) << left << first[i];
		cout << left << last[i];
		cout << endl;
	}
}

void printTotal(const int id[], const double before_Discount[], int size) {
	cout << setw(10) << left << "Trans_ID";
	cout << setw(20) << left << "Before Discount";
	cout << setw(10) << left << "After Discount" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(10) << left << id[i];
		cout << setw(20) << left << fixed << setprecision(2) << before_Discount[i];
		//The discount is 40% so we multiply by 60% to calculate the number
		cout << left << fixed << setprecision(2) << before_Discount[i] * 0.6;
		cout << endl;
	}
}

void printMenu() {
	//this helper function prints the menu
	cout << "1. Print all customers data" << endl;
	cout << "2. Print names and Transaction ID" << endl;
	cout << "3. Print total before and after discount applied" << endl;
	cout << "4. Enter q/Q to quit" << endl << endl;
	cout << "Enter your choice or 'q' to quit: ";
}