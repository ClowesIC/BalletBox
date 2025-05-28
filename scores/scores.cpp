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
// Assignment: Lab 10 (Test Scores)
//

#include <iostream>
#include <cmath>

using namespace std;

//Function Prototypes:
void getScores(double* scores, int size);
void sortScores(double* scores, int size);
double computeAverage(double* scores, int size);

int main()
{

	int size = 0; //the size of the array will remain constant based on the user input.
	double *scores = new double[size];


	
	//Task user to get constant size of array
	cout << "Enter the number of scores: ";
	cin >> size;
	while (size <= 1) {
		cout << "Please Enter the number of scores greater than 1, try again. \n";
		cout << "Enter the number of scores: ";
		cin >> size;
	}

	//user must now enter scores
	getScores(scores, size);
	//scores must now be sorted and displayed
	sortScores(scores, size);
	//calculate and display average;
	double average = computeAverage(scores, size);
	cout << "The average score is " << average;




}

//function definitions

void getScores(double *scores, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter test score " << i+1 << ": ";
		cin >> scores[i];
		if (scores[i] < 0) {
			cout << "Not allowed to enter a negative value, try again. \n";
			cout << "Enter test score " << i << ": ";
			cin >> scores[i];
		}
	}
	cout << endl;
}

void sortScores(double *scores, int size) {
	//bubble sort
	int n = size;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (scores[j] > scores[j + 1]) {
				swap(scores[j], scores[j + 1]);
			}
		}
	}

	//display sort for the array scores
	cout << "The test scores in ascending order:" << endl;
	for (int i = 0; i < size; i++) {
		cout << scores[i] << endl;
	}
	cout << endl;

}

double computeAverage(double* scores, int size) {
	//program should calculate average of all scores 
	//find some of all scores:
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + scores[i];
	}
	//calculate average
	double average = sum / size;
	return average;

}


//OUTPUT DISPLAY////////////////////////////////////////////////////
/*
Enter the number of scores: 1
Please Enter the number of scores greater than 1, try again.
Enter the number of scores: 4
Enter test score 1: 53
Enter test score 2: 4
Enter test score 3: 12
Enter test score 4: 22

The test scores in ascending order:
4
12
22
53

The average score is 22.75

*/