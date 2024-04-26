#include <iostream>

using namespace std;

// Function to find the total number of ways to make a given amount
int totalWays(int coins[], int n, int amount) {
    // Create a table to store the total number of ways to make each amount from 0 to amount
    int dp[amount + 1];

    // Initialize the table with 0
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }

    // Base case: 1 way to make amount 0 (by choosing no coins)
    dp[0] = 1;

    // Iterate over each coin denomination
    for (int i = 0; i < n; i++) {
        // For each coin denomination, update the table values
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main() {
    int n; // Number of coin denominations
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    int coins[n]; // Array to store the coin denominations
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < n; i++) {
        cout << "Coin " << i + 1 << ": ";
        cin >> coins[i];
    }

    int amount; // Amount to make
    cout << "Enter the amount to make: ";
    cin >> amount;

    // Find the total number of ways to make the amount
    int totalPossibilities = totalWays(coins, n, amount);

    // Print the result
    cout << "Total number of possibilities: " << totalPossibilities << endl;

    return 0;
}

/*
OUTPUT:
Enter the number of coin denominations: 4
Enter the coin denominations:
Coin 1: 2
Coin 2: 3
Coin 3: 5
Coin 4: 10
Enter the amount to make: 15
Total number of possibilities: 9

The overall time complexity of the coin changing problem using dynamic programming is O(n * amount).
*/

