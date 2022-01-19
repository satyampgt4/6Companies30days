#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum =0;
        for(int i =0; i<N; i++)
            sum +=arr[i];
        if(sum&1)
            return 0;
        sum = sum/2;
        int d[N+1][sum+1];
        for(int i =0; i<=N; i++)
        {
            for(int j =0; j<=sum; j++)
            {
                if(!j)
                    d[i][j] =1;
                else if(!i)
                    d[i][j] = 0;
                else if(j<arr[i-1])
                {
                    d[i][j] = d[i-1][j];
                }
                else
                {
                    d[i][j] = d[i-1][j]| d[i-1][j-arr[i-1]];
                }
            }
        }
        return d[N][sum];
    }
};