#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans(n-k+1);    
        priority_queue<int>pq1,pq2;
        for(int i =0; i<k-1; i++)
        {
            pq1.push(arr[i]);
        }
        for(int i =k-1,j=0; i<n; i++,j++)
        {
            pq1.push(arr[i]);
            while(pq2.size() && pq1.top()==pq2.top())
            {
                pq1.pop();
                pq2.pop();
            }
            ans[j] = (pq1.top());
            pq2.push(arr[i-k+1]);
        }
        return ans;
    }
};