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
// Assignment: HOMEWORK 9 (PART 2)
//


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Function prototypes:
double getPrice();
string getName();
void display(const vector<string>& names, const vector<double>& prices);

int main()
{
    vector<string> names;
    vector<double> prices;
    string name;

    while (true) {
        name = getName();
        if (name == "Done") {
            break; // Exit the loop if the user enters "Done"
        }
        names.push_back(name);
        prices.push_back(getPrice());
    }

    display(names, prices);
    return 0;
}

// Function to get the name of the item
string getName() {
    string name;
    cout << "What is the name of the item? ";
    cin >> name;
    return name;
}

// Function to get the price of the item
double getPrice() {
    double price;
    cout << "What is the price? ";
    cin >> price;
    while (price <= 0) {
        cout << "Invalid price. Please enter a valid price: ";
        cin >> price;
    }
    return price;
}

// Function to display items, prices, subtotal, tax, and total
void display(const vector<string>& names, const vector<double>& prices) {
    double subtotal = 0.0;

    cout << setprecision(2) << fixed;
    for (int i = 0; i < names.size(); i++) {
        cout << setw(24) << left << names[i] << right << "$" << prices[i] << endl;
        subtotal += prices[i];
    }

    double tax = 0.06 * subtotal; 
    double total = subtotal + tax;

    cout << "\nSubtotal: $" << subtotal << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Total: $" << total << endl;
}

//DISPLAY////////////////////////
/*
What is the name of the item? Hamburger
What is the price? 2.34
What is the name of the item? Fries
What is the price? 4.50
What is the name of the item? Drink
What is the price? 3.40
What is the name of the item? Done
Hamburger               $2.34
Fries                   $4.50
Drink                   $3.40

Subtotal: $10.24
Tax: $0.61
Total: $10.85







*/
