#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minSteps(int D){
        // code here
        int i =1;
        int ans =0;
        int sum =0;
        while(1)
        {
            sum = sum +i;
            ans++;
            i++;
            if(sum==D)
                return ans;
            else if(sum>D && !((sum-D)&1))
                return ans;
        }
    }