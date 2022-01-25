#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>v(n,0);
        for(int i =0; i<n; i++)
        {
            for(int j =n-1; j>=0 && !grid[i][j]; j--)
            {
                v[i]++;
            }
        }
        int ans =0;
        for(int i =0; i<n; i++)
        {
           int j =i;
            while(j<n && v[j]<n-1-i)
            {
                j++;
            }
            if(j ==n)
                return -1;
            ans += (j-i);
            while(j>i)
            {
                v[j] = v[j-1];
                j--;
            }
        }
        
        return ans;
    }
};