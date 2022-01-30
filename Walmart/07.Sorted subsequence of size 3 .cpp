#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        // Your code here
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i =n-1; i>=0; i--)
        {
            while(st.size() &&arr[st.top()]<=arr[i])
                st.pop();
            if(st.size())
                ans[i] = st.top();
            st.push(i);
        }
        for(int i =0; i<n; i++)
        {

            if(ans[i]==-1);
            else if(ans[ans[i]] != -1)
            {

                return {arr[i],arr[ans[i]],arr[ans[ans[i]]]};
            }
        }
        return {};
    }
};
