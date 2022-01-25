#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<bool>>&ch,int i,int j)
    {
        if(i<0|| j<0 || i>=ch.size()|| j>=ch[0].size() ||ch[i][j])
            return false;
            
        return ch[i][j] = true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> ch(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        int p =0;
        int c =0;
        int l =0;
        int ans =0;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j])
                {
                    ch[i][j] = true;
                    q.push({i,j});
                    p++;
                }
            }
        }
        if(!q.size())
            return -1;
        while(q.size())
        {
            int i = q.front().first;
            int j = q.front().second;
            ans = max(ans,l);
            q.pop();
            p--;
            if(check(ch,i+1,j))
            {
                q.push({i+1,j});
                    c++;
            }
            if(check(ch,i-1,j))
            {
                q.push({i-1,j});
                    c++;
            }
            if(check(ch,i,j+1))
            {
                q.push({i,j+1});
                    c++;
            }
            if(check(ch,i,j-1))
            {
                q.push({i,j-1});
                    c++;
            }
            if(p ==0)
            {
                p = c;
                c= 0;
                l++;
            }
        }
        if(l == 1)
            return -1;
        return l-1;
        
    }
};