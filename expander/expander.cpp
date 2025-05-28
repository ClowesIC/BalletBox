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
// Assignment: Homework 10 (Reverse and Expand)
//


#include <iostream>

using namespace std;

//function prototype:
int* expandArray(int* org_array, int array_size);

int main()
{
	int array_size = 0;
	int* org_array = new int[array_size];

	//user enters array size
	cout << "Please enter the size of the array: ";
	cin >> array_size;
	while (array_size <= 0) {
		cout << "The array size must be greater than 0, try again.\n";
		cout << "Please enter the size of the array: ";
		cin >> array_size;
	}
	cout << endl;

	//get numbers of array
	for (int i = 0; i < array_size; i++) {
		cout << "Enter integer number " << i + 1 << ": ";
		cin >> org_array[i];
		if (org_array[i] < 0) {
			cout << "Not allowed to enter a negative value, try again. \n";
			cout << "Enter integer number " << i << ": ";
			cin >> org_array[i];
		}
	}
	cout << endl;

	//display original array:
	cout << "The contents of the original array are: [";
	for (int i = 0; i < array_size; i++) {
		cout << org_array[i] << ", ";
	}
	cout << "]" << endl;

	//display expanded array
	cout << "The contents of the expanded array are: [";
	int *expanded = expandArray(org_array, array_size);
	for (int i = 0; i < array_size + 5; i++) {
		cout << expanded[i] << ", ";
	}
	cout << "]" << endl;
	delete[] expanded;
	delete[] org_array;




}

//function prototype:
int* expandArray(int* org_array, int array_size) {
	int *expanded_array = new int[array_size + 5]();

	//copy orginal elements from org_array
	for (int i = 0; i < array_size; i++) {
		expanded_array[i] = org_array[i];
	}

	return expanded_array;

}


//OUTPUT///

//Code will add 5 new elements in the new array
/*Please enter the size of the array: 5

Enter integer number 1 : 1
Enter integer number 2 : 2
Enter integer number 3 : 3
Enter integer number 4 : 4
Enter integer number 5 : 5

The contents of the original array are : [1, 2, 3, 4, 5, ]
The contents of the expanded array are : [1, 2, 3, 4, 5, 0, 0, 0, 0, 0, ]
*/


