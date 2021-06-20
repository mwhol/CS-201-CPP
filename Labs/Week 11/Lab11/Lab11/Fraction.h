// Mike Wholey
// 10/30/2018
// Lab 11

#include "stdafx.h"
#include <iostream>
using namespace std;

class Fraction
{

private:
	int getGCD( int num1, int num2 );
	int num, denom;


public:
	void reduce();
	Fraction();
	friend ostream& operator<<(ostream& output, const Fraction& fract);
	friend istream& operator>>(istream& input, Fraction& fract);
	const Fraction operator+(Fraction& fract);
	const Fraction operator-(Fraction& fract);
	const Fraction operator*(Fraction& fract);
	const Fraction operator/(Fraction& fract);
	bool operator==(Fraction& fract);
};

