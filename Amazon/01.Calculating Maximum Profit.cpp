#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxProfit(int K, int N, int a[]) {
        
     int dp[K+1][N];
     for(int i =0; i<=K; i++)
     {
         int temp = INT_MIN;
         for(int j =0; j<N; j++)
         {
             if(!i || !j)
             {
                 dp[i][j] =0;
             }
             else
             {
                 if(dp[i-1][j-1]- a[j-1]>temp)
                 {
                     temp = dp[i-1][j-1]- a[j-1];
                 }
                 dp[i][j] = max(dp[i][j-1], temp+a[j]);
             }
         }
     }
     return dp[K][N-1];
    }
};