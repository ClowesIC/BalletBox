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
// Assignment: LAB 06 (Guessing Game)
//


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int n;
	int guess;	

	//user must enter input in order to get an upper limit value
	cout << "Enter the upper limit of the guessing number: ";
	cin >> n;

	while (n < 1) {
		cout << "Invalid input, the upper limit must be greater than 0! " << endl;
		cout << "Enter the upper limit of the geussing number: ";
		cin >> n;
	}
	if (n >= 1) {
		srand(time(0));
		int randNumber = rand() % n + 1;
		cout << "Enter your guess in between 1 and " << n << "." << endl;
		cin >> guess;
		while (guess > n) {
			cout << "You have entered an invalid number!" << endl;
			cout << "Enter your guess in between 1 and " << n << "." << endl;
			cin >> guess;
		}
		while (guess != randNumber) {
			if (guess < randNumber) {
				cout << "Too low, try again." << endl;
				cout << "Enter your guess in between 1 and " << n << "." << endl;
				cin >> guess;
			}
			else {
				cout << "Too high, try again." << endl;
				cout << "Enter your guess in between 1 and " << n << "." << endl;
				cin >> guess;
			}
		}
		if (guess == randNumber) {
			cout << "Congrats, you guessed the correct number, " << randNumber;
		}
		
	}


	
	


}


//////////////OUTPUT TEST/////////////////////////////////////
/*
Enter the upper limit of the guessing number: 0
Invalid input, the upper limit must be greater than 0!
Enter the upper limit of the geussing number: 0
Invalid input, the upper limit must be greater than 0!
Enter the upper limit of the geussing number: 100
Enter your guess in between 1 and 100.
50
Too high, try again.
Enter your guess in between 1 and 100.
40
Too low, try again.
Enter your guess in between 1 and 100.
41
Too low, try again.
Enter your guess in between 1 and 100.
42
Congrats, you guessed the correct number, 42


*/

