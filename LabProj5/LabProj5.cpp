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
// Section: CMPSC 122 - 002LAB
// Assignment: LabProj5
//

// driver for project 5
#include <iostream>
#include <iomanip>
using namespace std;
#include "Complex2.h"
int main()
{
	Complex c(7.0, 3.0), d(1.0, -2.0), x, y;
	// c.print();
	cout << c;
	cout << " + ";
	// d.print();
	cout << d;
	cout << " = ";
	x = c + d;
	// x.print();
	cout << x;
	cout << '\n';
	// c.print();
	cout << c;
	cout << " - ";
	// d.print();
	cout << d;
	cout << " = ";
	x = c - d;
	// x.print();
	cout << x;
	cout << '\n';
	// c.print();
	cout << c;
	cout << " * ";
	// d.print();
	cout << d;
	cout << " = ";
	x = c * d;
	// x.print();
	cout << x;
	cout << '\n';
	// c.print();
	cout << c;
	cout << " / ";
	// d.print();
	cout << d;
	cout << " = ";
	x = c / d;
	// x.print();
	cout << x;
	cout << '\n';
	// c.print();
	cout << c;
	cout << " / ";
	// d.print();
	cout << y; // y is (0 + 0i)
	cout << " = ";
	x = c / y;
	// c.print();
	cout << c;
	cout << " == ";
	// c.print();
	cout << c;
	cout << ((c == c) ? " is equal " : " is not equal ");
	cout << '\n';
	// c.print();
	cout << c;
	cout << " == ";
	// d.print();
	cout << d;
	cout << ((c == d) ? " is equal" : " is not equal");
	cout << '\n';
	// c.print();
	cout << c;
	cout << " != ";
	// c.print();
	cout << c;
	cout << " is " << ((c != c) ? "true" : "false");
	cout << '\n';
	// c.print();
	cout << c;
	cout << " != ";
	// d.print();
	cout << d;
	cout << " is " << ((c != d) ? "true" : "false");
	cout << "\n\n";
	//uncomment this line for bonus points version
	// Optional: 4 Bonus Points
	// c.print();
	cout << c;
	cout << " + ";
	// d.print();
	cout << c;
	cout << " / ";
	cout << d;
	cout << " - ";
	cout << d;
	cout << " * ";
	cout << c;
	cout << " = ";
	x = c + c / d - d * c; // cascading use of operators
	// x.print();
	cout << x;
	cout << '\n';
	// uncomment this line for bonus points version
	return 0;
}
/////OUTPUT////////////////////////
/*
(7 + 3i)
/ (1 - 2i)
= (7 - 1.5i)

(7 + 3i)
/ (0 + 0i)
= Divide by Zero ERROR!!!(7 + 3i)
== (7 + 3i)
is equal
(7 + 3i)
== (1 - 2i)
is not equal
(7 + 3i)
!= (7 + 3i)
is false
(7 + 3i)
!= (1 - 2i)
is true

(7 + 3i)
+ (7 + 3i)
/ (1 - 2i)
- (1 - 2i)
* (7 + 3i)
= (7 + 7.5i)
*/