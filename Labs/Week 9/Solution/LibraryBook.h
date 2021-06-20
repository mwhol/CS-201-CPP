// Mike Wholey
// 10/16/2018
// Lab #9

// Ensure class isn't added more than once
#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
using namespace std;

class LibraryBook
{
private:
	string title;
	string author;
	string ISBN;
	bool checkedOut;

public:
	LibraryBook();
	LibraryBook(string bookTitle, string bookAuthor, string bookISBN);

	string getTitle();
	string getAuthor();
	string getISBN();

	void checkOut();
	void checkIn();
	bool isCheckedOut();
};

#endif