#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double knapsackGreedy(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            double remainingCapacity = capacity - currentWeight;
            totalValue += (double)items[i].value * (remainingCapacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items;
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;
    
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < numItems; ++i) {
        Item newItem;
        cout << "Item " << i + 1 << ": ";
        cin >> newItem.value >> newItem.weight;
        items.push_back(newItem);
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = knapsackGreedy(items, capacity);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
