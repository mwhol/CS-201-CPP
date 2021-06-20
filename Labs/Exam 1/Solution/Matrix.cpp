#include "stdafx.h"
#include "Matrix.h"


//constructor, takes two arguments and sets row and col to them
Matrix::Matrix(int a, int b) {
	row = a;
	col = b;
}

//basic accessor, returns our index value from our array
int Matrix::get(int row, int column) {
	return theMatrix[row][column];
}

//basic mutator, sets our private array at the index to our value
void Matrix::set(int row, int column, int value) {
	theMatrix[row][column] = value;
}