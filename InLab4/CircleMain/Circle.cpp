#include <cmath>
#include "Point.h"
#include "Circle.h"

Circle::Circle(Point cp, double r) {
	cp = center;
	r = radius;
}
Circle::Circle(double x, double y, double r) {
	radius = r;
	center = Point(x, y);
}
double Circle::getArea() {
	double pi = 3.14159;
	double area = pi * pow(radius, 2);
	return area;
}

double Circle::getRadius() {
	return radius;
}

void Circle::moveCircle(double dx, double dy) {
	center.move(dx, dy);
}
bool Circle::isItOrigin() {
	if (center.x() == 0 && center.y() == 0) {
		return true;
	}
	else {
		return false;
	}
}
Point Circle::getCenter() {
	return center;
}



void Circle::display() const {
	cout << "[(" << center.x() << ", " << center.y() << "), " << radius << "]";
}