#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int> m;
        int ans =0;
        string win ="{";
        for(int i =0; i<n; i++)
        {
            m[arr[i]]++;
            ans = max(ans,m[arr[i]]);
        }
        for(auto x:m)
        {
            if(x.second == ans && win>x.first)
                win  = x.first;
        }
        
        return {win,to_string(ans)};
    }
};
