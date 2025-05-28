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
// Section: COMPSCI 121
// Assignment: LAB 09 (C to F)
//

#include <iostream>
#include <cmath>
using namespace std;

//function prototypes:
void getTemperature(double temp[], int size);
void convertTemperature(double c_temp[], double f_temp[], int size);


int main()
{
	const int num = 5;
	int size = num;
	double temp[num];
	double c_temp[num];
	double f_temp[num];

	//get user inputted temps
	getTemperature(temp, size);
	//give all of the temp values to the celcius array elements:
	for (int index = 0; index < 4; index++) {
		c_temp[index] = temp[index];
	}
	//convert temp to F
	convertTemperature(c_temp, f_temp, size);



}

//function definitions:
void getTemperature(double temp[], int size) {
	for (int index = 1; index < size; index++) {
		cout << "Enter Celsius temperature " << index << ": ";
		cin >> temp[index-1];
		while (temp[index-1] <= -273.15) {
			cout << "The temperature must be greater than -273.15" << endl;
			cout << "Enter celcius temperature " << index << ": ";
			cin >> temp[index-1];
		}
	}
}

void convertTemperature(double c_temp[], double f_temp[], int size) {

	for (int index = 1; index < size; index++) {
		f_temp[index - 1] = (9.0 / 5) * c_temp[index - 1] + 32;
		cout << c_temp[index - 1] << " degrees Celsius is " << f_temp[index - 1] << " degrees Fahrenheit" << endl;
	}

}


//OUTPUT//////////////////////////////////////////////////////////////

/*
Enter Celsius temperature 1: -274
The temperature must be greater than -273.15
Enter celcius temperature 1: -31
Enter Celsius temperature 2: 0
Enter Celsius temperature 3: 13.25
Enter Celsius temperature 4: 100
-31 degrees Celsius is -23.8 degrees Fahrenheit
0 degrees Celsius is 32 degrees Fahrenheit
13.25 degrees Celsius is 55.85 degrees Fahrenheit
100 degrees Celsius is 212 degrees Fahrenheit

*/
