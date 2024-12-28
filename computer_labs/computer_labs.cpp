#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes
void createArrays(IntPtr labs[], int labsizes[]);
void freeArrays(IntPtr labs[]);
void showLabs(IntPtr labs[], int labsizes[]);
void login(IntPtr labs[], int labsizes[]);
void logout(IntPtr labs[], int labsizes[]);
void search(IntPtr labs[], int labsizes[]);

void createArrays(IntPtr labs[], int labsizes[]) {
    for (int i = 0; i < NUMLABS; i++) {
        labs[i] = new int[labsizes[i]]; // Dynamically allocate an int array for each lab
        for (int j = 0; j < labsizes[i]; j++) {
            labs[i][j] = -1;
        }
    }
}

void freeArrays(IntPtr labs[]) {
    for (int i = 0; i < NUMLABS; i++) {
        delete[] labs[i]; // Free the dynamically allocated int array for each lab
    }
}

void showLabs(IntPtr labs[], int labsizes[]) {
    cout << "LAB STATUS" << endl;
    cout << "Lab #     Computer Stations" << endl;
    for (int i = 0; i < NUMLABS; i++) {
        cout << i + 1 << "         ";
        for (int j = 0; j < labsizes[i]; j++) {
            cout << (j + 1) << ": ";
            if (labs[i][j] == -1) {
                cout << "empty ";
            } else {
                cout << labs[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void login(IntPtr labs[], int labsizes[]) {
    int id, labNum, compNum;
    cout << "Enter the 5 digit ID number of the user logging in: ";
    cin >> id;
    cout << "Enter the lab number the user is logging in from (1-4): ";
    cin >> labNum;
    cout << "Enter the computer station number the user is logging in to (1-" << labsizes[labNum - 1] << "): ";
    cin >> compNum;

    // Log in the user by updating the labs array
    labs[labNum - 1][compNum - 1] = id;
}

void logout(IntPtr labs[], int labsizes[]) {
    int id;
    cout << "Enter the 5 digit ID number of the user logging out: ";
    cin >> id;

    // Search through the arrays to find the user ID and log them out
    for (int i = 0; i < NUMLABS; i++) {
        for (int j = 0; j < labsizes[i]; j++) {
            if (labs[i][j] == id) {
                labs[i][j] = -1; // Mark the station as empty (-1) to log out the user
                cout << "Logout user " << id << " in Lab " << (i + 1) << " at computer " << (j + 1) << endl;
                return;
            }
        }
    }

    cout << "User not logged in." << endl;
}

void search(IntPtr labs[], int labsizes[]) {
    int id;
    cout << "Enter the 5 digit ID number to search: ";
    cin >> id;

    // Search through the arrays to find the user ID
    for (int i = 0; i < NUMLABS; i++) {
        for (int j = 0; j < labsizes[i]; j++) {
            if (labs[i][j] == id) {
                cout << "User " << id << " is logged in Lab " << (i + 1) << " at computer " << (j + 1) << endl;
                return;
            }
        }
    }

    cout << "User " << id << " is not logged in." << endl;
}

int main() {
    IntPtr labs[NUMLABS]; // store the pointers to the dynamic array for each lab
    int labsizes[NUMLABS]; // Number of computers in each lab
    int choice = -1;

    cout << "Welcome to the LabMonitorProgram!\n";

    // Prompt the user to enter labsizes
    cout << "Please enter the number of computer stations in each lab:\n";
    for (int i = 0; i < NUMLABS; i++) {
        do {
            cout << "How many computers in Lab " << i + 1 << "? ";
            cin >> labsizes[i];
        } while (labsizes[i] < 0);
    }

    // Create ragged array structure
    createArrays(labs, labsizes);

    // Main Menu
    while (choice != 0) {
        cout << endl;
        cout << "MAIN MENU" << endl;
        cout << "0) Quit" << endl;
        cout << "1) Simulate login" << endl;
        cout << "2) Simulate logout" << endl;
        cout << "3) Search" << endl;
        cin >> choice;
        if (choice == 1) {
            login(labs, labsizes);
            showLabs(labs, labsizes);
        } else if (choice == 2) {
            logout(labs, labsizes);
            showLabs(labs, labsizes);
        } else if (choice == 3) {
            search(labs, labsizes);
        }
    }
    freeArrays(labs); // Free memory before exiting
    cout << "Bye!\n";
    return 0;
}
