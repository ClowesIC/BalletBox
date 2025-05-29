#include "Point.h"
#include <cmath>
using namespace std;

Point::Point() {
	_x = 0;
	_y = 0;
}

Point::Point(double x, double y) {
	_x = x;
	_y = y;
}

double Point::x() const {
	return _x;
}
double Point::y() const {
	return _y;
}


double Point::magnitude() const {
	double r;
	r = sqrt((_x * _x) + (_y * _y));
	return r;
}
void Point::move(double dx, double dy) {
	_x = _x + dx;
	_y = _y + dy;
}

void Point::print() const {
	cout << "(" << _x << ", " << _y << ")";
}