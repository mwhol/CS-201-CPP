// MIKE WHOLEY
// 10/23/2018
// Lab 10

#include "stdafx.h"
#include "Account.h"
#include "CertificateOfDeposit.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Stores up to 30 accounts
	Account* accounts[30];
	// Number of accounts that have been opened
	int numAccounts = 0;

	// For file input processing
	string command, acctType;
	int acctNum1, acctNum2;
	double amount;

	// Do the input and math
	while(fin >> command)
	{
		if(command == "NEW") {
			fin >> acctType;
			fin >> acctNum1;
			//we check the type of the account then create it and assign it to the array
			if (acctType == "CHECKING") {
				accounts[numAccounts] = new CheckingAccount(acctNum1);
			}
			else if (acctType == "SAVINGS") {
				accounts[numAccounts] = new SavingsAccount(acctNum1);
			}
			else if (acctType == "CERTIFICATE") {
				accounts[numAccounts] = new CertificateOfDeposit(acctNum1);
			}
			numAccounts += 1;
        }


		else if (command == "WITHDRAWAL") {
			//subtract money from an account
			fin >> acctNum1;
			fin >> amount;
			for (int i = 0; i < numAccounts; i++) {
				if (accounts[i]->getAccountNum() == acctNum1) {
					accounts[i]->withdrawal(amount);
				}
			}


        }
		else if (command == "DEPOSIT") {
			// Add money to an account
			fin >> acctNum1;
			fin >> amount;
			for (int i = 0; i < numAccounts; i++) {
				if (accounts[i]->getAccountNum() == acctNum1) {
					accounts[i]->deposit(amount);
				}
			}
            
		}
		else if (command == "TRANSFER") {
			// Move money from one account to another
			fin >> acctNum1;
			fin >> acctNum2;
			fin >> amount;
			//loop through both accounts, withdraw from the first and deposit to the second
			for (int i = 0; i < numAccounts; i++) {
				if (accounts[i]->getAccountNum() == acctNum1) {
					accounts[i]->withdrawal(amount);
				}
			}
			for (int i = 0; i < numAccounts; i++) {
				if (accounts[i]->getAccountNum() == acctNum2) {
					accounts[i]->deposit(amount);
				}
			}
		}

		else if (command == "INTEREST")
		{
			// Calculate interest on all accounts
			for (int i = 0; i < numAccounts; i++) {
				accounts[i]->accrueInterest();
			}

        }
    }
	// Print output
	fout << "BANK STATEMENT" << endl << endl;

	for(int i = 0; i < numAccounts; i++)
	{
		fout << "Account number: " << accounts[i]->getAccountNum() << endl;
		fout << "Type of account: " << accounts[i]->getAccountType() << endl;
		fout << "Balance: $" << accounts[i]->getBalance() << endl;
		fout << endl;
	}
    
    // Delete accounts
	for (int i = 0; i < numAccounts; i++)
		delete accounts[i];

    // Close files
    fin.close();
    fout.close();
    return 0;
}