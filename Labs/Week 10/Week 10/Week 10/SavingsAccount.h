// MIKE WHOLEY
// 10/23/2018
// Lab 10


#include "Account.h"

// Prevent multiple includes of this class
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount : public Account
{
public:
	// Constructor
	SavingsAccount(int newAccountNum);
	
	// Applies an interest rate to the balance
	void accrueInterest();
};

#endif
