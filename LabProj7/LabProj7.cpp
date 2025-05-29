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
// Assignment: LabProj7
//

#include <iostream>
#include <stack>
using namespace std;
/******************************************************************************
* Node class declaration.
* DO NOT modify.
******************************************************************************/
class Node {
public:
	int data;
	Node* next;
};
/******************************************************************************
* Functions you have to implement
******************************************************************************/
//Problem A: Remove part of a linked list.
void Remove(Node*& llist, unsigned startIndex, unsigned endIndex)
{
	if (llist == nullptr || startIndex > endIndex) return; //make sure there is actually a list

	Node* prev = nullptr;
	Node* current = llist;
	unsigned currentIndex = 1;


	while (current != nullptr && currentIndex < startIndex + 1) { //go to the node in the current index position
		prev = current;
		current = current->next;
		currentIndex++;
	}


	if (current == nullptr) return; //if current ends up being a null ptr return

	while (current != nullptr && currentIndex <= endIndex + 1) { //start deleting nodes from starting index to end index
		Node* temp = current;
		current = current->next;
		delete temp;
		currentIndex++;
	}

	//connect previous node to node after implemented
	if (prev != nullptr) {
		prev->next = current;
	}
	else {
		llist = current;
	}
}
//Problem B: Reversing a linked list.
void ReverseList(Node*& llist)
{
	Node* prev = nullptr;
	Node* current = llist;
	Node* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	llist = prev;
}
//Problem C: Move the smallest node to the head of a linked list.
void MoveSmallestToHead(Node*& llist)
{
	 if (llist == nullptr || llist->next == nullptr) return;

	Node* smallestPrev = nullptr;
	Node* smallest = llist;
	Node* current = llist;
	Node* prev = nullptr;

	//find smallest node by going through the list
	while (current != nullptr) {
		if (current->data < smallest->data) {
			smallest = current;
			smallestPrev = prev;
		}
		prev = current;
		current = current->next;
	}

	// Don't move if the smallest node is already at head
	if (smallest == llist) return;

	// Remove the smallest node from its current position
	if (smallestPrev != nullptr) {
		smallestPrev->next = smallest->next;
	}

	// Move the smallest node to the head
	smallest->next = llist;
	llist = smallest;
}
//Problem D: Test if a list is a palindrome.
bool IsPalindrome(Node* llist)
{
	if (llist == nullptr || llist->next == nullptr) {
		return true; // Empty list or a single node is trivially a palindrome
	}

	Node* slow = llist;
	Node* fast = llist;

	// Step 1: Find the middle of the list (slow will point to the middle)
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// Step 2: Reverse the second half of the list
	Node* prev = nullptr;
	Node* current = slow;
	Node* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	// Now prev is the head of the reversed second half

	// Step 3: Compare the first and second halves
	Node* firstHalf = llist;
	Node* secondHalf = prev;

	while (secondHalf != nullptr) {
		if (firstHalf->data != secondHalf->data) {
			return false; // The list is not a palindrome
		}
		firstHalf = firstHalf->next;
		secondHalf = secondHalf->next;
	}

	return true; // The list is a palindrome
}
/******************************************************************************
* Functions that used by the driver.
* DO NOT modify these functions.
******************************************************************************/
Node* CreateList(int* arr, int len)
{
	if (len <= 0 || arr == NULL) {
		return NULL;
	}
	Node* head = new Node();
	head->data = arr[len - 1];
	head->next = NULL;
	for (int i = 1; i < len; i++) {
		Node* temp = new Node();
		temp->next = head;
		temp->data = arr[len - i - 1];
		head = temp;
	}
	return head;
}
void RemoveAll(Node*& first)
{
	Node* cur = first;
	while (cur != NULL) {
		Node* del = cur;
		cur = cur->next;
		delete del;
	}
	first = NULL;
}
void ShowList(Node* llist)
{
	Node* cur = llist;
	if (llist == nullptr)
		cout << "<<empty list>>";
	else
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
	cout << endl;
}
/******************************************************************************
* Test driver main function.
* DO NOT modify the main function.
******************************************************************************/
#define OPTIONAL_TEST 1
// including the optional tests, each test constitute 1 point
int main() {
	cout << "Problem A, test case 1, removing [2]-[4]:" << endl;
	int a[] = { 2, 5, 8, 10, 15 };
	Node* llistA = CreateList(a, 5);
	ShowList(llistA);
	cout << "Result List:" << endl;
	Remove(llistA, 2, 4);
	ShowList(llistA);
	cout << endl;
	cout << "Problem A, test case 2, removing [0]-[3]:" << endl;
	int b[] = { 1, 6, 8, 13, 15, 26, 30 };
	Node* llistB = CreateList(b, 7);
	ShowList(llistB);
	cout << "Result List:" << endl;
	Remove(llistB, 0, 3);
	ShowList(llistB);
	cout << endl;
#if OPTIONAL_TEST == 1
	// more tests
	cout << "problem A, test case 3, removing [0]-[0]:" << endl;
	int c[] = { 1 };
	Node* llistC = CreateList(c, 1);
	ShowList(llistC);
	cout << "result list:" << endl;
	Remove(llistC, 0, 0);
	ShowList(llistC);
	cout << endl;
	cout << "problem A, test case 4, removing [0]-[6]:" << endl;
	int d[] = { 1, 6, 8, 13, 15, 26, 30 };
	Node* llistd = CreateList(d, 7);
	ShowList(llistd);
	cout << "result list:" << endl;
	Remove(llistd, 0, 6);
	ShowList(llistd);
	cout << endl;
	cout << "Problem A, test case 5, removing [1]-[3]:" << endl;
	int e[] = { 1, 6, 8, 13, 15, 26, 30 };
	Node* llistE = CreateList(e, 7);
	ShowList(llistE);
	cout << "Result List:" << endl;
	Remove(llistE, 1, 3);
	ShowList(llistE);
	cout << endl;
#endif
	///////////////////////////////////////////////////
	cout << endl << "///////////////////////////////////////////////////" << endl
		<< endl;
	RemoveAll(llistA);
	RemoveAll(llistB);
	llistA = CreateList(a, 5);
	llistB = CreateList(b, 7);
	cout << "Problem B, test case 1, reversing list:" << endl;
	ShowList(llistA);
	cout << "Reversed List:" << endl;
	ReverseList(llistA);
	ShowList(llistA);
	cout << endl;
	cout << "Problem B, test case 2, reversing list:" << endl;
	ShowList(llistB);
	cout << "Reversed List:" << endl;
	ReverseList(llistB);
	ShowList(llistB);
	cout << endl;
#if OPTIONAL_TEST == 1
	// more tests
	RemoveAll(llistC);
	llistC = CreateList(c, 1);
	cout << "Problem B, test case 3, reversing list:" << endl;
	ShowList(llistC);
	cout << "Reversed List:" << endl;
	ReverseList(llistC);
	ShowList(llistC);
	cout << endl;
	int f[] = { 1, 2 };
	Node* llistF = CreateList(f, 2);
	cout << "Problem B, test case 4, reversing list:" << endl;
	ShowList(llistF);
	cout << "Reversed List:" << endl;
	ReverseList(llistF);
	ShowList(llistF);
	cout << endl;
	Node* llistEmpty = nullptr;
	cout << "Problem B, test case 5, reversing list:" << endl;
	ShowList(llistEmpty);
	cout << "Reversed List:" << endl;
	ReverseList(llistEmpty);
	ShowList(llistEmpty);
	cout << endl;
#endif
	///////////////////////////////////////////////////
	cout << endl << "///////////////////////////////////////////////////" << endl
		<< endl;
	int j[] = { 8, 5, 10, 2, 15 };
	Node* llistJ = CreateList(j, 5);
	cout << "Problem C, test case 1, move smallest to head:" << endl;
	ShowList(llistJ);
	cout << "Resulting List:" << endl;
	MoveSmallestToHead(llistJ);
	ShowList(llistJ);
	cout << endl;
	int k[] = { 30, 26, 15, 13, 8, 6, 1 };
	Node* llistK = CreateList(k, 7);
	cout << "Problem C, test case 2, move smallest to head:" << endl;
	ShowList(llistK);
	cout << "Resulting List:" << endl;
	MoveSmallestToHead(llistK);
	ShowList(llistK);
	cout << endl;
#if OPTIONAL_TEST == 1
	// more tests
	RemoveAll(llistC);
	llistC = CreateList(c, 1);
	cout << "Problem C, test case 3, move smallest to head:" << endl;
	ShowList(llistC);
	cout << "Move smallest to head:" << endl;
	MoveSmallestToHead(llistC);
	ShowList(llistC);
	cout << endl;
	int l[] = { 1, 30, 13, 6, 8, 1, 26 };
	Node* llistL = CreateList(l, 7);
	cout << "Problem C, test case 4, move smallest to head:" << endl;
	ShowList(llistL);
	cout << "Move smallest to head:" << endl;
	MoveSmallestToHead(llistL);
	ShowList(llistL);
	cout << endl;
	cout << "Problem C, test case 5, move smallest to head:" << endl;
	ShowList(llistEmpty);
	cout << "Move smallest to head:" << endl;
	MoveSmallestToHead(llistEmpty);
	ShowList(llistEmpty);
	cout << endl;
#endif
	//////////////////////////////////////////////////
	cout << endl << "///////////////////////////////////////////////////" << endl
		<< endl;
	cout << "Problem D, test case 1, test if palindrome:" << endl;
	int g[] = { 1, 4, 6, 7, 6, 4, 1 };
	Node* llistG = CreateList(g, 7);
	ShowList(llistG);
	cout << ((IsPalindrome(llistG)) ? "True" : "False") << endl;
	cout << endl;
	cout << "Problem D, test case 2, test if palindrome:" << endl;
	int h[] = { 1, 4, 6, 7, 6, 4 };
	Node* llistH = CreateList(h, 6);
	ShowList(llistH);
	cout << ((IsPalindrome(llistH)) ? "True" : "False") << endl;
	cout << endl;
#if OPTIONAL_TEST == 1
	// more tests
	cout << "Problem D, test case 3, test if palindrome:" << endl;
	int i[] = { 1, 4, 6, 7, 4, 1 };
	Node* llistI = CreateList(i, 6);
	ShowList(llistI);
	cout << ((IsPalindrome(llistI)) ? "True" : "False") << endl;
	cout << endl;
	cout << "Problem D, test case 4, test if palindrome:" << endl;
	ShowList(llistEmpty);
	cout << ((IsPalindrome(llistEmpty)) ? "True" : "False") << endl;
	cout << endl;
	cout << "Problem D, test case 5, test if palindrome:" << endl;
	RemoveAll(llistC);
	llistC = CreateList(c, 1);
	ShowList(llistC);
	cout << ((IsPalindrome(llistC)) ? "True" : "False") << endl;
	cout << endl;
#endif
}
/*
Test Run Output
===============
Problem A, test case 1, removing [2]-[4]:
2 5 8 10 15
Result List:
2 5
Problem A, test case 2, removing [0]-[3]:
1 6 8 13 15 26 30
Result List:
15 26 30
problem A, test case 3, removing [0]-[0]:
1
result list:
<<empty list>>
problem A, test case 4, removing [0]-[6]:
1 6 8 13 15 26 30
result list:
<<empty list>>
Problem A, test case 5, removing [1]-[3]:
1 6 8 13 15 26 30
Result List:
1 15 26 30
///////////////////////////////////////////////////
Problem B, test case 1, reversing list:
2 5 8 10 15
Reversed List:
15 10 8 5 2
Problem B, test case 2, reversing list:
1 6 8 13 15 26 30
Reversed List:
30 26 15 13 8 6 1
Problem B, test case 3, reversing list:
1
Reversed List:
1
Problem B, test case 4, reversing list:
1 2
Reversed List:
2 1
Problem B, test case 5, reversing list:
<<empty list>>
Reversed List:
<<empty list>>
///////////////////////////////////////////////////
Problem C, test case 1, move smallest to head:
8 5 10 2 15
Resulting List:
2 8 5 10 15
Problem C, test case 2, move smallest to head:
30 26 15 13 8 6 1
Resulting List:
1 30 26 15 13 8 6
Problem C, test case 3, move smallest to head:
1
Move smallest to head:
1
Problem C, test case 4, move smallest to head:
1 30 13 6 8 1 26
Move smallest to head:
1 30 13 6 8 1 26
Problem C, test case 5, move smallest to head:
<<empty list>>
Move smallest to head:
<<empty list>>
///////////////////////////////////////////////////
Problem D, test case 1, test if palindrome:
1 4 6 7 6 4 1
True
Problem D, test case 2, test if palindrome:
1 4 6 7 6 4
False
Problem D, test case 3, test if palindrome:
1 4 6 7 4 1
False
Problem D, test case 4, test if palindrome:
<<empty list>>
True
Problem D, test case 5, test if palindrome:
1
True
*/
