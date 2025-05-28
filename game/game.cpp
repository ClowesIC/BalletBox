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
// Assignment: Lab 14: Number Game
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function prototype:
void isCorrect(int upper);

int main() {
	int n;
	int randNumber;

	//user must enter input in order to get an upper limit value
	cout << "Enter the upper limit of the guessing number: ";
	cin >> n;

	while (n < 1) {
		cout << "Invalid input, the upper limit must be greater than 0! " << endl;
		cout << "Enter the upper limit of the geussing number: ";
		cin >> n;
	}
	
	//run isCorrect function to see if user's guesses work
	isCorrect(n);

	
	
}

//function definition:
void isCorrect(int upper) {
	int guess;
	if (upper >= 1) {
		srand(time(0));
		int randNumber = rand() % upper + 1;
		cout << endl << "Enter your guess in between 1 and " << upper << ":";
		cin >> guess;
		while (guess > upper) {
			cout << "You have entered an invalid number!" << endl;
			cout << endl << "Enter your guess in between 1 and " << upper << ":";
			cin >> guess;
		}
		while (guess != randNumber) {
			if (guess < randNumber) {
				cout << "Too low, try again." << endl;
				cout << endl << "Enter your guess in between 1 and " << upper << ":";
				cin >> guess;
			}
			else {
				cout << "Too high, try again." << endl;
				cout << endl << "Enter your guess in between 1 and " << upper << ":";
				cin >> guess;
			}
		}
		if (guess == randNumber) {
			cout << "Congrats! you guessed the correct number, " << randNumber;
		}

	}
}
//OUTPUT example//////////////////////////////
/*
Enter the upper limit of the guessing number: 100

Enter your guess in between 1 and 100:50
Too low, try again.

Enter your guess in between 1 and 100:65
Too low, try again.

Enter your guess in between 1 and 100:70
Too low, try again.

Enter your guess in between 1 and 100:75
Too low, try again.

Enter your guess in between 1 and 100:80
Too low, try again.

Enter your guess in between 1 and 100:90
Too high, try again.

Enter your guess in between 1 and 100:87
Too high, try again.

Enter your guess in between 1 and 100:86
Too high, try again.

Enter your guess in between 1 and 100:85
Too high, try again.

Enter your guess in between 1 and 100:84
Too high, try again.

Enter your guess in between 1 and 100:83
Congrats! you guessed the correct number, 83

*/