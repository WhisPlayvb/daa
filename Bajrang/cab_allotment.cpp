#include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
 int findCab(int arr[], int dep[], int n)
    {
    
    	sort(arr , arr+n);
    	sort(dep , dep+n);
    	
    	int i= 0 , j = 0;
    	
    	int count = 0;
    	int ans = 0;
    	
    	
    	while(i<n && j<n)
    	{
    	    if(arr[i]<= dep[j])
    	    {
    	        count++;
    	        i++;
    	        ans = max(ans , count);
    	    }
    	    else 
    	    {
    	        j++;
    	        count--;
    	    }
    	}
    	
    	return ans;
    }
     
int main()
{
   
        int n;
        cout<<"Enter No of Person : ";
        cin>>n;
        cout<<endl;
        int arr[n];
        int dep[n];
        cout<<"Enter Arrival Time of cab for a person : "<<endl;
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        cout<<"Enter time when cab dropping a person : "<<endl;
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        cout<<"Minimum Number of Cab Required are ..";
        cout <<findCab(arr, dep, n)<<endl;

   return 0;
}
