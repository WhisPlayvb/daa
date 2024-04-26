#include <iostream>
#include <climits> // for INT_MAX
#include <ctime> // for time
using namespace std;

int minCoins(int coins[], int n, int amount) {
    // Create an array to store the minimum number of coins required for each amount
    int minCoins[amount + 1];
    
    // Initialize minCoins array with a large value initially
    for (int i = 0; i <= amount; ++i) {
        minCoins[i] = INT_MAX;
    }
    
    // Base case: No coins needed to make up amount 0
    minCoins[0] = 0;
    
    // Compute minimum coins required for all amounts from 1 to amount
    for (int i = 1; i <= amount; ++i) {
        // Try all denominations
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && minCoins[i - coins[j]] != INT_MAX) {
                minCoins[i] = min(minCoins[i], minCoins[i - coins[j]] + 1);
            }
        }
    }
    
    // Return the minimum coins required for the given amount
    return minCoins[amount];
}

int main() {
    int numCoins;
    cout << "Enter the number of coins: ";
    cin >> numCoins;
    
    int coins[numCoins];
    
    cout << "Enter the coins: ";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }
    
    int amount;
    cout << "Enter the amount to make up: ";
    cin >> amount;
    
    int result = minCoins(coins, numCoins, amount);
    
    cout << "Minimum number of coins required: " << result << endl;
    
    return 0;
}
/*
Enter the number of coins: 4
Enter the coins: 1
5
6
9
Enter the amount to make up: 10
Minimum number of coins required: 2
*/

/*
The time complexity of the provided algorithm can be expressed as follows:
Let:
n be the number of coin denominations.
A be the value of the amount to make up.
The algorithm involves nested loops where each loop iterates over all coin denominations (n) and each iteration performs a constant amount of work. 
Therefore, the time complexity of the algorithm is
O(n·A)
*/

