#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum =0;
	    for(int i =0; i<n; i++)
	    {
	        sum+=arr[i];
	    }
	    int temp = sum/2;
	    
	    bool dp[n+1][temp+1];
	    for(int i =0; i<=n; i++)
	    {
	        for(int j =0; j<=temp; j++)
	        {
	            if(!j)
	                dp[i][j] =1;
	            else if(!i)
	                dp[i][j] =0;
	            else if(arr[i-1]>j)
	                dp[i][j] =dp[i-1][j];
	            else 
	                dp[i][j] =dp[i-1][j]| dp[i-1][j-arr[i-1]];
	        }
	    }
	    int ans = INT_MAX;
	    for(int i =0; i<=temp; i++)
	    {
	        if(dp[n][i])
	        {
	           // cout<<sum-i<<" ";
	            ans  = min(ans,abs(sum-(2*i)));
	        }
	    }
	    return ans;
	} 
	
};

