//coin changing using greedy and dynamic programming approach
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, tt_coins=0, coins=0, rem=0;
	cout<<"---------THE GREEDY APPROACH-----------"<<endl;
	cout<<"Enter the no. of denominations available : ";
	cin>>n;
	int d[n];
	cout<<"\n Enter the denominations : "<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>d[i];
	}
	sort(d, d + n, greater<int>());
	cout<<"\nEnter the amount : ";
	cin>>a;
	while(a!=0)
	{
		for(int i=0; i<n; i++)
		{
			coins = a/d[i];
			tt_coins = tt_coins + coins;
			rem = a%d[i];
			if(rem<a)
			{
				a=rem;
			}
			if(rem==0)
			{
				a=0;
			}
			cout<<"\n\nNo. of coins required of denomination "<<d[i]<<" are : "<<coins<<endl;
		}
		cout<<"\n\nTotal no. of coins required : "<<tt_coins<<endl;
		
		
	}
	return 0;
}
