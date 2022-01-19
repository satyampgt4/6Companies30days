#include <bits/stdc++.h>
using namespace std;

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        
        stack<int>st,st2;
        
        for(int i =n-1; i>=0; i--)
        {
            while(st.size() &&st.top()<=a[i]){
                st.pop();
            }
            if(st.size());
            else
            {
                st2.push(a[i]);
            }
            st.push(a[i]);
        }
        int m = st2.size();
        vector<int>ans(m);
        for(int i =0; i<m; i++)
        {
            ans[i] = st2.top();
            st2.pop();
        }
        return ans;   
    }
};