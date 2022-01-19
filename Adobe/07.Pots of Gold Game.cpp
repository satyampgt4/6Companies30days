#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    int dp[n][n];
	    for(int i =0; i<n; i++)
	    {
	        for(int a =0, b=a+i; b<n; a++,b++)
	        {
	            if(!i)
	            {
	                dp[a][b] = A[a];
	            }
	            else if (i==1)
	            {
	                dp[a][b] = max(A[a],A[b]);
	            }
	            else
	            {
	                 dp[a][b] = max(A[a]+min(dp[a+1][b-1],dp[a+2][b]),A[b]+min(dp[a+1][b-1],dp[a][b-2])); 
	            }
	        }
	        
	    }
	    return dp[0][n-1];
    }
};