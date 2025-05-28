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
// Section: CMPSC121 Lab
// Assignment: Homework 03 (Convert Pennies)
//


#include <iostream>
using namespace std;

int main()
{
	int dollars, quarters, dimes, nickles, pennies;
	int pennyRemainder;

	//User inputs pennies
	cout << "Enter number of cents to convert: ";
	cin >> pennies;

	//conversions
	dollars = pennies / 100; 
	pennyRemainder = pennies % 100;

	quarters = pennyRemainder / 25;
	pennyRemainder = pennyRemainder % 25;

	dimes = pennyRemainder / 10;
	pennyRemainder = pennyRemainder % 10;

	nickles = pennyRemainder / 5;
	pennyRemainder = pennyRemainder % 5;

	pennies = pennyRemainder;
	

	//display conversions
	cout << "Your conversion is: " << "\n";
	cout << dollars << " dollar(s)" << "\n";
	cout << quarters << " quarter(s)" << "\n";
	cout << dimes << " dime(s)" << "\n";
	cout << nickles << " nickel(s)" << "\n";
	cout << pennies << " pennies" << "\n";

	return 0;
}

/*OUTPUT/////////////////////////////////

Enter number of cents to convert: 1292
Your conversion is:
12 dollar(s)
3 quarter(s)
1 dime(s)
1 nickel(s)
2 pennies
*/
