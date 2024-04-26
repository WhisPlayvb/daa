#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(int A, vector<int>& coins) {
    vector<int> dp(A + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= A; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
    }

    return dp[A];
}

int main() {
    int C = 4;
    vector<int> coins = {2, 3, 5, 6};
    int A = 21;
    cout << "Minimum number of coins required: " << minCoins(A, coins) << endl;
    return 0;
}
