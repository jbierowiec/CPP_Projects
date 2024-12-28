#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float tipamount(int percent, float total_bill) {
    float tip_percent = percent/100.0;
    float tip = (tip_percent*total_bill);

    return tip;
}

float totalwithtipamount(float total_bill, float new_percent) {

    float calctip;
    calctip = total_bill + new_percent;

    return calctip;
}

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    float total_bill, new_total_bill, split_total_bill, split_new_total_bill;
    float tip, split_tip;
    int percent, num_people;
    int round_up_tip, round_down_tip;
    float new_percent;
    char choice, tip_choice, bill_choice;

    do
    {
        cout << endl;
        cout << "Welcome to the tipping calculator!" << endl << endl;
    
        cout << "Enter your total billing amount: ";
        cin >> total_bill; 
        cout << "What percentage would you like to tip? ";
        cin >> percent;

        
        tip = tipamount(percent, total_bill);
        new_total_bill = totalwithtipamount(total_bill, tip);
        //totalwithtipamount(total_bill, tip);

        cout << endl;

        cout << "Your total amount is:                       $" << total_bill << endl;
        cout << "Your total tip amount is:                   $" << tip << endl;
        cout << "Your total with the tip amount is:          $" << new_total_bill << endl << endl;

        cout << "Would you like to round the tip up or down or keep it as it is? (u/d/k): ";
        cin >> tip_choice;

        if (tip_choice == 'u') {
            round_up_tip = int(tip + 1);
            cout << endl << "Your tip amount is                          $" << round_up_tip << endl;
            tip = round_up_tip;
        }
        else if (tip_choice == 'd') {
            round_down_tip = int(tip);
            cout << endl << "Your tip amount is                          $" << round_down_tip << endl;
            tip = round_down_tip;
        }
        else if (tip_choice == 'k') {
            cout << endl << "Your tip amount is                          $" << tip << endl;
        }
        else {
            cout << "Invalid input" << endl;
        }

        cout << endl << "Would you like to split the bill? ";
        cin >> bill_choice;

        if (bill_choice == 'y') {
            cout << "How many people do you want to split the bill with? ";
            cin >> num_people;

            //new_total_bill = round(new_total_bill * 100) / 100;

            split_total_bill = total_bill/num_people;
            split_tip = tip/num_people;
            split_new_total_bill = split_total_bill + split_tip;

            split_new_total_bill = round(split_new_total_bill * 100) / 100;

            cout << endl;

            cout << "Your new total bill for " << num_people << " is:               $" << split_total_bill << endl;
            cout << "Your new total tip for " << num_people << " is:                $" << split_tip << endl;
            cout << "Your new total bill with tip for " << num_people << " is:      $" << split_new_total_bill << endl;

            if(new_total_bill > (float(num_people) * split_new_total_bill)) {
                float bill_difference = abs(new_total_bill - (float(num_people) * split_new_total_bill));

                bill_difference = round(bill_difference * 100) / 100;

                cout << new_total_bill << endl;
                cout << num_people * split_new_total_bill << endl;
                cout << "You have saved $" << bill_difference << endl;
            }

            else if(new_total_bill < (float(num_people) * split_new_total_bill)) {
                float bill_difference = abs(new_total_bill - (float(num_people) * split_new_total_bill));

                bill_difference = round(bill_difference * 100) / 100;

                cout << new_total_bill << endl;
                cout << num_people * split_new_total_bill << endl;
                cout << "You have lost $" << bill_difference << endl;
            }
        }

        else if (bill_choice != 'n') {
            cout << "Invalid input" << endl;
        }

        cout << endl << "Thank you for using the tipping calculator!" << endl << endl;

        cout << "Would you like to recalculate? ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}