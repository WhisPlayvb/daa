#include <iostream> // Input-output stream for console input/output
#include <vector>   // Standard library header for using vectors
#include <cmath>    // Include the <cmath> header for abs() function

using namespace std; // Use the standard namespace

// Function to print the board
void printBoard(const vector<int>& board) {
    for (int i = 0; i < board.size(); i++) { // Loop over each row of the board
        for (int j = 0; j < board.size(); j++) { // Loop over each column of the board
            if (board[i] == j) // If there's a queen at position (i, j)
                cout << "Q "; // Print "Q" to represent the queen
            else
                cout << ". "; // Otherwise, print "." to represent an empty cell
        }
        cout << endl; // Move to the next line after printing each row
    }
    cout << endl; // Print an extra newline for clarity
}

// Function to check if a queen can be placed at position (row, col)
bool isSafe(const vector<int>& board, int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) { // Iterate over each row above the current row
        if (board[i] == col || abs(row - i) == abs(col - board[i])) // Check if there's a queen in the same column or diagonally
            return false; // If so, it's not safe to place a queen here
    }
    return true; // If no conflicts found, it's safe to place a queen at this position
}

// Recursive function to solve the problem
void solveNQueens(vector<int>& board, int row) {
    if (row == board.size()) { // Base case: if we have placed queens in all rows
        printBoard(board); // Print the current board configuration
        return; // Return to explore other possibilities
    }

    for (int col = 0; col < board.size(); col++) { // Iterate over each column in the current row
        if (isSafe(board, row, col)) { // Check if it's safe to place a queen at this position
            board[row] = col; // Place the queen at this position
            solveNQueens(board, row + 1); // Recursively solve for the next row
            board[row] = -1; // Backtrack: Reset the position of the queen for exploring other possibilities
        }
    }
}

int main() {
    int size;
    cout << "Enter the number of queens (size of the chessboard): ";
    cin >> size; // Input the size of the chessboard

    vector<int> board(size, -1); // Initialize board with -1 (no queen)

    solveNQueens(board, 0); // Call the recursive function to solve the N-Queens problem

    return 0;
}

