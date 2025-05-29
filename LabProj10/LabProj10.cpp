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
// Section: CMPSCI 122 - 002L
// Assignment: LabProj10
//

#include <iostream>
#include "timer.h"

using namespace std;

// Function declaration
int paths(int n, int e);

int main() {
    int north;
    int east;
    char cont = 'y';
    Timer t;

    while (cont == 'y' || cont == 'Y') {
        cout << "How many points north of A is B? ";
        cin >> north;
        cout << "How many points east of A is B? ";
        cin >> east;

        //start timer
        t.start();

        //calculate paths
        int result = paths(north, east);

        //stop timer
        t.stop();

        //display
        cout << "There are " << result << " northeast paths between A and B." << endl;
        t.show();

        cout << "Enter y or Y to continue the next example or any other letter to exit: ";
        cin >> cont;
    }

    return 0;
}

//function definition
int paths(int n, int e) {

    if (n == 0 || e == 0) {
        return 1;
    }
    return paths(n - 1, e) + paths(n, e - 1);
}

/*
How many points north of A is B? 2
How many points east of A is B? 3
There are 10 northeast paths between A and B.
  Process Timer
  -------------------------------
  Elapsed Time: 0.001s
Enter y or Y to continue the next example or any other letter to exit: y
How many points north of A is B? 12
How many points east of A is B? 14
There are 9657700 northeast paths between A and B.
  Process Timer
  -------------------------------
  Elapsed Time: 0.171s
Enter y or Y to continue the next example or any other letter to exit: y
How many points north of A is B? 16
How many points east of A is B? 16
There are 601080390 northeast paths between A and B.
  Process Timer
  -------------------------------
  Elapsed Time: 9.02s
Enter y or Y to continue the next example or any other letter to exit: n*/
