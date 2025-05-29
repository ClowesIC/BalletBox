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
// Name: Ian CLowes
// Section: CMPSC 122, 002L
// Assignment: In-Lab2
//


#include <iostream>
#include <iomanip>
using namespace std;

//function prototype:
void bubbleSort(double*, int);
double Average(double*, int);

int main() {
	int SIZE;
	cout << "Please enter the number of test scores: ";
	cin >> SIZE;
	while (SIZE <= 0) {
		cout << "Number must be greater than 0!";
		cout << endl << "Please enter the number of test scores: ";
		cin >> SIZE;
	}
	double* scores = new double[SIZE]; 
	double average;
	
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter test score " << i + 1 << ": ";
		cin >> scores[i];
		while (scores[i] < 0) {
			cout << "Negative numbers not allowed!";
			cout << endl << "Enter test score " << i + 1 << ": ";
			cin >> scores[i];
		}
	}

	//bubble sort array
	bubbleSort(scores, SIZE);

	//display new sorted array
	cout << "The test scores ascending order:" << endl;
	cout << "================================ " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << scores[i] << endl;
	}
	cout << endl;
	
	//calculate average:
	average = Average(scores, SIZE);

	//display average
	cout << fixed << setprecision(2);
	cout << "The average score is " << average << endl;

	//display test scores (dropping lowest)
	cout << setprecision(0);
	cout << endl <<  "The test scores (dropping lowest):" << endl;
	cout << "================================== " << endl;
	for (int i = 1; i < SIZE; i++) {
		cout << scores[i] << endl;
	}

	delete [] scores;
	return 0;


	
}

//function definition:
void bubbleSort(double* scores, int SIZE) {
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (scores[j] > scores[j + 1]) {
				// Swap elements
				int temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
		}
	}
}
double Average(double* scores, int SIZE) {
	double average;
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum = sum + scores[i];
	}
	average = sum / SIZE;
	return average;
}

//OUTPUT///////////////////////////////////////
/*
Please enter the number of test scores: 0
Number must be greater than 0!
Please enter the number of test scores: 6
Enter test score 1: 69
Enter test score 2: 93
Enter test score 3: 75
Enter test score 4: 96
Enter test score 5: 91
Enter test score 6: 88
The test scores ascending order:
================================
69
75
88
91
93
96

The average score is 85.33

The test scores (dropping lowest):
==================================
75
88
91
93
96



*/
