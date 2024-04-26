#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm> // Include algorithm header for sort function

using namespace std;

// Swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Median of Medians algorithm to find median of the list
int medianOfMedians(vector<int>& arr, int left, int right) {
    int n = right - left + 1;
    int numGroups = (n + 4) / 5; // Number of groups of size 5

    // Calculate median of each group and store in median vector
    vector<int> median(numGroups, 0);
    for (int i = 0; i < numGroups; i++) {
        int groupLeft = left + i * 5;
        int groupRight = min(left + i * 5 + 4, right);
        sort(arr.begin() + groupLeft, arr.begin() + groupRight + 1); // Using sort function
        median[i] = arr[groupLeft + (groupRight - groupLeft) / 2];
    }

    // Recursively find median of medians
    if (numGroups == 1)
        return median[0];
    else
        return medianOfMedians(median, 0, numGroups - 1);
}

// Quick Sort algorithm
void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find pivot using median of medians
        int pivot = medianOfMedians(arr, left, right);
        
        // Partitioning
        int i = left - 1;
        int j = right + 1;
        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);
            if (i >= j)
                break;
            swap(arr[i], arr[j]);
        }
        
        // Recursively sort subarrays
        quickSort(arr, left, j);
        quickSort(arr, j + 1, right);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // Fill the array with user input
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    clock_t start = clock();
    quickSort(arr, 0, n - 1); // Sort the array using Quick Sort
    clock_t end = clock();

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << timeTaken << " seconds" << endl;

    return 0;
}
/*Enter the size of the array: 8
Enter 8 elements of the array: 45 7 32 8 12 43 78 12
Array before sorting: 45 7 32 8 12 43 78 12
Array after sorting: 7 8 12 12 32 43 45 78
O(nlogn) time comp
*/
