#include<iostream>
#include<vector>
using namespace std;

void MIN_MAX(vector<int>arr,int n,int start,int end,int &min,int &max)
{
    if(start == end)
    {
        min = max= arr[start];
    }
    else if(start == end-1)
    {
        if((arr[start])< arr[end])
        {
            min = arr[start];
            max = arr[end];
        }
        else
        {
            min = arr[end];
            max = arr[start];
        
        }
    }
    else
    {
        int mid = (start+end)/2;
        int minnew,maxnew;
        MIN_MAX(arr,n,start,mid,min,max);
        MIN_MAX(arr,n,mid+1,end,minnew,maxnew);

        if(max < maxnew)
        {
            max = maxnew;
        }

        if (min > minnew)
        {
            min = minnew;
        } 

    }
}

int main()
{
    int n =10;
    vector<int>arr ={10,40,32,7,18,45,99,8,23,5};

    int min=0;
    int max=0;

    MIN_MAX(arr,n,0,n-1,min,max);

    cout<<"Minimum element is : "<<min<<endl;
    cout<<"Maximum element is : "<<max<<endl;
     

}