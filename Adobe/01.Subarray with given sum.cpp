#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i =0,j=0;
        long long sum =0;
        for(int i =0,j=0; j<n; j++)
        {
            sum += arr[j];
            while(sum>s)
            {
                sum-=arr[i++];
            }
            if(sum == s)
            {
                return {i+1,j+1};
            }
        }
        return {-1};
        
    }
};
