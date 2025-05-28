// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: Ian Clowes
// Section: CMPSCI 121
// Assignment: Lab 12 (Rectangle and Triangle)
//

#include <iostream>
#include <iomanip>
#include "triangle.h"

using namespace std;


int main() {
	Triangle tri;
	double base, height, area;

	cout << "Enter the height of the triangle in meters: ";
	cin >> height;
	while (height <= 0) {
		cout << "The height must be greater than 0, please try again." << endl;
		cout << "Enter the hieght of the triangle in meters: ";
		cin >> height;
	}

	cout << "Enter the base of the triangle in meters: ";
	cin >> base;
	while (base <= 0) {
		cout << "The base must be greater than 0, please try again." << endl;
		cout << "Enter the base of the triangle in meters: ";
		cin >> base;
	}
	//set base and height using class functions
	tri.setBase(base);
	tri.setHeight(height);
	//calculate area using class function
	area = tri.getArea();
	//display area
	cout << setprecision(2) << fixed;
	cout << "The area of the triangle is " << area << " m^2";

	return 0;

}
//OUTPUT
/*
Enter the height of the triangle in meters: -2
The height must be greater than 0, please try again.
Enter the hieght of the triangle in meters: 2.57
Enter the base of the triangle in meters: 0
The base must be greater than 0, please try again.
Enter the base of the triangle in meters: 4.88
The area of the triangle is 6.27 m^2





*/