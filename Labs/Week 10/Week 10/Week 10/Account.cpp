// MIKE WHOLEY
// 10/23/2018
// Lab 10


#include "stdafx.h"
#include "Account.h"


Account::Account()
{
	balance = 0.0;
}
	
int Account::getAccountNum()
{
	return accountNum;
}

string Account::getAccountType()
{
	return type;
}

double Account::getBalance()
{
	return balance;
}

void Account::deposit(double amount)
{
	balance += amount;
}

void Account::withdrawal(double amount)
{
	balance -= amount;
}
