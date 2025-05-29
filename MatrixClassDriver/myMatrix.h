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
// Section: CMPSCI 122 - 002LAB
// Assignment: LabProj6
//




#pragma once

#include <iostream>

using namespace std;

class myMatrix {
public:
	///////////////////////////////////////////////////////////////////////////
	// Member functions you need to implement:
	///////////////////////////////////////////////////////////////////////////

	// 1. The default constructor. 
	// Initialize the matrix to a 1x1 matrix with entry 0
	
	myMatrix();

	// 2. The Second constructor. 
    // Initialize the matrix of given height and width with elements from a given array

	myMatrix(unsigned heightVal, unsigned WidthVal, int * sourceArray);
	
	// 3. Concatenate function.
	// Concatenates a matrix of the same height to the right of the caller matrix

	void Concatenate(myMatrix & matrixToConcatenate);

	// 4. Overloading of the += operator. Suggest using internal method.

	// !! ADD declaration line for the overloading function yourself !!

	myMatrix operator+=(myMatrix x);

	// 5,6,7: The "big three"

	// !! ADD declaration lines for the "big three" functions yourself !!

	~myMatrix(); //deconstructor
	myMatrix(const myMatrix& origList); //copy constructor
	myMatrix& operator=(const myMatrix& origList); //overload assignment operator 



	///////////////////////////////////////////////////////////////////////////
	// Member functions I have already implemented. Do not touch.
	///////////////////////////////////////////////////////////////////////////

	unsigned GetHeight();
	unsigned GetWidth();
	void PrintMatrix(ostream & out);
	void SetEntry(unsigned i, unsigned j, int valueToSet);

private:
	unsigned height;
	unsigned width;
	int* myArrayPtr;
};

// Overloading the << operator for easy output
ostream& operator<<(ostream& out, myMatrix& matrix);

//OUTPUT///////////
/*
The following shows a matrix created using the default constructor:

-842150451


The following shows a matrix created using the second constructor:

	 2     3     4     5     6
	 3     4     5     6     2
	 1     3     5     7     9
	 2     4     6     8    10


Trying to concatenate two matrices. Matrix A:

	 2     3     4     5     6
	 3     4     5     6     2
	 1     3     5     7     9
	 2     4     6     8    10


Matrix B:

	 0     1
	 1     0
	 1     1
	 0     0


After concatenating B to the right of A. A becomes:

	 2     3     4     5     6     0     1
	 3     4     5     6     2     1     0
	 1     3     5     7     9     1     1
	 2     4     6     8    10     0     0


Testing the copy constructor.
The following shows a Matrix C, created from copying the Matrix B above:

	 0     1
	 1     0
	 1     1
	 0     0


Now, we make some changes to matrix C. It becomes:

	 0     5
	 1     0
	 4     1
	 0     0


We print matrix B in the following. Note if the implementation is correct,
changing matrix C should not affact matrix B!

	 0     1
	 1     0
	 1     1
	 0     0


Testing the assignment operator.
The following shows a Matrix D, which is assigned with the Matrix B above:

	 0     1
	 1     0
	 1     1
	 0     0


Now, we make some changes to matrix D. It becomes:

	 0     1
	 1    10
	 1     1
	28     0


We print matrix B in the following. Note if the implementation is correct,
changing matrix D should not affact matrix B!

	 0     1
	 1     0
	 1     1
	 0     0


Adding matrix D to matrix B using the += operator.
After this, the matrix B becomes:
	 0     2
	 2    10
	 2     2
	28     0


Testing compatibility issue using += operator
Matrix A dimension: 4 x 7 and Matrix B dimension: 4 x 2
Perform A += B and failed!
Matrix A remains the same after the failed operation
	 2     3     4     5     6     0     1
	 3     4     5     6     2     1     0
	 1     3     5     7     9     1     1
	 2     4     6     8    10     0     0





*/