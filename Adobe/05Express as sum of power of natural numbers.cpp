#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long  numOfWays(int n, int x)
    {
        // code hereint 
        vector<vector<long long >>v;
        for(long long  i =0,k =0; k<=n; i++,k=pow(i,x))
        {
            v.push_back(vector<long long >(n+1));
            for(int j =0; j<=n; j++)
            {
                if(!j)
                {
                    v[i][j] =1;
                }
                else if (!i)
                {
                    v[i][j] = 0;
                }
                else if(j<k)
                {
                    v[i][j] = v[i-1][j];
                }
                else
                {
                    v[i][j] = v[i-1][j]+v[i-1][j-k];
                }
                // cout<<v[i][j]<<" ";
            }
            // cout<<"\n";            
        }
        return v[v.size()-1][n];
    }
};
