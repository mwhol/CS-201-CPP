// MIKE WHOLEY
// 9/25/2018
// Lab #6

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Point.h"

using namespace std;

int main() {
	
	Point points1[20];
	Point points2[20];
	int index = 0;
	double x;
	double y;
	double z;
	
	// File input/output variables
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// If we can't find the input file, quit with error message.
	if (!fin)
	{
		cout << "Input file not opened!" << endl;
		exit(1);
	}

	//while more input
	while (fin.good()) {
		//Read data into our two points
		fin >> x >> y >> z;
		points1[index].setCoordinates(x, y, z);
		fin >> x >> y >> z;
		points2[index].setCoordinates(x, y, z);
		//Increase our index
		index++;
	}
	fin.close();

	
	fout << "Distances from origin:" << endl;
	//loop through our filled points, print distance of one then space then distance of two,
	//both from the origin
	for (int i = 0; i < index; i++) {
		fout << points1[i].calcDistance() << " " << points2[i].calcDistance() << endl;
	}

	fout << endl;
	fout << "Distances from each other:" << endl;
	
	//loop through our filled points, print distance between two
	for (int i = 0; i < index; i++) {
		fout << points1[i].calcDistance(points2[i]) << endl;
	}

	fout.close();

	// End program
	return 0;
}