#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int l, int h)
{
    int pivot = arr[l];
    int i = l + 1;  // Start from the next element
    int j = h;

    while (i <= j)
    {
        while (i <= j && arr[i] < pivot)
        {
            i++;
        }
        
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(arr[j], arr[l]);
    return j;
}

void QuickSort(vector<int>& arr, int l, int h)
{
    if (l < h)
    {
        int P = partition(arr, l, h);
        QuickSort(arr, l, P - 1);
        QuickSort(arr, P + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;  // Random elements (0 to 999)
    }
    sort(arr.begin(),arr.end());

    auto start = high_resolution_clock::now();
    QuickSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    cout << "\nTime taken for QuickSort: " << duration.count() << " microseconds" << endl;

    return 0;
}
