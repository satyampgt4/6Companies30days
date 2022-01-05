#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long> FindMax10Numbers(vector<long long>& nums) {
       
       int n = nums.size();
       priority_queue<long long,vector<long long>,greater<long long>> pq;

       for(int i =0; i<10; i++)
           pq.push(nums[i]);
       
       for(int i =10; i<n; i++)
       {
           if(nums[i]>pq.top())
           {
               pq.pop();
               pq.push(nums[i]);
           }
       }
       vector<long long> ans(10);
       for(int i=9; i>=0; i--)
       {
           ans[i] = pq.top();
           pq.pop();
       }
       return ans;
    }
};