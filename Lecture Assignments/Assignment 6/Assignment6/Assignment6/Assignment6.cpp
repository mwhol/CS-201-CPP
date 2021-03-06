// MIKE WHOLEY
// ASSIGNMENT 6
// 11/17/2018

#include "pch.h"
#include <iostream>

using namespace std;

//   A
int LHSfunc(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) { sum += i * i; }
	return sum;
}

int RHSfunc(int n) {
	if (n < 0) { cout << "Please enter a positive number." << endl; }
	if (n == 1) { return 1; }
	return n * n + RHSfunc(n - 1);
}

//   B

/*int arrayBuilder(int* array) {
	//int* array;
	int* array2;
	int number = 0;
	int size = 5;
	int count = 0;
	array = new int[size];

	//first we build up ur array
	cout << "Enter numbers, when you are done, enter the number '-1'" << endl;
	cin >> number;
	while (number != -1) {
		//cin >> number;
		array[count] = number;
		count++;

		if (count == size) {
			array2 = new int[size + 5];
			for (int i = 0; i < size; i++) {
				array2[i] = array[i];
			}
			delete[] array;
			array = array2;
			size += 5;
		}
		cin >> number;
	}
	return count;
}

*/

void arrayReverse(int* array, int size) {
	int temp;
	//in the base case (size == 1) we don't do anything so we just exclude it
	if (size > 1) {
		//iterating through the array and swapping
		temp = array[size - 1];
		array[size - 1] = array[0];
		array[0] = temp;
		arrayReverse(array + 1, size - 2);
	}
}


void printArray(int* array, int size) {
	//just a helper for getting the formatting right
	cout << '(';
	for (int i = 0; i < size - 1; i++) {
		cout << array[i] << ',';
	}
	cout << array[size - 1] << ')';
}



int main() {
	int n;

	// A
	cout << "Input an number: ";
	cin >> n;
	cout << "Using the left hand side formula (non-recursive) we have the answer: " << LHSfunc(n) << endl;
	cout << "Using the right hand side formula (recursive) we have the answer: " << RHSfunc(n) << endl;
	if (LHSfunc(n) == RHSfunc(n)) {
		cout << "Yay both sides are equal!" << endl;
	}
	else { cout << "Oh no, I've messed up my program!" << endl; }

	cout << endl;

	// B
	int* array;
	int* array2;
	int number;
	int size = 5;
	int count = 0;
	array = new int[size];

	//first we build up ur array
	cout << "Enter numbers, when you are done, enter the number '-1'" << endl;
	cin >> number;
	while (number != -1) {
		array[count] = number;
		count++;
		//increasing the size of our array
		if (count == size) {
			array2 = new int[size + 5];
			for (int i = 0; i < size; i++) {
				array2[i] = array[i];
			}
			delete[] array;
			array = array2;
			size += 5;
		}
		cin >> number;
	}
	//Printing the output
	printArray(array, count);
	cout << " => ";
	arrayReverse(array, count);
	printArray(array, count);
	cout << endl << "Array reversed." << endl;

	return 0;
}
