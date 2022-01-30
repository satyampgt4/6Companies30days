#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(string s, string r)
    {
        if(s.size()==r.size())
        {
            int i =0;
            while(i<s.size() &&s[i]==r[i])
                i++;
            if(i==s.size())
                return 1;
            else
                return s[i]>r[i];
        }
        return s.size()>r.size();
    }
};
class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,Compare>pq;
        
        for(int i=0; i<k;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size(); i++)
        {
            pq.push(nums[i]);
            pq.pop();
        }
        return pq.top();
    }
};