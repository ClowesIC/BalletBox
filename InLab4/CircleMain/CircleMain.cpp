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
// Section: CMPSC 122 - 002L
// Assignment: In-Lab4 Exercise 2
//
#include <iostream>
#include <iomanip>
using namespace std;

#include "Circle.h"

int main() {
	Circle c(2.5, 3.0, 5.0);
	double radius;
	double area;
	
	//display radius of c
	radius = c.getRadius();
	cout << "radius of c: " << radius << "\n"; //if works, should be 5

	//display area of c
	area = c.getArea();
	cout << fixed << setprecision(2);
	cout << "area of c: " << area << "\n"; 

	//test for moveCircle and display
	
	cout << "Moving circle +1x and +1y" << "\n";
	c.moveCircle(1, 1); 
	cout << "Circle is now at: ";  
	c.display();
	cout << endl;

	//test bool IsItOrigin():
	cout << "Is circle c at origin?: ";
	if (c.isItOrigin() == true) {
		cout << "yes";
	}
	else {
		cout << "no";
	}



}

//OUTPUT
/*
radius of c: 5
area of c: 78.54
Moving circle +1x and +1y
Circle is now at: [(3.50, 4.00), 5.00]
Is circle c at origin?: no


*/