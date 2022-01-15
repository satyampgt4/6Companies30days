// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int> > ans;
        for(int i =0; i<n-3; i++)
        {
            for(int j =i+1; j<n-2;j++)
            {
                int p = j+1, q = n-1;
                while (p<q)
                {
                    if(arr[i]+arr[j]+arr[p]+arr[q]==k)
                    {
                        ans.push_back({arr[i],arr[j],arr[p],arr[q]});
                        
                        while(p<q && arr[p]==arr[p+1])
                            p++;
                        
                        while(p<q && arr[q]==arr[q-1])
                            q--;
                            
                            p++,q--;
                    }
                    else if(arr[i]+arr[j]+arr[p]+arr[q]<k)
                    {
                        p++;
                    }
                    else
                    {
                       q--;
                    }
                }
                while(j+1<n && arr[j]==arr[j+1])
                    j++;
            }
            while(i+1<n && arr[i]==arr[i+1])
                i++;
        }
        return ans;
    }
    
};