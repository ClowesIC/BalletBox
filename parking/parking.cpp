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
// Section: CMPSC121 LAB003
// Assignment: LAB05 (Parking Rate)
//


#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	float hours;
	string vehicle;
	string licensePlate;
	float amountDue;
	char letter;


	//User enters input
	cout << "Enter the vehicle type ('C' for car, 'T' for truck. 'B' for bus): ";
	cin >> letter;
	//test if input is valid
	if (letter != 'C' && letter != 'T' && letter != 'B') {
		cout << "That is an invalid vehicle type";
	}
	
	//normal program execution
	cout << "Enter the number of hours parked: ";
	cin >> hours;
	cout << "What is the license plate? ";
	cin.ignore();
	getline(cin, licensePlate);
	
	//assign output based on input and display
	//round hours
	hours = ceil(hours);
	double rate;

	switch (letter)
	{
	case 'C' : vehicle = "Car";
		if (hours <= 2) {
			rate = 1.25 * hours;
		}
		if (hours >= 2) {
			double firstRate = 1.25 * 2;
			rate = firstRate + 1.5 * (hours - 2);
		}
		
		// display
		cout << endl << "Vehicle Type: " << vehicle << endl;
		cout << "Time: " << hours << " hours" << endl;
		cout << "Licence Plate: " << licensePlate << endl;
		cout << setprecision(2) << fixed;
		cout << "Amount Due ($): " << rate;
		
		break;
	
	case 'T' : vehicle = "Truck";
		if (hours <= 2) {
			rate = 2.75 * hours;
		}
		if (hours >= 2) {
			double firstRate = 2.75 * 2;
			rate = firstRate + 3.75 * (hours - 2);
		}

		//display
		cout << endl << "Vehicle Type: " << vehicle << endl;
		cout << "Time: " << hours << " hours" << endl;
		cout << "Licence Plate: " << licensePlate << endl;
		cout << setprecision(2) << fixed;
		cout << "Amount Due ($): " << rate;
		
		break;
	
	case 'B': vehicle = "Bus";
		if (hours <= 1) {
			rate = 9.50 * hours;
		}
		if (hours >= 1) {
			double firstRate = 9.50;
			rate = firstRate + 6.75 * (hours - 1);
		}
		
		//display
		cout << endl << "Vehicle Type: " << vehicle << endl;
		cout << "Time: " << hours << " hours" << endl;
		cout << "Licence Plate: " << licensePlate << endl;
		cout << setprecision(2) << fixed;
		cout << "Amount Due ($): " << rate;

		break;
	
	default: cout << "You did not enter a valid vehicle type";


	}



}

//OUTPUT TESTS/////////////////////////
/*
Enter the vehicle type ('C' for car, 'T' for truck. 'B' for bus): C
Enter the number of hours parked: 4.0
What is the license plate? ABC 123

Vehicle Type: Car
Time: 4 hours
Licence Plate: ABC 123
Amount Due ($): 5.50

////////////////////////////////////////////////////

Enter the vehicle type ('C' for car, 'T' for truck. 'B' for bus): T
Enter the number of hours parked: 9.4
What is the license plate? JCD 8678

Vehicle Type: Truck
Time: 10 hours
Licence Plate: JCD 8678
Amount Due ($): 35.50

/////////////////////////////////////////////////////////////

Enter the vehicle type ('C' for car, 'T' for truck. 'B' for bus): B
Enter the number of hours parked: 2.7
What is the license plate? SBS 4556

Vehicle Type: Bus
Time: 3 hours
Licence Plate: SBS 4556
Amount Due ($): 23.00

*/

