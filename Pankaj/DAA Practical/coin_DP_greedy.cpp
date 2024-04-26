/*
C++ code that implements both Greedy and Dynamic Programming approaches to solve the coin changing problem using a switch case:
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find minimum number of coins needed using Greedy approach
vector<int> findMinCoinsGreedy(int amount, const vector<int>& coins) {
    vector<int> minCoins(coins.size(), 0);

    for (int i = coins.size() - 1; i >= 0; i--) {
        minCoins[i] = amount / coins[i];
        amount %= coins[i];
    }

    return minCoins;
}

// Function to find minimum number of coins needed using Dynamic Programming
vector<int> findMinCoinsDynamic(int amount, const vector<int>& coins) {
    vector<int> minCoins(amount + 1, INT_MAX);
    vector<int> usedCoins(amount + 1, -1);

    minCoins[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i && minCoins[i - coins[j]] + 1 < minCoins[i]) {
                minCoins[i] = minCoins[i - coins[j]] + 1;
                usedCoins[i] = j;
            }
        }
    }

    vector<int> result;
    int value = amount;
    while (value > 0) {
        result.push_back(coins[usedCoins[value]]);
        value -= coins[usedCoins[value]];
    }

    return result;
}

int main() {
    int choice;
    cout << "Choose an approach:\n";
    cout << "1. Greedy\n";
    cout << "2. Dynamic Programming\n";
    cin >> choice;

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int numCoins;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    vector<int> coins(numCoins);
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < numCoins; i++) {
        cout << "Coin " << i+1 << ": ";
        cin >> coins[i];
    }

    vector<int> result;
    switch (choice) {
        case 1:
            result = findMinCoinsGreedy(amount, coins);
            break;
        case 2:
            result = findMinCoinsDynamic(amount, coins);
            break;
        default:
            cout << "Invalid choice\n";
            return 1;
    }

    cout << "Minimum coins needed:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
Choose an approach:
1. Greedy
2. Dynamic Programming
2
Enter the amount: 47
Enter the number of coin denominations: 4
Enter the coin denominations:
Coin 1: 1
Coin 2: 5
Coin 3: 10
Coin 4: 25
Minimum coins needed:
1 1 10 10 25 



Greedy Approach:

Worst-case time complexity: O(n), where n is the number of coin denominations. This occurs when the largest denomination does not divide the amount evenly.
Average-case time complexity: O(n), same as worst-case because the algorithm iterates through all coin denominations once.
Best-case time complexity: O(n), same as worst-case because the algorithm iterates through all coin denominations once.
Dynamic Programming Approach:

Worst-case time complexity: O(n * m), where n is the amount and m is the number of coin denominations. This occurs when the amount is large and there are many different coin denominations.
Average-case time complexity: O(n * m), same as worst-case because the algorithm iterates through all possible combinations of amounts and coin denominations.
Best-case time complexity: O(n), when the amount is small relative to the number of coin denominations, resulting in fewer iterations to find the optimal solution.
*/