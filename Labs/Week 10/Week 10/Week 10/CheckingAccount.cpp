// MIKE WHOLEY
// 10/23/2018
// Lab 10


#include "stdafx.h"
#include "Account.h"
#include "CheckingAccount.h"

// Constructor
CheckingAccount::CheckingAccount(int newAccountNum)
{
	accountNum = newAccountNum;
	type = "Checking";
}

// Applies an interest rate to the balance
void CheckingAccount::accrueInterest()
{
	balance = balance;
}

