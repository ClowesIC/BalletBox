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
// Section: CMPSCI 122 - L002
// Assignment: LabProj2
//


#include <iostream>

using namespace std;

//function prototype:
void bestStrategy(int days[], int SIZE);

int main() {
	const int SIZE = 12;
	int days[SIZE];

	//prompt user input price history
	cout << "Please type the 12-day price history of the stock: " << endl;
	for (int i = 0; i < SIZE; i++) {
		cin >> days[i];
        cin.ignore(1);
	}


    //calulate best strategy for profit
    bestStrategy(days, SIZE);
}

//function definition:
void bestStrategy(int days[], int SIZE) {
    int maxProfit = 0;
    int bestBuyDay = 0;
    int bestSellDay = 0;

    // Iterate through each possible buy day
    for (int i = 0; i < SIZE - 3; i++) {  //Buy day, must be at least 3 days until sell day
        for (int j = i + 3; j < SIZE; j++) {  // Sell day, which is 3 days after buy
            int profit = (days[j] - days[i]) * (1000 / days[i]);

            // Update the maximum profit and best buy/sell days if a new max profit is found
            if (profit > maxProfit) {
                maxProfit = profit;
                //update days
                bestBuyDay = i + 1;
                bestSellDay = j + 1;
            }
        }

    }

    //display
    if (maxProfit <= 0) {
        cout << "Max Profit: " << maxProfit << endl;
    }
    else {
        cout << "Max Profit: " << maxProfit << endl;
        cout << "Best Strategy: buy on day " << bestBuyDay << ", sell on day " << bestSellDay << "." << endl;
    }
}

	
//OUTPUTS//////////////

/*
Please type the 12-day price history of the stock:
50 200 100 30 20 25 40 10 5 35 45 20
Max Profit: 3500
Best Strategy: buy on day 8, sell on day 11.

Please type the 12-day price history of the stock:
50 100 50 40 40 40 40 40 40 40 40 40
Max Profit: 0

*/



    
