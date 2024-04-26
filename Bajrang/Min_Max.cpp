#include<iostream>

using namespace std;

void findmaxmin(int arr[], int start, int end, int& max, int& min) {
    if (start == end) {
        max = arr[start];
        min = arr[start];
        return;
    }

    if (end == start + 1) {
        if (arr[start] > arr[end]) {
            max = arr[start];
            min = arr[end];
        }
        else {
            max = arr[end];
            min = arr[start];
        }
        return;
    }

    int mid = (start + end) / 2;

    int leftmin, leftmax, rightmin, rightmax;

    findmaxmin(arr, start, mid, leftmax, leftmin);
    findmaxmin(arr, mid + 1, end, rightmax, rightmin);

    if (leftmax > rightmax) {
        max = leftmax;
    }
    else {
        max = rightmax;
    }

    if (leftmin < rightmin) {
        min = leftmin;
    }
    else {
        min = rightmin;
    }
}

int main() {
  int n ;
  
  cout<<"Enter size of the array : ";
  cin>>n;
  int arr[n];
  int max, min;
  
  cout<<"Enter array elements : "<<endl;
  for(int i =0 ; i<n ; i++)
  {
  	cin>>arr[i];
  }

    cout << "Elements of the array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    findmaxmin(arr, 0, n - 1, max, min);

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;

    return 0;
}
