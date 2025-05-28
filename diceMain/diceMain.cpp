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
// Assignment: Hoemwork 12: Dice Tossing
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Dice.h"

using namespace std;

//function prototype:
void outcome_probability(Dice dice[], int n_dice, int totalTosses);

int main() {
	const int size = 3;
	Dice die[size];
	double sameCount = 0;
	const int totalTosses = 1000000;
	double ratio;
	double secondRatio;
	int number;

	//give initial sides of dice
	cout << "The dice initial face-up numbers are: " << die[0].getSideUp() << " " << die[1].getSideUp() << " " << die[2].getSideUp() << endl;

	//loop tosses
	for (int i = 0; i < totalTosses; i++) {
		for (int j = 0; j < size; j++) {
			die[j].toss();
		}
		if (die[0].getSideUp() == die[1].getSideUp() && die[1].getSideUp() == die[2].getSideUp()) {
			sameCount = sameCount + 1;
		}
	}
	ratio = sameCount / totalTosses;

	cout << "The theoretical probability of 3 dice tosses with the same number = 0.02777" << endl;
	cout << "The experimental probabibility of 3 dice tosses with the same number = " << setprecision(6) << fixed << ratio;
	cout << endl;

	//part 2
	//set ratio and SameCount back to zero
	sameCount = 0;
	ratio = 0;

	cout << "Please enter a number (3-18) for the sum of 3 dice tosses" << endl << "Enter 0 to end the experiment: ";
	cin >> number;
	if (number == 0) {
		return 0;
	}
	while (number < 3 || number > 18) {
		cout << "Invalid outcome value! Try again." << endl;
		cout << "Please enter a number (3-18) for the sum of 3 dice tosses" << endl << "Enter 0 to end the experiment: ";
		cin >> number;
		if (number == 0) {
			return 0;
		}
	}

	//loop tosses
	for (int i = 0; i < totalTosses; i++) {
		for (int j = 0; j < size; j++) {
			die[j].toss();
		}
		if (die[0].getSideUp() + die[1].getSideUp() + die[2].getSideUp() == number) {
			sameCount = sameCount + 1;
		}
	}
	ratio = sameCount / totalTosses;
	cout << "The experimental probability of 3 dice tosses with an outcome of " << number << " =" << endl << setprecision(6) << fixed << ratio << endl;

	//BONUS
	outcome_probability(die, size, totalTosses);
}

//function definition: 
void outcome_probability(Dice dice[], int n_dice, int totalTosses) {
	// Array to count sum of outcomes
	int outcomeCount[16] = { 0 };

	// Loop tosses
	for (int i = 0; i < totalTosses; i++) {
		int sum = 0;
		for (int j = 0; j < n_dice; j++) {
			dice[j].toss();
			//find the sum of the dice
			sum += dice[j].getSideUp();
		}
		if (sum >= 3 && sum <= 18) {
			//add a count to the matching index of the sum
			outcomeCount[sum - 3]++;
		}
	}

	// display stuff
	cout << setw(7) << "Outcome" << setw(15) << "Probability" << setw(15) << "Outcome Count"
		<< setw(23) << "Distribution Histogram" << endl;
	cout << "=======    ===========  ============= ======================" << endl;

	// Looping through sums
	for (int outcome = 3; outcome <= 18; outcome++) {
		// Experimental probability
		double probability = static_cast<double>(outcomeCount[outcome - 3]) / totalTosses;

		// Display the outcome, probability, and count
		cout << setw(7) << outcome << setw(15) << setprecision(7) << fixed << probability
			<< setw(15) << outcomeCount[outcome - 3] << " ";

		// Display histogram
		int histogramLength = outcomeCount[outcome - 3] / (totalTosses / 100); 
		for (int i = 0; i < histogramLength; i++) {
			cout << "*";
		}

		cout << endl;
	}
}

//DISPLAY
/*
The theoretical probability of 3 dice tosses with the same number = 0.02777
The experimental probabibility of 3 dice tosses with the same number = 0.028031
Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to end the experiment: -5
Invalid outcome value! Try again.
Please enter a number (3-18) for the sum of 3 dice tosses
Enter 0 to end the experiment: 5
The experimental probability of 3 dice tosses with an outcome of 5 =
0.027946
Outcome    Probability  Outcome Count Distribution Histogram
======= ===========     ============= ======================
	  3      0.0046660           4666
	  4      0.0139800          13980 *
	  5      0.0277630          27763 **
	  6      0.0463670          46367 ****
	  7      0.0693460          69346 ******
	  8      0.0977350          97735 *********
	  9      0.1157110         115711 ***********
	 10      0.1245330         124533 ************
	 11      0.1255410         125541 ************
	 12      0.1157190         115719 ***********
	 13      0.0970570          97057 *********
	 14      0.0693940          69394 ******
	 15      0.0461460          46146 ****
	 16      0.0276030          27603 **
	 17      0.0138540          13854 *
	 18      0.0045850           4585


*/