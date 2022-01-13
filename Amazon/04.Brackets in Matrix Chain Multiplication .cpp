#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        int a[n][n];
        string b[n][n];
        for(int t =0; t<n-1; t++)
        {
            for(int i =0,j =i+t ; j<n-1; i++, j++)
            {
                a[i][j] =INT_MAX;
                if(!t)
                {
                    a[i][j] = 0;
                    b[i][j] = ('A'+i);
                }
                else
                {
                    for(int k = i; k<j; k++)
                    {
                        int temp = a[i][k]+p[i]*p[k+1]*p[j+1]+a[k+1][j];
                        if(temp<a[i][j])
                        {
                            a[i][j] = temp;
                            b[i][j] = "("+b[i][k]+b[k+1][j]+")";
                        }
                    }
                }
            }
        }
    
        return b[0][n - 2];
    }
};