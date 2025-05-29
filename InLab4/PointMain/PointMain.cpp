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
// Section: COMPSC 122 = 002L
// Assignment: In-Lab04
//

#include <iostream>
#include <iomanip>
using namespace std;
#include "Point.h"

int main() {
	Point p0;
	Point p1(5, -2);
	Point p2 = p1;
	p0 = p1;
	cout << "p0.x() = " << p0.x() << "\n";
	cout << "p0.y() = " << p0.y() << "\n";

	cout << fixed << setprecision(2);
	cout << "Moving p1 +5x and +5y" << endl;
	p1.move(5, 5);
	cout << "p1 is now ";
	p1.print();
	cout << " with a magnitude of " << p1.magnitude();

}

/*
Output of testing class functions:
p0.x() = 5
p0.y() = -2
Moving p1 +5x and +5y
p1 is now (10.00, 3.00) with a magnitude of 10.44



*/
