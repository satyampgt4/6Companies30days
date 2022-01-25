#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int sum =nums[0];
        int c =1;
        for(int i=1; i<nums.size(); i++)
        {
            if(sum+nums[i]>k)
            {
                sum = nums[i];
                c++;
            }
            else
            {
                sum += nums[i];
            }
        }
        return c;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int ma =0;
        int sum =0;
        for(int i =0; i<nums.size(); i++)
        {
            ma = max(ma,nums[i]);
            sum+=nums[i];
        }
        while(ma<=sum)
        {
            int mid = ma+(sum-ma)/2;
            int t = solve(nums,mid);
            // cout<<t<<" "<<ma<<" "<<mid<<" "<<sum<<"\n";
            if(t<=m)
            {
                sum = mid-1;
            }
            else
            {
                ma = mid+1;
            }
                
        }
        return ma;
    }
};