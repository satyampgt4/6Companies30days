#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code hereint
        int x[a][b];
        x[0][0] =1;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b;j++)
            {
                if(!i||!j)
                {
                    x[i][j] =1;
                }
                else
                {
                    x[i][j] = x[i-1][j]+x[i][j-1];
                }
            }
        }
        return x[a-1][b-1];
    }
};
