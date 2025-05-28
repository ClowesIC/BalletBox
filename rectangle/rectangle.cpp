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

using namespace std;

//struct
struct rectangle {
	double length;
	double width;

};

//double function prototype:

double doubleDimensions(double &length, double &width);

int main() {
	rectangle rect;
	double area = 0;

	//prompt user to enter inputs for the length and width of rect
	//length
	cout << "Enter the starting length: ";
	cin >> rect.length;
	while (rect.length <= 0) {
		cout << "Please enter a length greater than zero!" << endl;
		cout << "Enter the starting length: ";
		cin >> rect.length;
	}
	cout << endl;
	//width
	cout << "Enter the starting width: ";
	cin >> rect.width;
	while (rect.width <= 0) {
		cout << "Please enter a width greater than zero!" << endl;
		cout << "Enter the starting width: ";
		cin >> rect.width;
	}
	cout << endl;

	//loop until area is greater than 500;
	while (area < 500) {
		area = rect.length * rect.width;
		if (area > 500) {
			break;
		}
		cout << fixed << setprecision(2);
		cout << rect.length << " x " << rect.width << " = " << area << endl;
		doubleDimensions(rect.length, rect.width);
	}
	cout << "DONE";

	return 0;

}

//function definition
double doubleDimensions(double& length, double& width) {
	length = length * 2;
	width = width * 2;
	return length, width;
}

//OUTPUT////
/*
Enter the starting length: -20
Please enter a length greater than zero!
Enter the starting length: 15.75

Enter the starting width: 0
Please enter a width greater than zero!
Enter the starting width: 1.2

15.75 x 1.20 = 18.90
31.50 x 2.40 = 75.60
63.00 x 4.80 = 302.40
DONE



*/