#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //You need to complete this fucntion
    const int m = 1e9+7;
    long long power(int N,int R)
    {
       //Your code here
        if(R==1)
        return N;
        
        long long t = power(N,R/2)%m;
        t = (t*t)%m;
        
        if(R&1)
            t = (t*N)%m;
        return t;
    }

};
