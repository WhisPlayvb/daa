
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 1000000;

struct TourResult {
    int cost;
    vector<int> order;
};

TourResult fun(int i, int mask, int n, const vector<vector<int>>& dist) {
    // Base case: If only ith bit and 1st bit is set in our mask,
    // it implies we have visited all other nodes already
    if (mask == ((1 << i) | 1)) {
        return {dist[0][i], vector<int>{i}};
    }
    TourResult best = {MAX, {}};
    // For every node j in mask, recursively calculate the cost of
    // traveling all nodes in mask except i and then return from j
    // taking the shortest route to 1
    for (int j = 1; j < n; j++) {
        if ((mask & (1 << j)) && j != i) {
            TourResult subResult = fun(j, mask & (~(1 << i)), n, dist);
            int cost = subResult.cost + dist[j][i];
            if (cost < best.cost) {
                best.cost = cost;
                best.order = subResult.order;
                best.order.push_back(i);
            }
        }
    }
    return best;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // Dynamic allocation of memory for the adjacency matrix
    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the adjacency matrix:" << endl;
    // Taking input for the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Finding the most efficient tour and the order of cities visited
    TourResult result = {MAX, {}};
    for (int i = 1; i < n; i++) {
        TourResult subResult = fun(i, (1 << n) - 1, n, dist);
        int cost = subResult.cost + dist[i][0];
        if (cost < result.cost) {
            result.cost = cost;
            result.order = subResult.order;
            result.order.push_back(0);
        }
    }

    // Printing the result
    cout << "The cost of the most efficient tour = " << result.cost << endl;
    cout << "Order of cities visited: ";
    cout<<1;
    for (int city : result.order) {
        cout << "->"<< city + 1 ; // Adjusting index to start from 1
    }
    cout << endl;

    return 0;
}

/*
Enter the number of cities: 4
Enter the adjacency matrix:
0 10 15 20
10  0 25 25
15 25  0 30
20 25 30  0
The cost of the most efficient tour = 80
Order of cities visited: 1->3->4->2->1


Enter the number of cities: 4
Enter the cost matrix:
0 22 26 30
30 0 45 35
25 45   0 60
30 35 40 0
Minimum cost to visit all cities: 122



Best Time Complexity: O(n^2 * 2^n)
Average Time Complexity: O(n^2 * 2^n)
Worst Time Complexity: O(n^2 * 2^n)
*/