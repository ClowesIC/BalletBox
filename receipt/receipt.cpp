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
// Section: CMPSC 121 LAB
// Assignment: Homework 04 (Receipt & Savings)
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string item1, item2, item3, item4;
	double price1, price2, price3, price4;

  //prompt the user for items and prices
	cout << "Enter names of 4 one-word (maximum of 10 letters) items to purchase: " << endl;
	getline(cin, item1);
	getline(cin, item2);
	getline(cin, item3);
	getline(cin, item4);
	cout << "Enter their prices in US Dollars (<= $1,000): " << endl;
	cin >> price1;
	cin >> price2;
	cin >> price3;
	cin >> price4;

 //format output
	double total = price1 + price2 + price3 + price4;
	const int WIDTH1 = 12, WIDTH2 = 10;
	
	cout << "|" << setw(15) << right << "Receipt" << setw(10) << right << "|" << endl;

	cout << fixed << setprecision(2) << showpoint;
	cout << "|" << left << setw(WIDTH1) << item1 << "|$" << right << setw(WIDTH2) << price1 << "|" << endl;
	cout << "|" << left << setw(WIDTH1) << item2 << "|$" << right << setw(WIDTH2) << price2 << "|" << endl;
	cout << "|" << left << setw(WIDTH1) << item3 << "|$" << right << setw(WIDTH2) << price3 << "|" << endl;
	cout << "|" << left << setw(WIDTH1) << item4 << "|$" << right << setw(WIDTH2) << price4 << "|" << endl;

	cout << "|" << left << setw(WIDTH1) << "TOTAL: $" << "  " << right << setw(WIDTH2) << total << "|" << endl;



	return 0;
}
//OUTPUT
/*
Enter names of 4 one-word (maximum of 10 letters) items to purchase:
Yogurt
Apple
Butter
Bread
Enter their prices in US Dollars (<= $1,000):
0.75
8.00
12.99
2.85
|        Receipt         |
|Yogurt      |$      0.75|
|Apple       |$      8.00|
|Butter      |$     12.99|
|Bread       |$      2.85|
|TOTAL: $           24.59|

*/
