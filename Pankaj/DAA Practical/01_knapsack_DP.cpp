#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    vector<vector<bool>> selected(n + 1, vector<bool>(W + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] <= j) {
       
                if (values[i - 1] + dp[i - 1][j - weights[i - 1]] > dp[i - 1][j]) {
                    dp[i][j] = values[i - 1] + dp[i - 1][j - weights[i - 1]];
                    selected[i][j] = true;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    
    int i = n;
    int j = W;
    while (i > 0 && j > 0) {
        if (selected[i][j]) {
            cout << "Item " << i << " (Weight: " << weights[i - 1] << ", Value: " << values[i - 1] << ")" << endl;
            j -= weights[i - 1];
        }
        i--;
    }

    return dp[n][W];
}

int main() {
    int n; 
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n); 
    vector<int> values(n);  

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int W;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    int max_value = knapsack(W, weights, values, n);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
