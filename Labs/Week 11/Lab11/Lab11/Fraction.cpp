// Mike Wholey
// 10/30/2018
// Lab 11

#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD( int num1, int num2 )
{
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
} 

// Reduce/simplify a fraction
void Fraction::reduce()
{
    // if the denom is negative we always flip
	if (denom < 0) {
		num = -num;
		denom = -denom;
	}
		
	int gcd = getGCD(num, denom);
	num /= gcd;
	denom /= gcd;
} 

Fraction::Fraction() {
	num = 0;
	denom = 0;
}

//input and output, both functions must return their stream
ostream& operator<<(ostream& output, const Fraction& fract) {
	output << fract.num << "/" << fract.denom;
	return output;
}

istream& operator>>(istream& input, Fraction& fract) {
	string slash;
	input >> fract.num >> slash >> fract.denom;
	return input;
}


//straightforward, we make a new Fraction, do a bit of math and then return it
const Fraction Fraction::operator+(Fraction& fract) {
	Fraction answer;
	answer.num = (this->num * fract.denom) + (this->denom * fract.num);
	answer.denom = (this->denom * fract.denom);
	answer.reduce();
	return answer;
}

const Fraction Fraction::operator-(Fraction& fract) {
	Fraction answer;
	answer.num = (this->num * fract.denom) - (this->denom * fract.num);
	answer.denom = (this->denom * fract.denom);
	answer.reduce();
	return answer;
}

const Fraction Fraction::operator*(Fraction& fract) {
	Fraction answer;
	answer.num = (this->num * fract.num);
	answer.denom = (this->denom * fract.denom);
	answer.reduce();
	return answer;
}

const Fraction Fraction::operator/(Fraction& fract) {
	Fraction answer;
	answer.num = (this->num * fract.denom);
	answer.denom = (this->denom * fract.num);
	answer.reduce();
	return answer;
}

bool Fraction::operator==(Fraction& fract) {
	//Make new ones so that we can do a reduction without actually
	//changing the Fractions
	Fraction a, b;
	a.num = this->num;
	a.denom = this->denom;
	b.num = fract.num;
	b.denom = fract.denom;

	a.reduce();
	b.reduce();

	if ((a.num == b.num) && (a.denom == b.denom)) {
		return true;
	}
	return false;
}
