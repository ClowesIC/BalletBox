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
// Assignment: Homework09 (Voting)
//


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Function prototypes
int getVote(vector<string> names, int score[]);
void winner(int score[], const vector<string>& names);

int main() {
    const int num = 4;
    int score[num] = { 0 }; // Initialize scores to zero
    vector<string> names{ "Tim", "Satya", "Sunder", "Elon" };

    // Loop for voting
    while (true) {
        int voteResult = getVote(names, score);
        if (voteResult == 4) {
            winner(score, names);
            break; // Exit loop if "quit" is entered
        }
    }

    return 0;
}

// Function to get a vote
int getVote(vector<string> names, int score[]) {
    string vote;
    cout << "Who do you want to vote for (Tim, Satya, Sunder, or Elon)? ";
    cin >> vote;

    while (vote != "Tim" && vote != "Satya" && vote != "Sunder" && vote != "Elon" && vote != "quit") {
        cout << "That is an invalid choice." << endl;
        cout << "Who do you want to vote for (Tim, Satya, Sunder, or Elon)? ";
        cin >> vote;
    }

    for (int i = 0; i < 4; i++) {
        if (vote == names[i]) {
            score[i]++; // Increment the score for the chosen name
            cout << "One vote has been added to " << names[i] << "'s count." << endl;
            return score[i]; // Return the updated score
        }
    }

    if (vote == "quit") {
        return 4; // Indicate to quit
    }

    return 0; // Default return
}

// Function to determine and display the winner
void winner(int score[], const vector<string>& names) {
    int highest = score[0];
    int winnerIndex = 0;

    // Determine the highest score
    for (int count = 1; count < 4; count++) {
        if (score[count] > highest) {
            highest = score[count];
            winnerIndex = count; // Keep track of the winner index
        }
    }

    // Display results
    for (int i = 0; i < 4; i++) {
        cout << setw(6) << left << names[i] << ": " << right << score[i];
        if (i == winnerIndex) {
            cout << "  **WINNER**";
        }
        cout << endl;
    }
}