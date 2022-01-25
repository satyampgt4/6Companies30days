#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i,vector<vector<int>>& m,vector<int>&v)
    {
        if(v[i])
            return;
        v[i] =1;
        for(int j = 0; j<v.size(); j++)
        {
            if(m[i][j])
            {
                // cout<<i<<j<<"+";
                solve(j,m,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>v(n,0);
        int ans = 0;
        for(int i =0; i<n; i++)
        {
            if(!v[i])
            {
                // cout<<i<<" \n";
                solve(i,isConnected,v);
                ans++;
            }
        }
        return ans;
    }
};