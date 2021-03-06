//MIKE WHOLEY
//LAB 12
//11/6/2018

#include "stdafx.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//we just loop and push back characters
void fillList(list<char> &thelist, string toadd) {
	for (int i = 0; i < toadd.length(); i++) {
		thelist.push_back(toadd[i]);
	}
}

//we use an iterator to loop through the list and print in the proper formatting
void printList(list<char> &thelist, ostream& out) {
	for (list<char>::iterator it = thelist.begin(); it != thelist.end(); it++) {
		out << "[" << *it << "] -> ";
	}
	out << 0 << endl;
}

void removeCharacter(list<char> &thelist, char toremove) {
	list<char>::iterator it = thelist.begin();
	//while loop necessary because we are changing our list during iteration
	while (it != thelist.end()) {
		if (*it == toremove) {
			//have to reassign
			it = thelist.erase(it);
		}
		//only iterate up if we didn't delete a character
		else { it++; }
	}
}



int main() {
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	list<char> mylist;
	string myline;

	while (fin.good()) {
		//read in the line and then check if it is "END"
		getline(fin, myline);
		if (myline == "END") {
			break;
		}
		//first we fill the list, then we delete the vowels
		fillList(mylist, myline);
		removeCharacter(mylist, 'A');
		removeCharacter(mylist, 'E');
		removeCharacter(mylist, 'I');
		removeCharacter(mylist, 'O');
		removeCharacter(mylist, 'U');
		removeCharacter(mylist, 'a');
		removeCharacter(mylist, 'e');
		removeCharacter(mylist, 'i');
		removeCharacter(mylist, 'o');
		removeCharacter(mylist, 'u');
		//now we print the list, clear it and add an extra newline to match the formatting
		printList(mylist, fout);
		mylist.clear();
		fout << endl;
	}

    return 0;
}

