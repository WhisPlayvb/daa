#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight; // Weight of the item
    int value;  // Value of the item
};

// Function to solve 0/1 knapsack problem
int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    // Create a 2D DP table to store the maximum value that can be achieved up to a certain capacity
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Iterate over each item
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the current item's weight is less than or equal to the current capacity, 
            // we have two choices:
            // 1. Include the item and add its value to the value that can be achieved with the remaining capacity
            // 2. Exclude the item and take the value that can be achieved without it
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                // If the current item's weight exceeds the current capacity, we can't include it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in the bottom-right cell of the table
    return dp[n][capacity];
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n); // Vector to store items
    cout << "Enter item details (weight, value):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity; // Capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Solve 0/1 knapsack problem
    int maxValue = knapsack(capacity, items);

    // Output the maximum value that can be achieved
    cout << "Maximum value that can be achieved: " << maxValue << endl;

    return 0;
}
