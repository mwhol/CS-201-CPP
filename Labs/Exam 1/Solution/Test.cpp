// MIKE WHOLEY
// 10/09/2018
// TEST #1

//According to instructions I did not create and/or use
//an overloaded +, <<, or >> operator.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

int main() {
    
	int row, col, value;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	//if the file is bad, we print and then since our while loop also uses .good()
	//we will just skip ahead to the end where we close the files
	if (!fin.good()) {
		cout << "THERE WAS AN ERROR OPENING THE INPUT FILE, PLEASE TRY AGAIN!";
	}

	//while our file is good we proceed
	while (fin.good()) {
		fin >> row >> col;

		Matrix one(row, col);
		Matrix two(row, col);
		Matrix three(row, col);

		//Here we enter three loops, the first two use our row and col knowledge to read in
		//our matrices, then the third loop loops through the arrays and adds together each
		//of their values at the same index, we then set that value in our third matrix which
		//we print out
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fin >> value;
				one.set(i, j, value);
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fin >> value;
				two.set(i, j, value);
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				//this would be much prettier using an overloaded +, apologies
				three.set(i, j, one.get(i, j) + two.get(i, j));
				fout << three.get(i, j) << "\t";
			}
			fout << "\n";
		}
		fout << "\n";
	}

	//closing the files
	fin.close();
	fout.close();

	return 0;

}

