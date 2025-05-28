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
// Assignment: Homework 13 (Reverse)
//

#include <iostream>
#include<string>
using namespace std;

//function prototype
void reverseString(string input, int size);

int main() {
	string userInput, dummyStr;
	cout << "Please enter a string:" << endl;
	getline(cin, userInput);
	cout << endl;
	
	cout << "The reverse string is: " << endl;
	reverseString(userInput, userInput.length());
	cout << endl;
	cout << endl;

	//another string
	string decision;
	cout << "Enter another string (Y/N): ";
	cin >> decision;
	
	//repeat if yes
	while (decision == "y" || decision == "Y") {
		cin.ignore();
		cout << "Please enter a string:" << endl;
		getline(cin, userInput);
		cout << endl << "The reverse string is: " << endl;
		reverseString(userInput, userInput.length());
		cout << endl << endl << "Enter another string (Y/N): ";
		cin >> decision;
		
	}

	//if no
	while (decision == "n" || decision == "N") {
		return 0;
	}


}

//function definition
void reverseString(string input, int size) {
	if (size == -1) {
		return;
	}
	else {
		cout << input[size];
		reverseString(input, size - 1);
	}
}

//sample output:
/*
Please enter a string:
Ian Clowes

The reverse string is:
sewolC naI

Enter another string (Y/N): Y
Please enter a string:
Ian Clowes

The reverse string is:
sewolC naI

Enter another string (Y/N): Y
Please enter a string:
Ian Clowes

The reverse string is:
sewolC naI

Enter another string (Y/N): N


*/