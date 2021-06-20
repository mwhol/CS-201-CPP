// MIKE WHOLEY
// 9/25/2018
// Lab #6

#include "stdafx.h"
#include "Point.h"
#include <cmath>
// Define your class's functions here

//constructor sets points to zero as default
Point::Point() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
	}

//we set our points
void Point::setCoordinates(double x1, double y1, double z1) {
		x = x1;
		y = y1;
		z = z1;
	}

//calculate distance with respect to origin
double Point::calcDistance() {
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

//calculate distance with respect to another point
double Point::calcDistance(Point point2) {
		return sqrt(pow(x - point2.x, 2) + pow(y - point2.y, 2)	+ pow(z - point2.z, 2));
	}