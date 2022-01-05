#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {

        long long pro =1;
        int ans =0;
        for(int i =0,j=0; j<n; j++)
        {
            pro = pro*a[j];
            while(pro>=k)
            {
                pro = pro/a[i];
                i++;
            }
            // cout<<pro<<" "<<j-i+1<<"\n";
            ans = ans + (j-i+1);
        }
        return ans;
    }
};