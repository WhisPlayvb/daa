#include <iostream>
using namespace std;
// Function to find the maximum and minimum elements in an array using divide and conquer
void findMaxMin(int arr[], int low, int high, int& maxElement, int& minElement) {
    if (low == high) { // Base case: Only one element in the array
        maxElement = arr[low];
        minElement = arr[low];
        return;
    }

    if (high - low == 1) { // Base case: Two elements in the array
        maxElement = std::max(arr[low], arr[high]);
        minElement = std::min(arr[low], arr[high]);
        return;
    }

    // Divide the array into two halves and recursively find max and min in each half
    int mid = (low + high) / 2;
    int leftMax, leftMin, rightMax, rightMin;
    findMaxMin(arr, low, mid, leftMax, leftMin); // Find max and min in the left half
    findMaxMin(arr, mid + 1, high, rightMax, rightMin); // Find max and min in the right half

    // Combine the results from the left and right halves
    maxElement = max(leftMax, rightMax);
    minElement = min(leftMin, rightMin);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int maxElement, minElement;
    findMaxMin(arr, 0, n - 1, maxElement, minElement);
    
    cout << "Maximum element in the array: " << maxElement << endl;
    cout << "Minimum element in the array: " << minElement << endl;

    return 0;
}

//Time complexity = O(n) in all the cases
