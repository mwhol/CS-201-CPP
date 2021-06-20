#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
	//private vars, including our matrix which is 50 x 50 at it's largest
	int row;
	int col;
	int theMatrix[50][50];

public:
	Matrix(int a, int b);
	void set(int row, int column, int value);
	int get(int row, int column);
};

#endif