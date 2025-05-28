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
// Assignment: Homework 13: Recursion in Backward
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//function prototype:
bool isPalindrome(const string& input, int first = 0, int last = 0);

int main() {
	string userInput, inputCopy;
	bool result;

	//prompt user to type string
	cout << "Enter a string:" << endl;
	getline(cin, userInput);
	cout << endl;
	inputCopy = userInput;

	//use bool isPalindrome to check if string is palindrome
	result = isPalindrome(userInput);

	if (result == true) {
		while (userInput.length() > 1) {
			cout << "Checking: " << userInput << endl;
			userInput = userInput.erase(0, 1);
			userInput = userInput.erase(userInput.length() - 1, 1);
		}
		if (userInput.length() == 1) {
			cout << "Checking: " << userInput << endl;
		}
		cout << endl << inputCopy << " is a palindrome!";
	}
	else {
		while (userInput.length() > 1) {
			cout << "Checking: " << userInput << endl;
			userInput = userInput.erase(0, 1);
			userInput = userInput.erase(userInput.length() - 1, 1);

			if (userInput.length() - 1 != userInput[0]) {
				cout << "Checking: " << userInput << endl;
				break;
			}
		}

		cout << endl << inputCopy << " is NOT a palindrome";
	}

	//another string
	string decision;
	cout << endl << "Enter another string (Y/N): ";
	cin >> decision;

	//repeat if yes
	while (decision == "y" || decision == "Y") {
		cout << endl << "Enter a string:" << endl;
		cin >> userInput;
		cout << endl;
		inputCopy = userInput;

		//palindrome stuff
		result = isPalindrome(userInput);

		if (result == true) {
			while (userInput.length() > 1) {
				cout << "Checking: " << userInput << endl;
				userInput = userInput.erase(0, 1);
				userInput = userInput.erase(userInput.length() - 1, 1);
			}
			if (userInput.length() == 1) {
				cout << "Checking: " << userInput << endl;
			}
			cout << endl << inputCopy << " is a palindrome!";
		}
		else {
			while (userInput.length() > 1) {
				cout << "Checking: " << userInput << endl;
				userInput = userInput.erase(0, 1);
				userInput = userInput.erase(userInput.length() - 1, 1);

				if (userInput.length() - 1 != userInput[0]) {
					cout << "Checking: " << userInput << endl;
					break;
				}
			}

			cout << endl << inputCopy << " is NOT a palindrome";
		}
		cout << endl << "Enter another string (Y/N): ";
		cin >> decision;
	}

	//if no
	if (decision == "n" || decision == "N") {
		return 0;
	}
	else {
		cout << endl << "Invalid input, try again!";
	}


}

//function definition
bool isPalindrome(const string& input, int first, int last) {
	
	//the last variable should be the last element of users string index
	if (last == 0) {
		last = input.length() - 1;
	}
	//base case: when the characters are different, it is not a palindrome
	if (tolower(input[first]) != tolower(input[last])) {
		return false;
	}

	//skip characters that are nonalphabetic
	if (!isalpha(input[first]) && !isalpha(input[last])) {
		return isPalindrome(input, first + 1, last - 1);
	}

	//compare characters (ignore capitalization)
	if (tolower(input[first]) == tolower(input[last])) {
		
		if (first == last) {
			return true;
		}
		//process repeats until first index equals last index
		else {
			return isPalindrome(input, first + 1, last - 1);
		}
	}


}

//OUTPUT///////////////////////////
/*
Enter a string:
Racecar

Checking: Racecar
Checking: aceca
Checking: cec
Checking: e

Racecar is a palindrome!
Enter another string (Y/N): Y

Enter a string:
tacocaT

Checking: tacocaT
Checking: acoca
Checking: coc
Checking: o

tacocaT is a palindrome!
Enter another string (Y/N): Y

Enter a string:
Racebar

Checking: Racebar
Checking: aceba

Racebar is NOT a palindrome
Enter another string (Y/N): N





*/