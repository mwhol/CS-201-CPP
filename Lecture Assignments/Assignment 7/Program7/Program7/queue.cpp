// MIKE WHOLEY
// 12/12/2018
// PROGRAM 7


#include "pch.h"
#include <string>
#include "queue.h"
#include <iostream>

using namespace std;

//helper function which prints a patient
void printPatient(patient p) {
	cout << "Patient: ";
	cout << p.firstName << " " << p.lastName << endl;
	cout << "Social Security Number: " << p.socSecNum << endl << endl;
}

//helper function which will get input from the user and create a patient
patient buildPatient() {
	patient p;
	cout << "Patient's first name: ";
	cin >> p.firstName;
	cout << "Patient's last name: ";
	cin >> p.lastName;
	cout << "Patient's social security number: ";
	cin >> p.socSecNum;
	p.next = nullptr;
	cout << endl;
	return p;
}

//basic queue creation
queue::queue() {
	head = nullptr;
	tail = nullptr;
	patients = 0;
	critPatients = 0;
}

//basic code to add a patient, special case if
//the it is the first patient in the queue
void queue::addPatient(patient* newP) {
	if (patients == 0) {
		head = newP;
		tail = newP;
	}
	else {
		tail->next = newP;
		tail = newP;
	}
	patients++;
}

//code to add a critical patient
void queue::addCritPatient(patient* newP) {
	patient *temp;
	temp = head;
	int i;

	//if no other critical patients, add it to head
	if (critPatients == 0) {
		head = newP;
		newP->next = temp;
	}

	//otherwise we enter a basic loop to find the last critical patient
	//then we do a basic insertion using our temporary pointer
	else {
		for (i = 1; i < critPatients; i++) {
			temp = temp->next;
		}
		newP->next = temp->next;
		temp->next = newP;
	}
	//make sure to keep these variables in the right state
	patients++;
	critPatients++;
}

//basic helper
int queue::size() {
	return patients;
}

void queue::takePatient() {
	//if patients in queue then we print the patient, delete the head, then reassign
	//the head to the new patient at the front of the queue
	if (patients > 0) {
		patient *temp;
		temp = head->next;
		cout << "Patient moved to OR" << endl;
		printPatient(*head);
		delete head;
		head = temp;
		patients--;
		if (critPatients > 0) { critPatients--; }
	}
	//if no patients, print a helpful message
	else {
		cout << "The queue is currently empty." << endl << endl;
	}
}

void queue::printQueue() {
	patient *temp;
	temp = head;
	//basic loop utilizin printPatient helper function
	for (int i = 0; i < patients; i++) {
		printPatient(*temp);
		temp = temp->next;
	}
}

void queue::cancelPatient(patient P) {
	patient *temp, *prev;
	int i;
	temp = head;
	prev = nullptr;

	for (i = 0; i < patients; i++) {
		if (temp->firstName == P.firstName &&
			temp->lastName == P.lastName &&
			temp->socSecNum == P.socSecNum) {
			//special case when we're cancelling the head
			if (i == 0) {
				temp = head;
				head = head->next;
				delete temp;
			}
			//otherwise we do normal deletion
			else {
				prev->next = temp->next;
				delete temp;
			}
			//fixing the tail if we delete the last element
			if (i == (patients - 1)) {
				tail = prev;
			}
			patients--;
			if (i < critPatients) {
				critPatients--;
			}
			cout << "Patient removed." << endl << endl;
			i = -1;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	//sentinel value conditional if not found
	if (i != -1) {
		cout << "Patient not found." << endl << endl;
	}
}