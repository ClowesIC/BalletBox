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
// Section: CMPSC 121
// Assignment: Homework 08 (RPS Game)
//


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//function prototypes:
int getUserSelection();
int getComputerChoice();
void determineWinner(int uChoice, int cChoice, int& uScore, int& cScore);


int main()
{

	int computerScore = 0;
	int userScore = 0;
	int cChoice;
	int uChoice;
	do {
		cChoice = getComputerChoice();
		uChoice = getUserSelection();

		determineWinner(uChoice, cChoice, userScore, computerScore);
	} while (uChoice != -1);


}

//function definitions

//user selection
int getUserSelection() {
	int decision;
	cout << "Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): ";
	cin >> decision;
	switch (decision) {
	case 1: return 1;
		break;
	case 2: return 2;
		break;
	case 3: return 3;
		break;
	case -1: return -1;
		break;
	default: cout << "Invalid choice." << endl;
		getUserSelection();

	}
}

int getComputerChoice() {
	int cChoice;
	int limit = 3;
	srand(time(0));
	cChoice = rand() % limit + 1;
	return cChoice;
	


}

//determine winner
void determineWinner(int uChoice, int cChoice, int& uScore, int& cScore) {
	
	string userChoice;
	if (uChoice == 1) {
		userChoice = "rock";
	}
	if (uChoice == 2) {
		userChoice = "paper";
	}
	if (uChoice == 3) {
		userChoice = "scissor";
	}

	string compChoice;
	if (cChoice == 1) {
		compChoice = "rock";
	}
	if (cChoice == 2) {
		compChoice = "paper";
	}
	if (cChoice == 3) {
		compChoice = "scissor";
	}

	
	if (uChoice == 1 && cChoice == 3 || uChoice == 2 && cChoice == 1 || uChoice == 3 && cChoice == 2) {
		cout << "User chooses " << userChoice << ", Computer chooses " << compChoice << endl;
		cout << "USER WINS" << endl;
		uScore = uScore + 1;
	}
	if (cChoice == 1 && uChoice == 3 || cChoice == 2 && uChoice == 1 || cChoice == 3 && uChoice == 2) {
		cout << "User chooses " << userChoice << ", Computer chooses " << compChoice << endl;
		cout << "COMPUTER WINS" << endl;
		cScore = cScore + 1;
	} 
	else if (cChoice == 1 && uChoice == 1 || cChoice == 2 && uChoice == 2 || cChoice == 3 && uChoice == 3) {
		cout << "User chooses " << userChoice << ", Computer chooses " << compChoice << endl;
		cout << "TIE. NO WINNER" << endl;
	}

	//end game
	if (uChoice == -1) {
		cout << "GAME OVER" << endl;
		if (cScore > uScore) {
			cout << "The Computer wins with a score of " << cScore << " to " << uScore;
		}
		if (uScore > cScore) {
			cout << "The User wins with a score of " << uScore << " to " << cScore;
		}
		if (uScore == cScore) {
			cout << "The game is a tie with a user score of " << uScore << " and a computer score of " << cScore;
		}
	}


}

//OUTPUT///////////////////////////////////////////////////
/*
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 1
User chooses rock, Computer chooses rock
TIE. NO WINNER
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 1
User chooses rock, Computer chooses paper
COMPUTER WINS
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 0
Invalid choice.
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 5
Invalid choice.
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 3
User chooses scissor, Computer chooses rock
COMPUTER WINS
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 2
User chooses paper, Computer chooses rock
USER WINS
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): 1
User chooses rock, Computer chooses paper
COMPUTER WINS
Make your choice (1: Rock, 2: Paper, 3: Scissor, -1: quit): -1
GAME OVER
The Computer wins with a score of 3 to 1


*/
