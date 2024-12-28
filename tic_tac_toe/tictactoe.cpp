#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the Tic-Tac-Toe board
void display(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (a draw)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to randomly decide which player goes first
int decideFirstPlayer() {
    srand(time(0));
    return rand() % 2 + 1;  // Returns 1 or 2
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int currentPlayer = decideFirstPlayer();
    string player1, player2;
    char currentMarker;
    
    if (currentPlayer == 1) {
        currentMarker = 'X';
    } else {
        currentMarker = 'O';
    }

    cout << "Enter Player 1's name: ";
    cin >> player1;
    cout << "Enter Player 2's name: ";
    cin >> player2;

    cout << player1 << " vs " << player2 << endl;

    do {
        display(board);

        // Announce the current player
        //cout << (currentPlayer == 1 ? player1 : player2) << "'s turn." << endl;
        if (currentPlayer == 1) {
            cout << player1 + "'s turn." << endl;
        } else {
            cout << player2 + "'s turn." << endl;
        }

        // Get the row and column for the player's move
        int row, col;
        do {
            cout << "Enter row (1-3) and column (1-3) separated by a space: ";
            cin >> row >> col;
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');

        // Make the move
        //board[row - 1][col - 1] = (currentPlayer == 1 ? 'X' : 'O');
        if (currentPlayer == 1) {
            board[row - 1][col - 1] = 'X';
        } else {
            board[row - 1][col - 1] = 'O';
        }

        // Check for a winner or draw
        //if (checkWin(board, (currentPlayer == 1 ? 'X' : 'O'))) {
        if (checkWin(board, currentMarker)) {
            display(board);
            //cout << (currentPlayer == 1 ? player1 : player2) << " wins!" << endl;
            if (currentPlayer == 1) {
                cout << player1 + " wins!" << endl;
            } else {
                cout << player2 + " wins!" << endl;
            }
            break;
        } else if (isBoardFull(board)) {
            display(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        //currentPlayer = (currentPlayer == 1 ? 2 : 1);
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }

    } while (true);

    return 0;
}
