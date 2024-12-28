#include <iostream>
using namespace std;

int main() {

    // variable declaration
    string username;
    int numCoffee, numBagel, numDonut;
    double payment, change;

    cout.setf(ios::fixed);
    cout.precision(2);

    double coffee = 2.50;
    double bagel = 1.75;
    double donut = 1.00;
    double tax = 1.085;
    
    double coffeeTotal, bagelTotal, donutTotal, total, total_no_tax;

    bool not_valid;

    // welcoming message and asking of basic questions to the user
    cout << "Welcome to our Coffee Shop!" << endl;
    cout << endl;
    cout << "Enter your first name:                                 ";
    getline(cin, username);

    cout << endl;
    cout << "Welcome " << username << "!" << endl;
    cout << endl;
    cout << "Enter the number of coffees you would like to buy:     ";
    cin >> numCoffee;
    cout << "Enter the number of bagels you would like to buy:      ";
    cin >> numBagel;
    cout << "Enter the number of donuts you would like to buy:      ";
    cin >> numDonut;

    // calculation definition

    coffeeTotal = coffee * numCoffee;
    bagelTotal = bagel * numBagel;
    donutTotal = donut * numDonut;

    total_no_tax = coffeeTotal + bagelTotal + donutTotal;

    total = total_no_tax * tax;

    cout << endl;
    cout << "Your total comes out to be: $" << total << "." << endl;
    cout << endl;
    
    // ONE TIME OPTION WHERE PROGRAM CONTINUES OR QUITS REGARDLESS OF CHOICE

    /*
    cout << "How much would you like to pay? Enter your value here: ";
    cin >> payment;

    change = payment - total;

    if (change > 0) {
        cout << "Your change is: " << change << endl;
    } else if (change < 0) {
        cout << "You have to pay more!" << endl;
    }
    else {
        cout << "Invalid input!" << endl;
    }
    */

   // DO WHILE OPTION -> REPEATING PAYMENT IF INVALID INPUT 

    do {
        cout << "How much would you like to pay? Enter your value here: $";
        cin >> payment;

        change = payment - total;

        if (change >= 0) {
            cout << "Your change is: $" << change << endl;
        } else if (change < 0) {
            cout << "You have to pay more!" << endl;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    } while(change < 0);

    // output of reciept to the user

    cout << endl;
    cout << "Here is your reciept!" << endl;
    cout << endl;
    cout << "Name:                  " << username << endl;
    cout << endl;
    cout << "Number of coffees:     " << numCoffee << endl;
    cout << "Number of bagels:      " << numBagel << endl;
    cout << "Number of donuts:      " << numDonut << endl;
    cout << endl;
    cout << "Total before tax:      $" << total_no_tax << endl;
    cout << "Tax percentage:        " << tax << "%" << endl;
    cout << "Total with tax:        $" << total << endl;
    cout << "Amount paid:           $" << payment << endl;
    cout << "Change:                $" << change << endl;
    cout << endl; 
    cout << "Thank you for shopping at the Coffee Shop! Have a nice day!" << endl;
    cout << endl;

    return 0;
}