#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void solve(vector<vector<int>>& grid,int i, int j,int&c)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j])
        {
            return;
        }
        c++;
        grid[i][j] =0;
        solve(grid,i+1,j,c);
        solve(grid,i-1,j,c);
        solve(grid,i,j+1,c);
        solve(grid,i,j-1,c);
        solve(grid,i+1,j+1,c);
        solve(grid,i+1,j-1,c);
        solve(grid,i-1,j+1,c);
        solve(grid,i-1,j-1,c);
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans =0;
        for(int i =0; i<grid.size(); i++)
        {
            for(int j =0; j<grid[0].size(); j++)
            {
                if(grid[i][j])
                {
                    int c=0;
                    solve(grid,i,j,c);
                    ans = max(c,ans);
                }
            }
        }
        return ans;
    }
};
