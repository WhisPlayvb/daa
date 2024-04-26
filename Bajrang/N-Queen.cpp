#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int> >& board, int row, int col) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1)
            return false;
    }
    
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1)
            return false;
    }
    
    // Check lower diagonal on left side
    for (int i = row, j = col; i < board.size() && j >= 0; ++i, --j) {
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}

bool solveQueens(vector<vector<int> >& board, int col) {
    // Base case: if all queens are placed
    if (col >= board.size())
        return true;
    
    // Try placing queen in each row of the current column
    for (int i = 0; i < board.size(); ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            
            // Recur to place queens in next columns
            if (solveQueens(board, col + 1))
                return true;
            
            // Backtrack if placing queen leads to failure
            board[i][col] = 0;
        }
    }
    
    // If no solution found for this column
    return false;
}

void printSolution(const vector<vector<int> >& board) {
//    for (const auto& row : board) {
//        for (int cell : row) {
//            cout << cell << " ";
//        }
//        cout << endl;
//    }
for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
        cout << board[i][j] << " ";
    }
    cout << endl;
}

}

void solveEightQueens() {
    vector<vector<int> > board(8, vector<int>(8, 0));  // Create an empty 8x8 board
    
    if (solveQueens(board, 0)) {
        cout << "Solution exists. Placing queens:" << endl;
        printSolution(board);
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    solveEightQueens();
    return 0;
}
