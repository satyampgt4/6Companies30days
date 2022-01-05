#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
       int n = nums.size();
       unordered_map<int,int>m;
       
       for(int i =0; i<n; i++)
       {
           if(m[(k-(nums[i])%k)%k]>0)
           {
                m[(k-(nums[i])%k)%k]--;
           }
           else
           {
               m[(nums[i])%k]++;
           }
       }
       for(auto x: m)
       {
           if(x.second)
           return false;
       }
       return true ;
    }
};
