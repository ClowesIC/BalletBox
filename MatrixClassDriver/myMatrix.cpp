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


#include <iostream>
#include <iomanip>
#include "myMatrix.h"

typedef int ElementType;
using namespace std;


///////////////////////////////////////////////////////////////////////////////
// Functions that are already implemented by myself. Do not modify.
///////////////////////////////////////////////////////////////////////////////

void myMatrix::PrintMatrix(ostream& out) {
	int index = 0;
	for (unsigned i = 0; i < this->height; i++) {
		for (unsigned j = 0; j < this->width; j++) {
			out << setw(6) << this->myArrayPtr[index];
			index++;
		}
		out << endl;
	}
}

ostream& operator<<(ostream& out, myMatrix& matrix){
	matrix.PrintMatrix(out);
	return out;
}

unsigned myMatrix::GetHeight() {
	return this->height;
}

unsigned myMatrix::GetWidth() {
	return this->width;
}


void myMatrix::SetEntry(unsigned i, unsigned j, int valueToSet) {
	this->myArrayPtr[(i * this->width) + j] = valueToSet;
}




///////////////////////////////////////////////////////////////////////////////
// Implement required member functions below
///////////////////////////////////////////////////////////////////////////////

myMatrix::myMatrix() {
	this->height = 1;
	this->width = 1;
	this->myArrayPtr = new ElementType[height * width];

}

myMatrix::myMatrix(unsigned heightVal, unsigned widthVal, int* sourceArray) {

	height = heightVal;
	width = widthVal;

	// Allocate memory 
	myArrayPtr = new ElementType[height * width];

	// Copy the array elements
	for (unsigned i = 0; i < height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			myArrayPtr[i * width + j] = sourceArray[i * width + j];
		}
	}
}


void myMatrix::Concatenate(myMatrix& matrixToConcatenate) {
	// Ensure that the matrices have the same height for horizontal concatenation
	if (this->height != matrixToConcatenate.GetHeight()) {
		cout << "Error: Matrices must have the same height to concatenate." << endl;
		return;
	}

	// Calculate the new width after concatenation
	unsigned newWidth = width + matrixToConcatenate.GetWidth();

	// Allocate memory for the new array with the new width
	ElementType* newArrayPtr = new ElementType[this->height * newWidth];

	// Copy the values from the current matrix into the new array
	for (unsigned i = 0; i < this->height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			newArrayPtr[i * newWidth + j] = this->myArrayPtr[i * width + j];
		}
	}

	// Copy the values from the matrixToConcatenate into the new array
	for (unsigned i = 0; i < matrixToConcatenate.GetHeight(); ++i) {
		for (unsigned j = 0; j < matrixToConcatenate.GetWidth(); ++j) {
				newArrayPtr[i * newWidth + (width + j)] = matrixToConcatenate.myArrayPtr[i * matrixToConcatenate.GetWidth() + j];
		}
	}

	
	delete[] myArrayPtr;
	myArrayPtr = newArrayPtr; //replace array with new
	width = newWidth;  // Update the width of the caller matrix
}


///////////////////////////////////////////////////////////////////////////////
// Implement the overloading function for += below
///////////////////////////////////////////////////////////////////////////////

myMatrix myMatrix::operator+=(myMatrix x) {
	if (height == x.height && width == x.width) {
		for (unsigned i = 0; i < height; ++i) {
			for (unsigned j = 0; j < width; ++j) {
				myArrayPtr[i * width + j] += x.myArrayPtr[i * width + j];
			}
		}
	}
	else {
		
	}
	return *this;
}



///////////////////////////////////////////////////////////////////////////////
// Implement the "big three" below
///////////////////////////////////////////////////////////////////////////////
myMatrix::~myMatrix() {
	delete[] myArrayPtr;
}
myMatrix::myMatrix(const myMatrix& origList) {
	height = origList.height;
	width = origList.width;
	myArrayPtr = new ElementType[1024];
	for (int i = 0; i < 1024; i++) {
		myArrayPtr[i] = origList.myArrayPtr[i];
	}
}
myMatrix& myMatrix::operator=(const myMatrix& origList) {
	if (this != &origList) { 
		delete[] myArrayPtr;
		// Allocate new memory
		height = origList.height;
		width = origList.width;
		myArrayPtr = new ElementType[height * width];
		// Copy elements from the original matrix
		for (unsigned i = 0; i < height * width; i++) {
			myArrayPtr[i] = origList.myArrayPtr[i];
		}
	}
	return *this; 
}

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