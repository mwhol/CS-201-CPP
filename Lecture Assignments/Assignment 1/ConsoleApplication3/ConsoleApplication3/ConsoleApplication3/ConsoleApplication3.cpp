//Class: CS201R 0002
//Teacher: Mohamed Gharibi
//Student: Mike Wholey
//Assignment One

#include "pch.h"
#include <iostream>
using namespace std;

//out global variables
int option;
bool loopAgain = true;
char answer = 'Y';

//our functions
int printMenu();
int gradeScale();
int gradeCalc();

int main() {
	//main func, first we enter a simple while loop
	while (loopAgain) {
		//then we print our menu
		option = printMenu();
		//now we enter a switch for the user's input
		switch (option) {
		case 1:
			gradeScale();
			break;
		case 2:
			gradeCalc();
			break;
		case 3:
			loopAgain = false;
			continue;
		default:
			cout << endl << "*** INCORRECT INPUT, TRY AGAIN ***" << endl << endl;
			continue;
		}

		//ask the user if they would like to continue
		cout << "Do you want to have another transaction?" << endl;
		cin >> answer;
		//if they say yes we continue the while loop
		if ((answer == 'Y') || (answer == 'y')) {
			loopAgain = true;
		}
		//otherwise we exit the loop
		else { loopAgain = false; }
	}
	return 0;
}


int printMenu() {
	//Simple Function prints the menu, grabs what the user selects
	//and returns it
	cout << "Welcome to Grade system:" << endl;
	cout << "How can we help you today?" << endl;
	cout << "1. Grade Scale." << endl;
	cout << "2. Calculate your total % and Grade." << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice:" << endl;
	cin >> option;
	return option;
}

int gradeScale() {
	//Function for option two, we print the grade scale
	cout << "A: 90-100" << endl;
	cout << "B: 80-89" << endl;
	cout << "C: 69-79" << endl;
	cout << "D: 60-68" << endl;
	cout << "F: 0-59" << endl;
	return 0;
}

int gradeCalc() {
	int assignment;
	int examOne;
	int examTwo;
	int examFinal;
	int grade;
	//First we print and ask for input from the user
	cout << "Please enter your points in assignments, Exam1, Exam2, and Final Exam" << endl;
	cout << "Assignments out of 80:" << endl;
	cin >> assignment;
	cout << "Exam1 out of 80:" << endl;
	cin >> examOne;
	cout << "Exam2 out of 80:" << endl;
	cin >> examTwo;
	cout << "Final Exam out of 100:" << endl;
	cin >> examFinal;

	//then we calculate the grade and do some printing
	grade = ((assignment / 80.0) * 40) + ((examOne / 80.0) * 20) + ((examTwo / 80.0) * 20) + ((examFinal / 100.0) * 20);

	cout << "Your total grade percentage is " << grade << endl;

	cout << "Depending on Grade scale, your Grade is" << endl;

	//and then we use the grade in percentage points
	//and convert to a letter grade and print it
	if (grade >= 90) { cout << "A" << endl; }
	else if (grade >= 80) { cout << "B" << endl; }
	else if (grade >= 69) { cout << "C" << endl; }
	else if (grade >= 60) { cout << "D" << endl; }
	else { cout << "F" << endl; }

	return 0;
}