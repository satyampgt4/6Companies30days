#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans(n-k+1);    
        multiset<int,greater<int>>ms;
        for(int i =0; i<k-1; i++)
        {
            ms.insert(arr[i]);
        }
        for(int i =k-1,j=0; i<n; i++,j++)
        {
            ms.insert(arr[i]);
            ans[j] = (*ms.begin());
            ms.erase(ms.find(arr[i-k+1]));
        }
        return ans;
    }
};

//implementation 2

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
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
