//DP:Memoization technique instead of recursion.
//Memoization:Top Down
//Fibonacci series using DP(memoization)
//TC:O(N)
//SC:O(N)+O(N)

#include<iostream>
using namespace std;

int f(int n, vector<int> &dp){
  if(n<=1){
    return n;
  }

  if(dp[n]!=-1) return dp[n];
  return dp[n]=f(n-1,dp)+f(n-2,dp);
}

int main(){
  int n;
  cin>>n;
  vector<iny> dp(n+1, -1);
  cout<<f(n,dp);
  return 0;
}
