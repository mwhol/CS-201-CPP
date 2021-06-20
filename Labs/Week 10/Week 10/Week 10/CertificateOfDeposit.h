// MIKE WHOLEY
// 10/23/2018
// Lab 10

#include "Account.h"

// Prevent multiple includes of this class
#ifndef CERTIFICATEOFDEPOSIT_H
#define CERTIFICATEOFDEPOSIT_H

class CertificateOfDeposit : public Account
{
private:
	bool hasWithdrawn;
public:
	// Constructor
	CertificateOfDeposit(int newAccountNum);
	
	// Applies an interest rate to the balance
	void accrueInterest();
	// Removes money from the bank account
	void withdrawal(float amount);
};

#endif
