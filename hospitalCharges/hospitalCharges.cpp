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
// Section: CMPSC121
// Assignment: LAB08 (Hospital Charges)
//


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//function prototypes:
char getPatientType();
double patientCharges(int days, double roomchrg, double med, double serv); //In-patient
double patientCharges(double med, double serv); //outpatient
int getDaysInHospital();
double getChargesRate(string chargesItem);

//MAIN
int main()
{
	int days;
	char type;
	double roomchrg;
	double med;
	double serv;
	double totalCharge;

	cout << "This program will computer patient hospital charges." << endl;
	type = getPatientType();
	
	//get charges
	if (type == 'I') {
		days = getDaysInHospital();
		roomchrg = getChargesRate("Daily room rate");
		med = getChargesRate("Medication charges");
		serv = getChargesRate("Lab fees and other service");
		cout << endl;
		totalCharge = patientCharges(days, roomchrg, med, serv);
		cout << "The total charges are $" << totalCharge;
	}

	else if (type == 'O') {
		med = getChargesRate("Medication charges");
		serv = getChargesRate("Lab fees and other service");
		cout << endl;
		totalCharge = patientCharges(med, serv);
		cout << "The total charges are $" << totalCharge;
	}




	



}

//function definitions:

//get patient type
char getPatientType() {
	char type;
	cout << "What was the patient type?" << endl;
	cout << "Inpatient or Outpatient? (I or O): ";
	cin >> type;
	while (type != 'I' && type != 'O') {
		cout << "Invalid option, What is the patient type? (I or O): ";
		cin >> type;
	}
	if (type == 'I') {
		type = 'I';
	}
	else {
		type = 'O';
	}
	return type;
}

//get days in hospital
int getDaysInHospital() {
	int days;
	cout << "Number of days in the hospital: ";
	cin >> days;
	while (days < 0) {
		cout << "Number of days in hospital must be zero or more." << endl << "Please enter again: ";
		cin >> days;
	}
	return days;
}

//get patient charge rates
double getChargesRate(string chargesItem) {
	double charge;
	cout << chargesItem << " $:";
	cin >> charge;
	while (charge < 0) {
		cout << chargesItem << "must be zero or more." << endl << "Please enter again: ";
		cin >> charge;
	}
	return charge;

}

//total charge of IN-PATIENT
double patientCharges(int days, double roomchrg, double med, double serv) {
	double total;
	total = (days * roomchrg) + med + serv;
	return total;
}

//total charge of OUT-PATIENT
double patientCharges(double med, double serv) {
	double total;
	total = med + serv;
	return total;
}

//OUTPUTS///////////////////////////////////////////////
/*
This program will computer patient hospital charges.
What was the patient type?
Inpatient or Outpatient? (I or O): I
Number of days in the hospital: -1
Number of days in hospital must be zero or more.
Please enter again: 5
Daily room rate $:-10
Daily room ratemust be zero or more.
Please enter again: 125
Medication charges $:325.80
Lab fees and other service $:150.50

The total charges are $1101.3

///////////////////////////////////////////////////////////////


This program will computer patient hospital charges.
What was the patient type?
Inpatient or Outpatient? (I or O): O
Medication charges $:-25.50
Medication chargesmust be zero or more.
Please enter again: 85.50
Lab fees and other service $:-100
Lab fees and other servicemust be zero or more.
Please enter again: 250.90

The total charges are $336.4

*/