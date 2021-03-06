// MIKE WHOLEY
// 12/12/2018
// PROGRAM 7

#include "pch.h"
#include <string>
#include <iostream>
#include "queue.h"

using namespace std;

//Helper function which prints our first menu,
//asks for input and returns that input
int menuPrint() {
	int i = 0;
	while (i < 1 || i > 4) {
		cout << "                    Welcome to Starling City Hospital" << endl;
		cout << "1: Heart clinic" << endl;
		cout << "2: Lung clinic" << endl;
		cout << "3: Plastic surgery" << endl;
		cout << "4: Exit" << endl;
		cout << "Please enter your choice: ";
		cin >> i;
		//basic check for if user entered good input
		if (i < 1 || i > 4) {
			cout << endl << "Please try again" << endl << endl;
		}
	}
	cout << endl;
	return i;
}

//Helper function which prints our second menu,
//asks for input and returns that input
int menu2Print(string department) {
	int j = 0;
	while (j < 1 || j > 6) {
		cout << "Welcome to " << department << endl;
		cout << "1: Add patient" << endl;
		cout << "2: Add critically ill patient" << endl;
		cout << "3: Take out patient for operation" << endl;
		cout << "4: Cancel patient" << endl;
		cout << "5: List the queue of patients" << endl;
		cout << "6: Change department or exit" << endl;
		cout << "Please enter your choice: ";
		cin >> j;
		//basic check for if input is good or not
		if (j < 1 || j > 6) {
			cout << endl << "Error try again" << endl << endl;
		}
	}
	cout << endl;
	return j;
}

int main() {
	//pointers galore! we have a lot of variables here
	//because we are tracking the state of several queues
	int choice = 0, choice2 = 0;
	queue heart, lung, plastic;	
	patient *p;
	queue *patientQueue = &heart;
	string department;

	//we enter our first while loop
	while (choice != 4) {
		choice = menuPrint();
		
		//after input we set our few important vars depending
		//on the user's choice
		if (choice == 1) {
			patientQueue = &heart;
			department = "the Heart Clinic";
		}
		if (choice == 2) {
			patientQueue = &lung;
			department = "the Lung Clinic";
		}
		if (choice == 3) {
			patientQueue = &plastic;
			department = "the Plastic Surgery Department";
		}

		//then we go to the second menu
		while (choice != 4 && choice2 != 6) {
			choice2 = menu2Print(department);

			if (choice2 == 1) {
				//we create a new patients and call addPatient on it
				//to add it to the back of the queue
				p = new patient;
				*p = buildPatient();
				patientQueue->addPatient(p);
			}
			if (choice2 == 2) {
				//we build a new patient but this time we 
				//call the function specifically for critical patients
				p = new patient;
				*p = buildPatient();
				patientQueue->addCritPatient(p);
			}
			if (choice2 == 3) {
				//we just call the takePatient function
				patientQueue->takePatient();
			}
			if (choice2 == 4) {
				//if the user wants to cancel a patient, we ask for input
				//via the buildPatient function, then pass that patient
				//to the queue through the cancel function which does the
				//rest of the work for us
				p = new patient;
				*p = buildPatient();
				patientQueue->cancelPatient(*p);
			}
			if (choice2 == 5) {
				//we do a basic check on whether there *are* patients
				if (patientQueue->size() == 0) {
					cout << endl << "The queue is currently empty." << endl << endl;
				}
				//if there are we print a header and then call printQueue function
				else {
					cout << endl << "        PATIENT QUEUE" << endl;
					patientQueue->printQueue();
				}
			}
			//here we use break to go up to higher while loop
			if (choice2 == 6) {
				choice2 = -1;
				break;
			}
		}
	}
	return 0;
}
