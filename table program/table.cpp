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
// Section: CMPSCI 122 - 002Lab
// Assignment: LabProj8
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to hold customer information
struct Customer {
    string name;
    Customer(string name) { //constructor
        this->name = name;
    }
};

class Restaurant {
private:
    int smallTables, largeTables;
    int smallTablesTaken = 0, largeTablesTaken = 0;
    queue<Customer> smallWaitList;
    queue<Customer> largeWaitList;

public:
    Restaurant(int smallTables, int largeTables) { //constructor 
        this->smallTables = smallTables;
        this->largeTables = largeTables;
    }

    // Add a new customer requesting a large table
    void newLargeCustomer(const string& name) {
        if (largeTablesTaken < largeTables) {
            largeTablesTaken++;
            cout << "New customer " << name << " takes an available large table." << endl;
        }
        else {
            largeWaitList.push(Customer(name));
            cout << "New customer " << name << " enters the large waiting line." << endl;
        }
    }

    // Add a new customer requesting a small table
    void newSmallCustomer(const string& name) {
        if (smallTablesTaken < smallTables) {
            smallTablesTaken++;
            cout << "New customer " << name << " takes an available small table." << endl;
        }
        else if (largeTablesTaken < largeTables) {
            largeTablesTaken++;
            cout << "New customer " << name << " takes an available large table." << endl;
        }
        else {
            smallWaitList.push(Customer(name));
            cout << "New customer " << name << " enters the small waiting line." << endl;
        }
    }

    // Checkout a large table (free up a large table)
    void checkoutLarge() {
        if (largeTablesTaken > 0) {
            largeTablesTaken--;
            if (!largeWaitList.empty()) {
                Customer nextCustomer = largeWaitList.front();
                largeWaitList.pop();
                largeTablesTaken++;
                cout << "New large table seat(s) is available." << endl;
                cout << "Next customer " << nextCustomer.name << " takes an available large table." << endl;
            }
            else {
                cout << "No customer occupied any large table!" << endl;
            }
        }
        else {
            cout << "No customer occupied any large table!" << endl;
        }
    }

    // Checkout a small table (free up a small table)
    void checkoutSmall() {
        if (smallTablesTaken > 0) {
            smallTablesTaken--;
            if (!smallWaitList.empty()) {
                Customer nextCustomer = smallWaitList.front();
                smallWaitList.pop();
                smallTablesTaken++;
                cout << "New small table seat(s) is available." << endl;
                cout << "Next customer " << nextCustomer.name << " takes an available small table." << endl;
            }
            else if (!largeWaitList.empty()) {
                Customer nextCustomer = largeWaitList.front();
                largeWaitList.pop();
                largeTablesTaken++;
                cout << "New small table seat(s) is available." << endl;
                cout << "Next customer " << nextCustomer.name << " takes an available large table." << endl;
            }
            else {
                cout << "No customer occupied any small table!" << endl;
            }
        }
        else {
            cout << "No customer occupied any small table!" << endl;
        }
    }

    // Show the current status of tables and waiting lists
    void showInfo() {
        cout << "Small tables: " << smallTablesTaken << " / " << smallTables << endl;
        cout << "Large tables: " << largeTablesTaken << " / " << largeTables << endl;
        cout << smallWaitList.size() << " customer(s) waiting for small table." << endl;
        cout << largeWaitList.size() << " customer(s) waiting for large table." << endl;
    }
};

int main() {
    int smallTables, largeTables;
    string command, tableSize, name;

    cout << "Welcome to the Restaurant Table Management System." << endl;
    cout << "Enter the total number of large tables: ";
    cin >> largeTables;
    cout << "Enter the total number of small tables: ";
    cin >> smallTables;

    Restaurant restaurant(smallTables, largeTables);

    cin.ignore();

    while (true) {
        cout << "Enter Command: ";
        getline(cin, command);

        if (command.substr(0, 3) == "new") { // substr is used here to determine specific command by extracting inputted string
            command = command.substr(4);

            size_t spacePos = command.find(' ');

            if (spacePos != string::npos) {
                tableSize = command.substr(0, spacePos);
                name = command.substr(spacePos + 1);
            }
            else {
                cout << "Invalid command!" << endl;
                continue;
            }

            if (tableSize == "large") {
                restaurant.newLargeCustomer(name);
            }
            else if (tableSize == "small") {
                restaurant.newSmallCustomer(name);
            }
            else {
                cout << "Invalid table size!" << endl;
            }
        }
        else if (command.substr(0, 8) == "checkout") {
            command = command.substr(9);

            if (command == "large") {
                restaurant.checkoutLarge();
            }
            else if (command == "small") {
                restaurant.checkoutSmall();
            }
            else {
                cout << "Invalid table size!" << endl;
            }
        }
        else if (command == "info") {
            restaurant.showInfo();
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}

//OUTPUT
/*
Welcome to the Restaurant Table Management System.
Enter the total number of large tables: 5
Enter the total number of small tables: 5
Enter Command: new large Mike
New customer Mike takes an available large table.
Enter Command: new large Tim
New customer Tim takes an available large table.
Enter Command: new large Andrew
New customer Andrew takes an available large table.
Enter Command: new small Jared
New customer Jared takes an available small table.
Enter Command: new large Joshua
New customer Joshua takes an available large table.
Enter Command: new large Alex
New customer Alex takes an available large table.
Enter Command: new large Harold
New customer Harold enters the large waiting line.
Enter Command: info
Small tables: 1 / 5
Large tables: 5 / 5
0 customer(s) waiting for small table.
1 customer(s) waiting for large table.
Enter Command: exit
Invalid command!
Enter Command: checkout large
New large table seat(s) is available.
Next customer Harold takes an available large table.
Enter Command: info
Small tables: 1 / 5
Large tables: 5 / 5
0 customer(s) waiting for small table.
0 customer(s) waiting for large table.
Enter Command:
*/