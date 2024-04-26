#include <iostream>
#include <algorithm>

using namespace std;

// Function to find the minimum number of coins required to make the change amount
void coinChange(int coins[], int n, int amount) {
    // Sort coins in descending order
    sort(coins, coins + n, greater<int>());

    int coinCount = 0; // Initialize the count of coins used

    // Iterate through the coins to find the minimum number of coins required
    for (int i = 0; i < n; i++) {
        // While the current coin value is less than or equal to the remaining amount,
        // use as many coins of that denomination as possible
        while (amount >= coins[i]) {
            cout << coins[i] << " ";
            amount -= coins[i];
            coinCount++; // Increment the coin count
        }
    }

    cout << "\nMinimum number of coins required: " << coinCount << endl;
}

int main() {
    int n; // Number of coins
    cout << "Enter the number of coins: ";
    cin >> n;

    int coins[n]; // Array to store coin denominations
    cout << "Enter the denominations of each coin:\n";
    for (int i = 0; i < n; i++) {
        cout << "Coin " << i + 1 << ": ";
        cin >> coins[i];
    }

    int amount; // Amount of change to make
    cout << "Enter the amount of change to make: ";
    cin >> amount;

    // Find the minimum number of coins required to make the change
    coinChange(coins, n, amount);

    return 0;
}

/*
OUTPUT
Enter the number of coins: 4
Enter the denominations of each coin:
Coin 1: 25
Coin 2: 20
Coin 3: 20
Coin 4: 5
Enter the amount of change to make: 50
25 25
Minimum number of coins required: 2
*/

/*
TIME COMPLEXITY
O(nlogn), where n is the number of coin denominations.
*/

