// LAB13
// MIKE WHOLEY
// RICHARD SCHNEIDER
// PIZZA PRICING PROBLEM
// 11/13/2018

#include "stdafx.h"
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	int arraySize;

	//open for input/output
	fin.open("inputpizza.txt");
	fout.open("outputpizza.txt");

	int counter = 0;
	while (fin.good()) {
		double max = 0;
		double current;
		int index;

		//read in number of pizzas
		fin >> arraySize;
		//check for end of file
		if (arraySize == 0) { break; }
		//new dynamic array to hold pizza info
		int* diamArray = new int[arraySize];
		int* priceArray = new int[arraySize];

		//read pizza info to arrays
		for (int i = 0; i < arraySize; i++) {
			fin >> diamArray[i] >> priceArray[i];
		}
		
		//calculate square inches per dollar, keep track of max and index
		for (int i = 0; i < arraySize; i++) {
			current = ((diamArray[i]/2.0) * (diamArray[i] / 2.0) * 3.14159) / priceArray[i];
			if (current > max) { max = current; index = i; }	
		}

		//output the best pizzas!
		fout << "Menu " << counter+1 << ": " << diamArray[index] << endl;
		counter++;
	}

	fin.close();
	fout.close();

    return 0;
}

