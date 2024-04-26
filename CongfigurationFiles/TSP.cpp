#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to solve TSP using dynamic programming
pair<double, int*> solveTSP(int n, double** dist) {
    double** dp = new double*[1 << n];
    int** path = new int*[1 << n];
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = new double[n];
        path[i] = new int[n];
    }

    for (int i = 0; i < (1 << n); ++i) {
        fill(dp[i], dp[i] + n, INF);
        fill(path[i], path[i] + n, -1);
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j)) {
                        if (dp[mask ^ (1 << i)][j] + dist[j][i] < dp[mask][i]) {
                            dp[mask][i] = dp[mask ^ (1 << i)][j] + dist[j][i];
                            path[mask][i] = j;
                        }
                    }
                }
            }
        }
    }

    int last = 0;
    double minDist = INF;
    for (int i = 1; i < n; ++i) {
        if (dp[(1 << n) - 1][i] + dist[i][0] < minDist) {
            minDist = dp[(1 << n) - 1][i] + dist[i][0];
            last = i;
        }
    }

    int* tour = new int[n];
    int mask = (1 << n) - 1;
    tour[0] = last;
    int idx = 1;
    while (path[mask][last] != -1) {
        int prev = path[mask][last];
        tour[idx++] = prev;
        mask ^= (1 << last);
        last = prev;
    }

    for (int i = 0; i < (1 << n); ++i) {
        delete[] dp[i];
        delete[] path[i];
    }
    delete[] dp;
    delete[] path;

    return make_pair(minDist, tour);
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // Input the distance matrix
    double** dist = new double*[n];
    cout << "Enter the distance matrix (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; ++i) {
        dist[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    pair<double, int*> result = solveTSP(n, dist);

    cout << "Minimum distance for the TSP: " << result.first << endl;
    cout << "Path: ";
    for (int i = 0; i < n; ++i) {
        cout << result.second[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete[] dist[i];
    }
    delete[] dist;
    delete[] result.second;

    return 0;
}

