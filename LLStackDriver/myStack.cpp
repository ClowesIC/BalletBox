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
// Assignment: Inlab08
//


#include "myStack.h"
#include <iostream>

using namespace std;

myStack::myStack() {
	this->mySize = 0;
	this->stackContents = NULL;
}

void myStack::push(ElementType data) {
	Node* previousFirst = this->stackContents;
	this->stackContents = new Node;
	this->stackContents->data = data;
	this->stackContents->next = previousFirst;
	this->mySize += 1;
}

void myStack::pop() {
	Node* previousFirst = this->stackContents;
	this->stackContents = this->stackContents->next;
	delete previousFirst; 

	this->mySize -= 1;
	

}

ElementType myStack::top() {
	if (this->mySize <= 0) {
		throw std::out_of_range("Trying to perform top on empty stack!");
	}
	return this->stackContents->data;
}

int myStack::size() {
	return this->mySize;
}
/*
Driver program to test the myStack class.
A stack for testing is created.
Value 1 pushed to stack.
Current top element of stack is 1
Value 3 pushed to stack.
Current top element of stack is 3
Value 10 pushed to stack.
Current top element of stack is 10
Value 23 pushed to stack.
Current top element of stack is 23
A value is popped from the stack.
Current top element of stack is 10
Value 9 pushed to stack.
Current top element of stack is 9
Three values are popped from the stack.
Current top element of stack is 1
*/