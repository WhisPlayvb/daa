#include <bits/stdc++.h>
using namespace std;
#include<chrono>

int partition1(int l, int r, vector<int> &arr)
{
    int pivot_element = arr[l];
    int left = l;
    int right = r - 1; 

    while (left <= right) {
        while (left <= right && arr[left] < pivot_element) {
            left++;
        }
        while (left <= right && arr[right] >= pivot_element) {
            right--;
        }

        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    
    swap(arr[left], arr[r]);

    return left;
}


void quicksort1(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;
    int pivot_index = partition1(l, r, v);
    quicksort1(v, l, pivot_index - 1);
    quicksort1(v, pivot_index + 1, r);
}

 

int findMedian(vector<int> &arr, int start, int end)
{
    if (end - start <= 5)
    {
        sort(arr.begin() + start, arr.begin() + end);
        return arr[(start + end) / 2];
    }
    vector<int> medians;
    for (int i = start; i <= end; i += 5)
    {
        int subEnd = min(i + 4, end);
        sort(arr.begin() + i, arr.begin() + subEnd);
        medians.push_back(arr[(i + subEnd) / 2]);
    }
    int medianOfMedians = findMedian(medians, 0, medians.size() - 1);
    return medianOfMedians;
}


int partition2(vector<int> &arr, int start, int end, int pivot)
{
    int pivotIdx = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == pivot)
        {
            pivotIdx = i;
            break;
        }
    }
    swap(arr[pivotIdx], arr[end]);
    pivotIdx = end; 
    int i = start - 1;
    for (int j = start; j < pivotIdx; j++)
    {
        if (arr[j] < arr[pivotIdx])
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivotIdx]);
    return i + 1;
}


void quicksort2(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivot = findMedian(arr, start, end);
        int partitionIdx = partition2(arr, start, end, pivot);
        quicksort2(arr, start, partitionIdx - 1);
        quicksort2(arr, partitionIdx + 1, end);
    }
}


int main()
{
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int val = rand() % (n);
        v[i] = val;
    }

    cout << "Before Sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    auto start1 = std::chrono::steady_clock::now();
    quicksort1(v, 0, v.size() - 1);
    cout << "After Sorting : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    auto fin1 = std::chrono::steady_clock::now();
    double time1 = std::chrono::duration_cast<std::chrono::duration<double>>(fin1 - start1).count();

    auto start2 = std::chrono::steady_clock::now();

    quicksort2(v, 0, v.size() - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;

    auto fin2 = std::chrono::steady_clock::now();
    double time2 = std::chrono::duration_cast<std::chrono::duration<double>>(fin2 - start2).count();
    cout << "\nTime Taken By Quick Sort = " << fixed << time1 << setprecision(10) << endl;
    cout << "\nTime Taken By Median of Median = " << fixed << time2 << setprecision(10) << endl;
}
