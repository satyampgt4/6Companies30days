#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int i,int j ,int n, int m,vector<vector<bool>>&g)
    {
        if(i<0 || i>=n || j<0 || j>=m || g [i][j])
                return false;
            
        return true;
    }
    void solve(queue<pair<int,int>>&q,vector<vector<int>>& heights,vector<vector<bool>>&p,vector<vector<int>>&fm)
    {
        int n = heights.size();
        int m = heights[0].size();
        while(q.size())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            fm[i][j]++;
            if(check(i+1,j,n,m,p) &&heights[i+1][j]>=heights[i][j])
            {
                q.push({i+1,j});
                p[i+1][j] = true;
            }
            if(check(i-1,j,n,m,p) &&heights[i-1][j]>=heights[i][j])
            {
                q.push({i-1,j});
                p[i-1][j] = true;
            }
            if(check(i,j+1,n,m,p) &&heights[i][j+1]>=heights[i][j])
            {
                q.push({i,j+1});
                p[i][j+1] = true;
            }
            if(check(i,j-1,n,m,p) &&heights[i][j-1]>=heights[i][j])
            {
                q.push({i,j-1});
                p[i][j-1] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> p(n,vector<bool>(m,false)),a(n,vector<bool>(m,false));
        vector<vector<int>> fm(n,vector<int>(m,0)),ans;
        queue<pair<int,int>>q;
        for(int i =0; i<n; i++)
        {
            q.push({i,0});
            p[i][0] = true;
        }
        for(int i =1; i<m;i++)
        {
            q.push({0,i});
            p[0][i] = true;
        }
        solve(q,heights,p,fm);
        for(int i =0; i<n; i++)
        {
            q.push({i,m-1});
            a[i][m-1] = true;
        }
        for(int i =0; i<m-1;i++)
        {
            q.push({n-1,i});
            a[n-1][i] = true;
        }
        solve(q,heights,a,fm);
        for(int i =0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // cout<<fm[i][j]<<" ";
                if(fm[i][j]==2)
                    ans.push_back({i,j});
            }
            // cout<<"\n";
        }
        return ans;
    }
};