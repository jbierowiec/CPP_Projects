#include <iostream>
using namespace std;

int main() {

    double length, width, area;

    cout << endl;
    cout << "Enter two values for this area program" << endl;
    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter the width:  ";
    cin >> width;
    cout << endl;

    area = length * width;

    cout << "The area is: " << area << " m^2" << endl;
    cout << endl;
    
    return 0;
}