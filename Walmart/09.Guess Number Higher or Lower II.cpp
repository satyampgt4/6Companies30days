#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        
        int d[n][n];
        for(int i=0; i<n; i++)
        {
            for(int a =0,b = a+i; b<n; a++,b++)
            {
                if(!i)
                {
                    d[a][b] =0;
                }
                else if(i<3)
                {
                    int t = a + (i)/2;
                    d[a][b] = t+1;
                }
                else
                {
                    d[a][b] =INT_MAX;
                    for(int k =a+1; k<b; k++)
                    {
                        d[a][b] = min(d[a][b],k+1+max(d[a][k-1],d[k+1][b]));
                    }
                }
                // cout<<d[a][b]<<" ";
            }
            // cout<<"\n";
        }
        return d[0][n-1];
    }
};