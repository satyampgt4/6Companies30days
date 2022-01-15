#include<bits/stdc++.h>
using namespace std;


void rotate(int n,int a[][n])
{
    //code here
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<i; j++)
        {
            int t =a[i][j];
            a[i][j] = a[j][i];
            a[j][i] =t;
        }
    }
    for(int i =0; i<n; i++)
    {
        int  p=0, q= n-1;
        while(p<q)
        {
            int t =a[p][i];
            a[p][i] = a[q][i];
            a[q][i] =t;
            p++;
            q--;
        }
    }
}
