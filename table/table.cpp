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
// Section: CMPSC 121
// Assignment: Homework 06 (Multiplication Table)
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numRow;
	int numCol;

	int row;
	int col;

	cout << "let's build a multiplication table!" << endl;
	//row input
	cout << "Enter the number of rows (1 to 12 inclusive) : ";
	cin >> numRow;
	while (numRow < 1 || numRow > 12) {
		cout << "Invalid input, try again!" << endl;
		cout << "Enter the number of rows (1 to 12 inclusive) : ";
		cin >> numRow;
	}
	//col output
	cout << "Enter the number of columns (1 to 12 inclusive) : ";
	cin >> numCol;
	while (numCol < 1 || numCol > 12) {
		cout << "Invalid input, try again!" << endl;
		cout << "Enter the number of colomns (1 to 12 inclusive) : ";
		cin >> numCol;
	}

	//making and displaying table
	for (row = 1; row <= numRow; row++) {
		for (col = 1; col <= numCol; col++) {
			cout << setw(2) << row * col << " ";
		}
		cout << endl;
	}


	

}




////OUTPUT////////////////////////////////////////
/*
let's build a multiplication table!
Enter the number of rows (1 to 12 inclusive) : 0
Invalid input, try again!
Enter the number of rows (1 to 12 inclusive) : 4
Enter the number of columns (1 to 12 inclusive) : 0
Invalid input, try again!
Enter the number of colomns (1 to 12 inclusive) : 5
 1  2  3  4  5
 2  4  6  8 10
 3  6  9 12 15
 4  8 12 16 20



*/