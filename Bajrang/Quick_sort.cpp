#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(vector<int>& arr, int low, int high, int pivot) {
    while (low <= high) {
        while (arr[low] < pivot) low++;
        while (arr[high] > pivot) high--;

        if (low <= high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

int findMedianOfMedians(vector<int>& arr, int start, int end) {
    int n = end - start + 1;
    int numMedians = (n + 4) / 5;  // Number of groups of 5 elements
    vector<int> medians(numMedians);

    for (int i = 0; i < numMedians; i++) {
        int medianStart = start + i * 5;
        int medianEnd = min(start + i * 5 + 4, end);
        sort(arr.begin() + medianStart, arr.begin() + medianEnd + 1);
        medians[i] = arr[(medianStart + medianEnd) / 2];
    }

    while (numMedians > 1) {
        int newNumMedians = (numMedians + 4) / 5;
        vector<int> newMedians(newNumMedians);

        for (int i = 0; i < newNumMedians; i++) {
            int medianStart = i * 5;
            int medianEnd = min(i * 5 + 4, numMedians - 1);
            sort(medians.begin() + medianStart, medians.begin() + medianEnd + 1);
            newMedians[i] = medians[(medianStart + medianEnd) / 2];
        }

        medians = newMedians;
        numMedians = newNumMedians;
    }

    return medians[0];
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = findMedianOfMedians(arr, low, high);
        int pivotIndex = partition(arr, low, high, pivot);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex, high);
    }
}

int main() {
    srand(time(0));
    int n;
    cout<<"Enter size: ";
    cin>>n;
    vector<int> arr(n);
      for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random elements (0 to 999)
    }

    sort(arr.begin(), arr.end());
    
    clock_t startTime = clock();

    quickSort(arr, 0, n - 1);

    clock_t endTime = clock();
    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;


    cout << "Time taken for quickSort: " << elapsedTime << " seconds" << endl;

    return 0;
}

