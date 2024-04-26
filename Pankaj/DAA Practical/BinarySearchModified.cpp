#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


int linearSearch(int arr[],int size,int key)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			return i;
		}
	}

	return -1;
}

int BinarySearchRecursive(int arr[],int key,int start,int end)
{
	if(start>end)
     {
        return -1;
     }
    
    int mid=(start+end)/2;     

    if(arr[mid] == key )
     {
        return mid ;
     }
     else if(arr[mid] > key)
     {
        BinarySearchRecursive(arr,key,start,mid-1);
     }
     else
     {
        BinarySearchRecursive(arr,key,mid+1,end);
     }
	
	
}

int BinarySearch(int arr[],int size,int key)
{
	int start=0;
	int end=size-1;
	
	
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]< key)
		{
			start=mid+1;
		}
		else if(arr[mid]>key)
		{
			end=mid-1;
		}
	}
	return -1;
}

int modifiedBinarySearch(int arr[], int x,int size) {
    int low = 0;
    int high = size-1;

    while (low <= high) {
        
        int pivotIndex = low + rand() % (high - low + 1);
        int mid = pivotIndex;

        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  
	
}

int main()
{
	int size=6;
	cout<<"Enter Size:";
	cin>>size;
	
	int arr[100000];
	for(int i=0;i<size;i++)
	{
        arr[i]=rand()%10000;
	}

	sort(arr, arr+size);
	
	for(int i=0;i<size;i++)
	{
		cout<<" "<<arr[i];
	}

	cout<<endl;
	int key=0;
	cout<<"Element to Search:";
	cin>>key;


	auto startLinear = high_resolution_clock::now();
    int resultLinear = linearSearch(arr, size, key);
    auto endLinear = high_resolution_clock::now();

    if (resultLinear == -1)
        cout << "Linear Search: Element not found" << endl;
    else
        cout << "Linear Search: Element found at index " << resultLinear << endl;


    auto durationLinear = duration_cast<nanoseconds>(endLinear - startLinear);
    cout << "Linear Search Time: " << durationLinear.count() << " nanoseconds" << endl;


    auto startIterative = high_resolution_clock::now();
    int resultBinary = BinarySearch(arr, size, key);
    auto endIterative = high_resolution_clock::now();

    if (resultBinary == -1)
        cout << "Iterative Binary Search: Element not found" << endl;
    else
        cout << "Iterative Binary Search: Element found at index " << resultBinary << endl;

    auto durationIterative = duration_cast<nanoseconds>(endIterative - startIterative);
    cout << "Iterative Binary Search Time: " << durationIterative.count() << " nanoseconds" << endl;

	auto startRecursive = high_resolution_clock::now();
    int resultRecursive = BinarySearchRecursive(arr,key, 0, size);
    auto endRecursive = high_resolution_clock::now();

	if (resultRecursive == -1)
        cout << "Recursive Binary Search: Element not found" << endl;
    else
        cout << "Recursive Binary Search: Element found at index " << resultRecursive << endl;

    auto durationRecursive = duration_cast<nanoseconds>(endRecursive - startRecursive);
    cout << "Recursive Binary Search Time: " << durationRecursive.count() << " nanoseconds" << endl;


	auto startModified = high_resolution_clock::now();
    int resultModified = modifiedBinarySearch(arr,key,size);
    auto endModified = high_resolution_clock::now();

	if (resultModified == -1)
        cout << "Modified Binary Search: Element not found" << endl;
    else
        cout << "Modified Binary Search: Element found at index " << resultModified << endl;

	auto durationModified = duration_cast<nanoseconds>(endModified - startModified);
    cout << "Modified Binary Search Time: " << durationModified.count() << " nanoseconds" << endl;


    

    return 0;
	
}