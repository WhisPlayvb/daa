#include <bits/stdc++.h>
#include <algorithm>
//#include <chrono>
using namespace std;

int coins[] = {1,5,6,9}; 
int dp[1000] = {0};
int selected[1000] = {-1};
int minCoins(int N, int M)
{
  
  for(int i = 0;i<=N;i++)
  {
    dp[i] = INT_MAX;
    selected[i] = -1;
  }
  
  dp[0] = 0;
  
  for(int i = 1;i<=N;i++)
  {
    for(int j = 0;j<M;j++)
    {
      if(coins[j] <= i && 1 + dp[i - coins[j]] < dp[i])
      {
        dp[i] = 1 + dp[i - coins[j]];
        selected[i] = j;
      }
    }
  }
  
  cout<<"Coins used: ";
  int i = N;
  while(i > 0)
  {
    int j = selected[i];
    cout<<coins[j]<<" ";
    i -= coins[j];
  }
  cout<<endl;
  
  return dp[N];
}

int main() {
  int sum = 11;
  int total_coins = 4;

//  auto start = chrono::steady_clock::now();
  int nCoins = minCoins(sum, total_coins);
//  auto end = chrono::steady_clock::now();
  
  cout<<"Minimum coins required: "<<nCoins;
  
//  cout << "\nElapsed time in microseconds: " << 
//    chrono::duration_cast<chrono::microseconds>(end - start).count()<<"ms"<< endl;
  cout << endl;

  return 0;
}
