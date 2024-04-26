#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

bool binarySearchX(vector<int> &arr, int size, int value)
{
    bool isFound = false;

    auto start = high_resolution_clock::now();

    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        // int mid = rand()%size;
        int mid = left + rand() % (right - left + 1);

        if (arr[mid] == value)
        {
            isFound = true;
            break;
        }
        else if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration_time = duration_cast<duration<double>>(stop - start) * 1000; // Convert to milliseconds
    cout << fixed << setprecision(4) << "\nTime taken by the binary search is = " << duration_time.count() << " milliseconds";

    return isFound;
}

int main()
{

    int size = 0;
    int element = 0;
    bool isFound = false;

    cout << "\nEnter the size of array = ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        int random = rand();
        arr[i] = random;
    }

    element = rand() % size;
    cout << "\nElement to search is = " << arr[element] << endl;
    int search = arr[element];

    sort(arr.begin(), arr.end());
    bool isBinaryFound = binarySearchX(arr, size, search);
    cout << endl;
    if (isBinaryFound)
        cout << search << " is present" << endl;
    else
        cout << search << " is not present" << endl;
}
