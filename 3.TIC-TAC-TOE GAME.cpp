#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) // Check rows
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) // Check columns
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) // Check main diagonal
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) // Check secondary diagonal
        return true;
    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the empty board
    char currentPlayer = 'X'; // Player X starts the game

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        int row, col;
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    }

    return 0;
}
