#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }

    for (int row = x, col = y; row >= 0 && col >= 0; row--, col--) {
        if (arr[row][col] == 1) {
            return false;
        }
    }

    for (int row = x, col = y; row >= 0 && col < n; row--, col++) {
        if (arr[row][col] == 1) {
            return false;
        }
    }

    return true;
}

bool nQueen(int** arr, int x, int n, int& solutionCount, int maxSolutions) {
    if (x >= n) {
        if (solutionCount < maxSolutions) {
            cout << "Solution " << solutionCount + 1 << ":\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            solutionCount++;
            return true; 
        } else {
            return false; 
        }
    }

    bool res = false;
    for (int col = 0; col < n; col++) {
        if (isSafe(arr, x, col, n)) {
            arr[x][col] = 1; 

            res = nQueen(arr, x + 1, n, solutionCount, maxSolutions) || res;

            arr[x][col] = 0; 
        }
    }

    return res; 
}

int main() {
    int n;
    cout << "Enter number of queens you want to place: ";
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    int maxSolutions = 4; 
    int solutionCount = 0;

    cout << "One solution:\n";
    if (!nQueen(arr, 0, n, solutionCount, 1)) {
        cout << "No solution exists.\n";
        return 0;
    }

    char choice;
    cout << "Do you want to print more solutions? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        maxSolutions += 4; 
        while (nQueen(arr, 0, n, solutionCount, maxSolutions)) {
            cout << "Do you want to print more solutions? (y/n): ";
            cin >> choice;
            if (choice != 'y' && choice != 'Y')
                break;
            maxSolutions += 4; 
        }
    }

    return 0;
}
