// Your Name
// Today's date
// Lab 10

#include "stdafx.h"
#include "Account.h"
#include "CertificateOfDeposit.h"

// Constructor
CertificateOfDeposit::CertificateOfDeposit(int newAccountNum)
{
	accountNum = newAccountNum;
	hasWithdrawn = false;
	type = "Certificate of Deposit";
}

// Applies an interest rate to the balance
void CertificateOfDeposit::accrueInterest()
{
	if (hasWithdrawn == false) { balance *= 1.1; }
	else { balance *= 1.01; }
}

// Removes money from the bank account
void CertificateOfDeposit::withdrawal(float amount)
{
	balance -= amount;
	hasWithdrawn = true;
}
