#include <iostream>
#include <vector>
#include <cmath> // Include the <cmath> header for abs() function

using namespace std;

// Function to print the board
void printBoard(const vector<int>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed at position (row, col)
bool isSafe(const vector<int>& board, int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(row - i) == abs(col - board[i]))
            return false;
    }
    return true;
}

// Recursive function to solve the problem
void solveNQueens(vector<int>& board, int row) {
    if (row == board.size()) {
        printBoard(board);
        return;
    }

    for (int col = 0; col < board.size(); col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1);
            board[row] = -1; // backtrack
        }
    }
}

int main() {
    int size;
    cout << "Enter the number of queens (size of the chessboard): ";
    cin >> size;

    vector<int> board(size, -1); // Initialize board with -1 (no queen)

    solveNQueens(board, 0);

    return 0;
}


//Time Complexity : O((m + q) log^2 n)
//Space Complexity : O((m + q) log n)


