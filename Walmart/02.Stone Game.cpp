#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        int d[n][n];
        int sum =0;
        for(int i =0; i<n; i++)
        {
            sum +=piles[i];
            for(int a = 0,b= i; b<n; a++,b++)
            {
                
                if(i<2)
                {
                    d[a][b] = max(piles[a],piles[b]);
                }
                else
                {
                    d[a][b] = max(piles[a]+min(d[a+2][b],d[a+1][b-1]),piles[b]+min(d[a][b-2],d[a+1][b-1])); 
                }
                // cout<<d[a][b]<<" ";
            }
            // cout<<"\n";
        }
        sum = (sum/2)-(d[0][n-1]);
        
        return sum<0;
    }
};