#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Item {
    int value;   
    int weight;  
    double ratio; 
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Add the entire item
            totalValue += items[i].value;
            currentWeight += items[i].weight;
            cout << "Item " << i + 1 << " (Value: " << items[i].value << ", Weight: " << items[i].weight << ", Ratio: " << items[i].ratio << ") taken completely. Weight taken: " << items[i].weight << endl;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;
            cout << "Item " << i + 1 << " (Value: " << items[i].value << ", Weight: " << items[i].weight << ", Ratio: " << items[i].ratio << ") taken partially with ratio " << items[i].ratio << ". Weight taken: " << remainingWeight << endl;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n; 
    cout << "Enter number of items: ";
    cin >> n;

    int capacity; 
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "\nRatios for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (Value: " << items[i].value << ", Weight: " << items[i].weight << ") Ratio: " << items[i].ratio << endl;
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "\nMaximum value that can be obtained: " << maxValue << endl;

    return 0;
}

