// MIKE WHOLEY
// 9/25/2018
// Lab #6


#ifndef POINT_H
#define POINT_H


// Define your class here

class Point {
private:
	double x, y, z;

public:

	//see Point.cpp for documentation of these functions
	Point();
	void setCoordinates(double x1, double y1, double z1);
	double calcDistance();
	double calcDistance(Point point2);
};


#endif