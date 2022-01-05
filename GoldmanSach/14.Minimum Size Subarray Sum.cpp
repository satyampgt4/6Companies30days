#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum =0;
        int ans =INT_MAX;
        int n = nums.size();
        int i =0,j=0;
        for(; j<n; j++)
        {
            while(sum>=target)
            {
                ans = min(ans,(j-i));
                sum = sum-nums[i];
                i++;
            }
            sum = sum+nums[j];
            
        }
        while(sum>=target)
            {
                ans = min(ans,(j-i));
                sum = sum-nums[i];
                i++;
            }
        
        if(ans ==INT_MAX)
            return 0;
        return ans;
    }
};