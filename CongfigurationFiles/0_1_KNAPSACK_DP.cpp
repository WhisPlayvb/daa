#include <iostream>
#include <vector>

/* v[i,w] = max{v[i-1,w],v[i-1,w-w[i]+p[i] */

using namespace std;

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n, vector<int>& selectedItems) {
    int dp[n + 1][W + 1];

    // Initialize dp table with zeros
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtrack to find selected items
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i);
            w -= wt[i - 1];
        }
    }

    // Return the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n]; // Value and weight of each item
    cout << "Enter the profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    int W; // Maximum capacity of the knapsack
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    // Vector to store selected items for optimal solution
    vector<int> selectedItems;

    // Solve the 0/1 Knapsack problem and get the total profit
    int totalProfit = knapsack(W, wt, val, n, selectedItems);

    // Print the total profit
    cout << "The total profit: " << totalProfit << endl;

    // Print the selected items for the optimal solution
    cout << "Selected items for optimal solution: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
OUTPUT-1
Enter the number of items: 4
Enter the profit and weight of each item:
Enter profit and weight for item 1: 1 2
Enter profit and weight for item 2: 2 3
Enter profit and weight for item 3: 5 4
Enter profit and weight for item 4: 6 5
Enter the maximum capacity of the knapsack: 8
The total profit: 8
Selected items for optimal solution: 2 4

*/


/*
Time Compexity:
O(N*M), where N is the number of items and W is the maximum capacity of the knapsack.
*/
