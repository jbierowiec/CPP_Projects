#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 5;

void fillArrays(string names[], double prices[], int quantities[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter information for item #" << i + 1 << ":\n";
        cout << "Name: ";
        cin >> names[i];
        cout << "How much of that item?: ";
        cin >> quantities[i];
        cout << "Price per item: $";
        cin >> prices[i];
        cout << endl;
    }
}

double calculateTotalCost(const double prices[], const int quantities[]) {
    double totalCost = 0;
    for (int i = 0; i < SIZE; i++) {
        totalCost += prices[i] * quantities[i];
    }
    return totalCost;
}

void printShoppingList(const string names[], const double prices[], const int quantities[]) {
    cout << "This week's shopping list:" << endl;
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << names[i] << endl;
        cout << "Quantity: " << quantities[i] << endl;
        cout << "Price: $" << fixed << setprecision(2) << prices[i] * quantities[i] << endl;
        cout << endl;
    }

    double totalCost = calculateTotalCost(prices, quantities);
    cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
}

int main() {
    string names[SIZE];
    double prices[SIZE];
    int quantities[SIZE];

    cout << endl;
    fillArrays(names, prices, quantities);
    printShoppingList(names, prices, quantities);

    return 0;
}
