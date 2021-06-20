// MIKE WHOLEY
// 10/23/2018
// Lab 10


#include "Account.h"

// Prevent multiple includes of this class
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
public:
	// Constructor
	CheckingAccount(int newAccountNum);

	// Applies an interest rate to the balance
	void accrueInterest();
};

#endif
