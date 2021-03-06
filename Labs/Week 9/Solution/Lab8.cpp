// Mike Wholey
// 10/16/2018
// Lab #9

#include "stdafx.h"
#include "LibraryBook.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	// File stream variables
	ifstream finBooks("books.txt");
	ifstream finISBN("isbns.txt");
	ofstream fout("checkedout.txt");

	// Check for file errors first
	if (!finBooks || !finISBN)
	{
		cout << "Error opening input files!\n";
		system("pause");
		return 1;
	}


	//basic declarations including array of books
	string title, author, ISBN;
	int count = 0;
	LibraryBook bookArray[10];

	//while we loop we create LibraryBook objects and append them to our array
	while (finBooks.good()) {
		getline(finBooks, title);
		getline(finBooks, author);
		getline(finBooks, ISBN);

		bookArray[count] = LibraryBook(title, author, ISBN);
		count++;
	}

	
	while (finISBN.good()) {
		finISBN >> ISBN;
		//first we read our ISBN and then we loop through array looking
		//for matching book, enter a conditional to change book status and
		//then do so
		for (int i = 0; i < 10; i++) {
			if (bookArray[i].getISBN() == ISBN) {
				if (bookArray[i].isCheckedOut()) { bookArray[i].checkIn(); }
				else { bookArray[i].checkOut(); }
			}
		}
	}

	//print header
	fout << "Books checked out:" << endl << "------------------" << endl << endl;
	fout << "Title\tAuthor\tISBN" << endl;

	//loop through array of books, checking if each is checked out or not
	//if it is then we print out the books information tab separated
	for (int i = 0; i < 10; i++) {
		if (bookArray[i].isCheckedOut()) {
			fout << bookArray[i].getTitle() << "\t";
			fout << bookArray[i].getAuthor() << "\t";
			fout << bookArray[i].getISBN() << "\t" << endl;
		}
	}

	// Close the files at the end
	finBooks.close();
	finISBN.close();
	fout.close();

	// End program
	return 0;
}
