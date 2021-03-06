/*
MIKE WHOLEY
CS 201R
MOHAMED GHARIBI
ASSIGNMENT 2
ALGO:
	FIRST WE ASK THE USER FOR THE YEAR
	THEN WE ASK THE USER FOR THE START DAY
	THEN WE LOOP 12 TIMES, CALLING PRINTONEMONTH
		EACH TIME, WE KEEP TRACK OF THE ENDING DAY OF
		EACH MONTH SO THAT WE CAN CORRECTLY CALCULATE
		THE START DAY OF THE NEXT MONTH
	AS WE LOOP WE PRINT OUT EACH MONTH TO THE USER
*/

#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void PrintOneMonth(int MonthNumber, int Year, int StartDayNumber);
int DaysPerMonth(int MonthNumber, int Year);
int GetStartDayNumber();
int GetYear();
string caps(string lowerCase);


int main() {
	int year;
	int day;

	//First we get the year and day from the user
	year = GetYear();
	day = GetStartDayNumber();
	//then we start looping, we go through each month
	for (int i = 0; i < 12; i++) {
		//and print the month
		PrintOneMonth(i, year, day);
		//then calculate the starting day that we need to
		//pass to the next call of PrintOneMonth
		day = (((DaysPerMonth(i, year) % 7) + day) % 7);
	}
	return 0;
}

string caps(string lowerCase) {
	//we loop through the string and call toupper on each
	//character, capitalizing it
	for (int i = 0; i < lowerCase.length(); i++) {
		lowerCase[i] = static_cast<char> (toupper(lowerCase[i]));
	}
	return lowerCase;
}

void PrintOneMonth(int MonthNumber, int Year, int StartDayNumber) {
	int count = 0;
	int i;

	//first we grab the number of days for the month
	int monthDays = DaysPerMonth(MonthNumber, Year);

	//Then we print the header, admittedly the centering code here (setw) is a bit ugly
	if (MonthNumber == 0) { cout << setw(21 + (5 + 7) / 2) << "JANUARY " << Year << endl; }
	if (MonthNumber == 1) { cout << setw(21 + (5 + 8) / 2) << "FEBRUARY " << Year << endl; }
	if (MonthNumber == 2) { cout << setw(21 + (5 + 5) / 2) << "MARCH " << Year << endl; }
	if (MonthNumber == 3) { cout << setw(21 + (5 + 5) / 2) << "APRIL " << Year << endl; }
	if (MonthNumber == 4) { cout << setw(21 + (5 + 3) / 2) << "MAY " << Year << endl; }
	if (MonthNumber == 5) { cout << setw(21 + (5 + 4) / 2) << "JUNE " << Year << endl; }
	if (MonthNumber == 6) { cout << setw(21 + (5 + 4) / 2) << "JULY " << Year << endl; }
	if (MonthNumber == 7) { cout << setw(21 + (5 + 6) / 2) << "AUGUST " << Year << endl; }
	if (MonthNumber == 8) { cout << setw(21 + (5 + 9) / 2) << "SEPTEMBER " << Year << endl; }
	if (MonthNumber == 9) { cout << setw(21 + (5 + 7) / 2) << "OCTOBER " << Year << endl; }
	if (MonthNumber == 10) { cout << setw(21 + (5 + 8) / 2) << "NOVEMBER " << Year << endl; }
	if (MonthNumber == 11) { cout << setw(21 + (5 + 8) / 2) << "DECEMBER " << Year << endl; }

	//then we print the day headers
	cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;

	//we print tabs to get the first day of the month
	for (i = 0; i < StartDayNumber; i++) {
		cout << "\t";
		count++;
	}

	//then we enter a loop where we print each day of the month
	for (i = 1; i <= monthDays; i++) {
		cout << i << "\t";
		count++;
		//if we're on the last day of the week, we print a newline
		if (count == 7) {
			count = 0;
			cout << endl;
		}
	}
	cout << endl << endl;
}

int DaysPerMonth(int MonthNumber, int Year) {
	//big conditional to return number of days for each month
	if (MonthNumber == 0) { return 31; }
	//for february this is how we handle the leap years
	else if (MonthNumber == 1) {
		if (Year % 400 == 0) { return 29; }
		else if ((Year % 4 == 0) && (Year % 100 != 0)) { return 29;	}
		else { return 28; }
	}
	else if (MonthNumber == 2) { return 31; }
	else if (MonthNumber == 3) { return 30; }
	else if (MonthNumber == 4) { return 31; }
	else if (MonthNumber == 5) { return 30; }
	else if (MonthNumber == 6) { return 31; }
	else if (MonthNumber == 7) { return 31; }
	else if (MonthNumber == 8) { return 30; }
	else if (MonthNumber == 9) { return 31; }
	else if (MonthNumber == 10) { return 30; }
	else if (MonthNumber == 11) { return 31; }
}

int GetStartDayNumber() {
	//this function asks the user for input for a day and
	//uses our caps function to capitalize it.
	//each day maps to an int and that int is what we return
	string day;
	cout << "What day of the week does Jan 1 fall on this year? ";
	cin >> day;
	day = caps(day);
	if (day == "SUNDAY") { return 0; }
	else if (day == "MONDAY") { return 1; }
	else if (day == "TUESDAY") { return 2; }
	else if (day == "WEDNESDAY") { return 3; }
	else if (day == "THURSDAY") { return 4; }
	else if (day == "FRIDAY") { return 5; }
	else if (day == "SATURDAY") { return 6; }
	else {
		cout << "INCORRECT INPUT TRY AGAIN" << endl << endl;
		return GetStartDayNumber();
	}
}

int GetYear() {
	//We ask the user for an int in an appropriate range
	//if they provide it then we return that int, otherwise
	//we use a recursive call to ask the user again
	int year;

	cout << "Enter year (must be in range 1000 <= Year <= 9999): ";
	cin >> year;

	if ((year >= 1000) && (year <= 9999)) {
		return year;
	}
	else {
		//simple recursion, to get answer in range
		cout << "INCORRECT, TRY AGAIN" << endl;
		return GetYear();
	}
}