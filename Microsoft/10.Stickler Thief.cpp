#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n==1)
            return arr[0];
        
        int dp[n];
        dp[0] = arr[0];
        dp[1] = arr[1];
        int ans = max(dp[0],dp[1]);
        if(n>2)
        {
            dp[2] = dp[0]+arr[2];
            ans = max(ans,dp[2]);
            for(int i =3; i<n; i++)
            {
                dp[i] = arr[i]+max(dp[i-2],dp[i-3]);
                ans = max(dp[i],ans);
                
            }
        }
        return ans;
    }
};
