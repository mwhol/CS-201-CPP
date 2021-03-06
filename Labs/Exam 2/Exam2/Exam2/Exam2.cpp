// MIKE WHOLEY
// EXAM 2 - FINAL
// 12/4/2018

#include "stdafx.h"
#include "Employee.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;


//helper function which prints an employee in the format specified
void printEmployee(ofstream& out, Employee e, int ID) {
	//Basic info on the employee
	out << e.getName() << ", ID Number " << ID << ":" << endl;

	//here we print out their pay rate depending on whether they are fired or not
	if (e.isEmployed()) { out << "Current pay rate: $" << e.getPayRate() << endl; }
	else { out << "Not employed with the company." << endl; }

	//then we print our their total earnings
	out << "Pay earned to date: $" << e.getBalance() << endl;
}


int main() {
	//helper variables, hold our inputs and the map of employees
	Employee currEmployee;
	map <int, Employee> employeeMap;
	string command, firstName, lastName, name;
	int ID;
	int raise;

	ifstream fin("input.txt");
	
	//we loop through our input file looking for commands
	while (fin.good()) {
		fin >> command;

		//if we are to make a new employee, we read in the name, construct 
		//the employee and then add it to the map
		if (command == "NEW") {
			fin >> ID >> firstName >> lastName;
			name = firstName + " " + lastName;
			currEmployee = Employee(name);
			employeeMap.emplace(ID, currEmployee);
		}

		//if we are to give a raise then we hunt for the relevant ID number
		//and give them the percentage raise specified
		if (command == "RAISE") {
			fin >> ID >> raise;
			if (employeeMap.count(ID) == 1) {
				employeeMap[ID].giveRaise(raise);
			}
		}

		//to pay all the employees we loop through them and use the pay function
		//the pay function checks whether the employee is fired already so we don't
		//have to do that here
		if (command == "PAY") {
			for (map<int, Employee>::iterator it = employeeMap.begin(); it != employeeMap.end(); it++) {
				it->second.pay();
			}			
		}

		//to fire the employee we look for them, and call the fire function on them
		if (command == "FIRE") {
			fin >> ID;
			if (employeeMap.count(ID) == 1) {
				employeeMap.at(ID).fire();
			}

		}
	}
	fin.close();

	//to print to our output file we iterate through the map, and pass each employee and ID
	//to our helper function which handles all the formatting
	ofstream fout("output.txt");
	for (map<int, Employee>::iterator it = employeeMap.begin(); it != employeeMap.end(); it++) {
		printEmployee(fout, it->second, it->first);
		fout << endl;
	}
	fout.close();

	//Then we close the file and we're all done. Thank you for a great semester! (:

    return 0;
}

