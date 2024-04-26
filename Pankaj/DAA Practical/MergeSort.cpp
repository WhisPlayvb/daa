#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


void Merge(int* arr,int s,int e)
{
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}


void mergeSort(int *arr,int s,int e)
{
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

     
    mergeSort(arr, s, mid);
    
    
    mergeSort(arr, mid+1, e);

    
    Merge(arr, s, e);
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
    for(int i=0;i<size;i++)
	{
		cout<<" "<<arr[i];
	}

    cout<<"\n ################################################################"<<endl;
    cout<<"\n";
    auto startLinear = high_resolution_clock::now();
    mergeSort(arr,0,size-1);
    auto endLinear = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(endLinear - startLinear);
    cout << "Merge Sort Time: " << duration.count() << " nanoseconds" << endl;

    cout<<"Sorted Array:"<<endl;

    for(int i=0;i<size;i++)
	{
		cout<<" "<<arr[i];
	}

}