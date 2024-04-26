#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
  int weight;
  int profit;
  double ratio; // Value per unit weight
  int originalIndex; // Original index of the item (for printing)
};

// Function to compare items based on their value per unit weight (ratio)
bool compare(Item a, Item b) {
  return a.ratio > b.ratio;
}

// Function to solve Fractional Knapsack problem using greedy approach
double fractionalKnapsack(int W, Item items[], int n, vector<double>& selectedWeights) {
  // Calculate value per unit weight for each item
  for (int i = 0; i < n; i++) {
    items[i].ratio = (double)items[i].profit / items[i].weight;
  }

  // Sort items based on value per unit weight in non-increasing order
  sort(items, items + n, compare);

  double totalProfit = 0.0; // Total profit obtained
  int currentWeight = 0;   // Current weight in knapsack

  // Use a vector to store selected item weights (fractional or whole)
  selectedWeights.resize(n, 0.0); // Initialize with zeros

  // Iterate through sorted items and add them to the knapsack
  for (int i = 0; i < n; i++) {
    // If adding the entire item doesn't exceed the knapsack capacity
    if (currentWeight + items[i].weight <= W) {
      selectedWeights[i] = items[i].weight; // Select the entire item
      totalProfit += items[i].profit;
      currentWeight += items[i].weight;
    } else {
      // Add a fraction of the item to fill the knapsack
      int remainingWeight = W - currentWeight;
      selectedWeights[i] = remainingWeight; // Select fraction of the item
      totalProfit += items[i].ratio * remainingWeight;
      break; // Knapsack is full
    }
  }

  return totalProfit;
}

int main() {
  int n; // Number of items
  cout << "Enter the number of items: ";
  cin >> n;

  Item items[n]; // Array to store items
  cout << "Enter the profit and weight of each item:\n";
  for (int i = 0; i < n; i++) {
    cout << "Enter profit and weight for item " << i + 1 << ": ";
    cin >> items[i].profit >> items[i].weight;
    // Store original index for printing later
    items[i].originalIndex = i + 1;
  }

  int W; // Maximum capacity of the knapsack
  cout << "Enter the maximum capacity of the knapsack: ";
  cin >> W;

  // Vector to store selected item weights (fractional or whole)
  vector<double> selectedWeights(n);

  // Solve the Fractional Knapsack problem
  double totalProfit = fractionalKnapsack(W, items, n, selectedWeights);

  // Print the total profit
  cout << "The total profit that can be obtained: " << totalProfit << endl;

  // Print the selected items for the optimal solution (using original indices)
  cout << "Selected items for optimal solution (original indices): ";
  for (int i = 0; i < n; i++) {
    if (selectedWeights[i] > 0) {
      cout << items[i].originalIndex << " "; // Print original index
    }
  }
  cout << endl;

  return 0;
}
/*Enter the number of items: 5
Enter the profit and weight of each item:
Enter profit and weight for item 1: 30 5
Enter profit and weight for item 2: 40 10
Enter profit and weight for item 3: 45 15
Enter profit and weight for item 4: 77 22
Enter profit and weight for item 5: 90 25
Enter the maximum capacity of the knapsack: 60
The total profit that can be obtained: 230
Selected items for optimal solution (original indices): 1 2 5 4*/
