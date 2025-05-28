
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Function Prototypes:
double askAmount();
double askIncome();
bool askLoan();
bool decideLoan(double income, double loan);

int main()
{
	double loan;
	double income;


	if (askLoan() == 0) {
		cout << "Thanks for visiting the bank!";
	}
	else { //user wants a loan
		

		loan = askAmount();
		
		income = askIncome();
		
		decideLoan(income, loan);
		if (decideLoan(income, loan) == 1) {
			cout << "Congratulations! Your loan request for $" << loan << " has been accepted!";
		}
		if (decideLoan(income, loan) == 0) {
			cout << "Sorry! Your loan request for $" << loan << " has been rejected.";
		}

	}
	

	



	



}


//Function definitions:
double askAmount() {
	double loan;
	cout << "how much would you like to borrow? ";
	cin >> loan;
	while (loan <= 0) {
		cout << "Please enter a positive number ";
		cin >> loan;
	}
	return loan;

}

double askIncome() {
	double income;
	cout << "What is your yearly income? ";
	cin >> income;
	while (income <= 0) {
		cout << "Please enter a positive number ";
		cin >> income;
	}
	return income;
	
}

bool askLoan() {
	string choice;
	cout << "Would you like to take out a loan? ";
	cin >> choice;
	if (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y") {
		return 1;
	}
	if (choice == "no" || choice == "No" || choice == "n" || choice == "N") {
		return 0;
	}
	else if (choice != "no" ||choice != "No" || choice != "n" || choice != "N" || choice != "yes" || choice != "Yes" || choice != "y" || choice != "Y")  {
		cout << "Invalid choice; please enter yes or no. ";
		cin >> choice;
	}



}

bool decideLoan(double income, double loan) {
	if (income <= 10000) {
		return 0;
	}
	if (income > 10000 && income < 100000) {
		if (income * 5 >= loan) {
			return 1;
		}
		if (income * 5 < loan) {
			return 0;
		}
	}
	if (income >= 100000) {
		return 1;

	}


}

//OUTPUTS///////////////



/*
Would you like to take out a loan? maybe
Invalid choice; please enter yes or no. yes
how much would you like to borrow? 0
Please enter a positive number 45000
What is your yearly income? 15000
Congratulations! Your loan request for $45000 has been accepted!




*/