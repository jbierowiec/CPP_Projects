#include <iostream>

using namespace std;

double grade_converter(string let_grad) {
    
    double number_grade;

    if (let_grad == "A") {
        return number_grade = 4.0;
    } 
    else if (let_grad == "A-") {
        return number_grade = 3.666666667;
    }
    else if (let_grad == "B+") {
        return number_grade = 3.333333333;
    }
    else if (let_grad == "B") {
        return number_grade = 3.0;
    }
    else if (let_grad == "B-") {
        return number_grade = 2.666666667;
    }
    else if (let_grad == "C+") {
        return number_grade = 2.333333333;
    }
    else if (let_grad == "C") {
        return number_grade = 2.0;
    }
    else if (let_grad == "C-") {
        return number_grade = 1.666666667;
    }
    else if (let_grad == "D+") {
        return number_grade = 1.333333333;
    }
    else if (let_grad == "D") {
        return number_grade = 1.0;
    }
    else {
        return number_grade = 0.0;
    }

    return number_grade;
}

int main() {
    char option;
    string letter_grade, ugrad_class;
    int total_credit_weight = 0, credit_weight;
    int official_classes, total_classes = 0;
    double grade_conv, adjustment;
    double average, total_grade = 0;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << endl;
    cout << "This is a GPA undergraduate university calculator program" << endl;
    cout << endl;
    cout << "Enter a type of calculation you would like to make: " << endl;
    cout << "Enter (1) if you would like to calculate your GPA inputting all of your grades and grade weights: " << endl;
    cout << "Enter (2) if you would like to calculate your GPA with known earned credits and possible credits earned: " << endl;
    cin >> option;
    cin.ignore();

    if (option == '1') {
        
        do
        {
            cout << "Enter a class you took (Enter 'exit' to stop inputted classes): ";
            getline(cin, ugrad_class);
            cout << "Enter a letter grade for " << ugrad_class << " (Enter 'exit' to stop inputted grades): ";
            getline(cin, letter_grade);
            cout << "Enter the credit weight of the class (Enter '0' to stop inputted classes): ";
            cin >> credit_weight;
            cin.ignore();

            grade_conv = grade_converter(letter_grade);
            adjustment = ((grade_conv / 4) * credit_weight);

            total_grade += adjustment;
            total_credit_weight += credit_weight;
            total_classes++;

            cout << "The grade for " << ugrad_class << " is " << grade_converter(letter_grade) << "." << endl;

        } while (ugrad_class != "exit" && letter_grade != "exit" && credit_weight != 0);
    
        official_classes = total_classes - 1;

    } else if (option == '2') {
        
        cout << "Enter your total amount of earned credits: ";
        cin >> total_grade;
        cout << "Enter your total amount of credits you could have earned: ";
        cin >> total_credit_weight;
    
        official_classes = 0;
    }
    
    average = ((total_grade / total_credit_weight) * 4);

    cout << endl;
    cout << "The total number of classes you inputted is " << official_classes << "." << endl;
    cout << "The total number of earned credits you inputted is " << total_grade << "." << endl;
    cout << "The total number of credits you could have earned is " << double(total_credit_weight) << "." << endl;
    cout << "Your average Grade Point Average (GPA) is: " << average << "." << endl;
    cout << endl;

    return 0;
}