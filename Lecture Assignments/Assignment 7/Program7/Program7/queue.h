// MIKE WHOLEY
// 12/12/2018
// PROGRAM 7

#include "pch.h"
#include <string>


#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

//basic struct
struct patient {
	string firstName;
	string lastName;
	int socSecNum;
	patient* next;
};

//two helper functions
void printPatient(patient p);
patient buildPatient();

class queue {
public:
	queue();
	void addPatient(patient* newP);
	void addCritPatient(patient* newP);
	void takePatient();
	void printQueue();
	void cancelPatient(patient P);
	int size();

private:
	patient *head, *tail;
	int patients, critPatients;
};



#endif