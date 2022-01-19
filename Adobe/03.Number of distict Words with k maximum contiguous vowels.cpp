#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
       int M=1000000007;
       long dp[N+1][K+1];
       for(int i=0; i<=N;i++)
       {
           for(int j =0; j<=K; j++)
           {
               if(!i)
               {
                   dp[i][j] = 1;
               }
               else if (!j)
               {
                   dp[i][j] = (dp[i-1][K]*21)%M;
               }
               else
               {
                   dp[i][j] = ((dp[i-1][K]*21)%M +(dp[i-1][j-1]*5)%M)%M;
               }
           }
       }
       return dp[N][K]%M;
    }
};