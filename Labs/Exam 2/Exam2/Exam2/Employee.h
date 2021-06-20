// MIKE WHOLEY
// EXAM 2 - FINAL
// 12/4/2018

#include "stdafx.h"
#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
private:
	string name;
	double balance;
	double payRate;
	//helper variable for isEmployed()
	bool fired;

public:
    // Constructor
	Employee(string myName = "")
	{
		name = myName;
		balance = 0;
		payRate = 10;
		fired = false;
	}

    // Getter to return the current pay rate
	double getPayRate()
	{
		return payRate;
	}

    // Getter to return the current amount of pay earned
	double getBalance()
	{
		return balance;
	}

    // Getter to get Employee's name
	string getName()
	{
		return name;
	}

    // Function to give the raise. It takes in a percent in whole numbers 
    // (ex: 5 for 5%)
	void giveRaise(int rate)
	{
		payRate = payRate * (1.0 + (rate / 100.0));
	}

    // Pays the employee
	void pay()
	{
		//we verify employment status first
		if (!fired) {
			balance += payRate;
		}
	}

    // Fires the Employee
	void fire()
	{
		fired = true;
	}

    // Returns if the Employee is currently employed
	bool isEmployed()
	{
		return !fired;
	}

};

#endif