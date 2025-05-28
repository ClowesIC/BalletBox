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
// Section: CMPSC121
// Assignment: Homework 05 (Geometry Calculator)
//


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	char num;
	float area;
	float radius;
	double pi = 3.14;

	float length;
	float width;

	float base;
	float height;

	cout << "Geometry Calculator:" << endl;
	cout << "1. Calculate the area of a Circle" << endl;
	cout << "2. Calculate the area of a Rectangle" << endl;
	cout << "3. Calculate the area of a triangle" << endl;
	cout << "4. Quit" << endl;
	cout << "Enter your choice (1-4) : ";
	cin >> num;

	switch (num)
	{
	case '1' :
		cout << "Enter radius of circle (m): ";
		cin >> radius;
		if (radius < 0) {
			cout << "Negative value is not allowed";
		}
		else {
			double areaCircle = pi * pow(radius, 2);
			cout << endl << "The area of the circle is: " << areaCircle << " m^2";
		}
		break;
	case '2' :
		cout << "Enter length of rectangle (m): ";
		cin >> length;
		cout << "Enter width of rectangle (m): ";
		cin >> width;
		if (length < 0 || width < 0) {
			cout << "Negative value is not allowed.";
		}
		else {
			double areaRectangle = length * width;
			cout << endl << "The area of the rectangle is: " << areaRectangle << " m^2";
		}
		break;
	case '3' :
		cout << "Enter the base of the triangle (m): ";
		cin >> base;
		cout << "Enter the height of the triangle (m): ";
		cin >> height;
		if (height < 0 || base < 0) {
			cout << "negative value is not allowed.";
		}
		else {
			double areaTriangle = .5 * base * height;
			cout << endl << "The area of the triangle is: " << areaTriangle << " m^2";
		}
		break;
	case '4' : 
		cout << "Goodbye!";
			return 0;
			break;
	}

}



////OUTPUT TESTS////////////////////////////

/*
Geometry Calculator:
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a triangle
4. Quit
Enter your choice (1-4) : 3
Enter the base of the triangle (m): 5.5
Enter the height of the triangle (m): 9

The area of the triangle is: 24.75 m^2

/////////////////////////

Geometry Calculator:
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a triangle
4. Quit
Enter your choice (1-4) : 1
Enter radius of circle (m): 6.2

The area of the circle is: 120.702 m^2

////////////////////////////////////////

Geometry Calculator:
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a triangle
4. Quit
Enter your choice (1-4) : 3
Enter the base of the triangle (m): -1
Enter the height of the triangle (m): 4
negative value is not allowed.



*/

