#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& grid, int i,int j)
    {
        if(i<0 ||j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]!=1)
            return false;
       return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int p =0;
        int c =0;
        int ans =0;
        queue<pair<int,int>>g;
        int oren=0;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    g.push({i,j});
                    p++;
                }
                if(grid[i][j] !=0)
                {
                    oren++;
                }
            }
        }
        if(p)
            ans =-1;
        while(g.size())
        {
            auto t = g.front();
            g.pop();
            int i =t.first;
            int j = t.second;
           
            if(check(grid,i+1,j))
            {
                g.push({i+1,j});
                c++;
                 grid[i+1][j] = 2;
            
            } 
            if(check(grid,i-1,j))
            {
                
                g.push({i-1,j});
                c++;
                 grid[i-1][j] = 2;
            
            } 
            if(check(grid,i,j+1))
            {
                
                g.push({i,j+1});
                c++;
                 grid[i][j+1] = 2;
            
            } 
            if(check(grid,i,j-1))
            {
                
                g.push({i,j-1});
                c++;
                 grid[i][j-1] = 2;
            
            } 
            oren--;
            p--;
            if(!p)
            {
                ans++;
                p=c;
                c=0;
            }
            // cout<<p<<" "<<c<<" "<<ans<<"\n";
        }
        if(oren)
        {
            return -1;
        }
        return ans;
    }
};