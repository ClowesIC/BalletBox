#include <iostream>
#include "triangle.h"
using namespace std;

//class function definitions
//set base
void Triangle::setBase(double b) {
	base = b;
}
//set height
void Triangle::setHeight(double h) {
	height = h;
}
//get base
double Triangle::getBase() const {
	return base;
}
//get height
double Triangle::getHeight() const {
	return height;
}
//get area
double Triangle::getArea() const {
	return .5 * base * height;
}
