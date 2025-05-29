#pragma once
#include "Point.h"

class Circle {
public:
	Circle(Point cp, double r);
	Circle(double x, double y, double r);
	double getArea();
	double getRadius();
	void moveCircle(double dx, double dy);
	bool isItOrigin();
	Point getCenter();
	void display() const;


private:
	Point center;
	double radius;
};