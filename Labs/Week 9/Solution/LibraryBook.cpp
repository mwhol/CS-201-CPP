// Mike Wholey
// 10/16/2018
// Lab #9

#include "stdafx.h"
#include "LibraryBook.h"
#include <string>

using namespace std;

LibraryBook::LibraryBook() {
	//default to not being checked out
	title = "";
	author = "";
	ISBN = "";
	checkedOut = false;
}

LibraryBook::LibraryBook(string bookTitle, string bookAuthor, string bookISBN) {
	//default is not checked out
	title = bookTitle;
	author = bookAuthor;
	ISBN = bookISBN;
	checkedOut = false;
}

//rest of these functions are obvious

string LibraryBook::getTitle() {
	return title;
}

string LibraryBook::getAuthor() {
	return author;
}
string LibraryBook::getISBN() {
	return ISBN;
}

bool LibraryBook::isCheckedOut() {
	return checkedOut;
}

void LibraryBook::checkOut() {
	checkedOut = true;
}
void LibraryBook::checkIn() {
	checkedOut = false;
}





