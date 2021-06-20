// Your name
// Today's date
// Lab #6

#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

// Forward declaration for calcDistance function
double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2);


int main()
{
    // File input/output variables
	ifstream fin("input.txt");
	ofstream fout("output.txt");

    // If we can't find the input file, quit with error message.
	if(!fin)
	{
		cout << "Input file not opened!" << endl;
		exit(1);
	}






    // Close our files to ensure we save our data
	fin.close();
	fout.close();

    // End program
	return 0;
}


double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}