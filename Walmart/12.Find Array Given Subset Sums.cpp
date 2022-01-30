#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>v,vector<int>&ans)
    {
        if(v.size()==1)
            return;
        
        sort(v.rbegin(),v.rend());            
        unordered_map<int,int>m;
        for(int i =0; i<v.size(); i++)
            m[v[i]]++;
        
        int x = v[0]-v[1];
       
        vector<int>l,r;
        bool f =0;
        for(int i =0; i<v.size(); i++)
        {
            if(m[v[i]]&& m.find(v[i]-x)!=m.end() && m[v[i]-x])
            {
                m[v[i]]--;
                m[v[i]-x]--;
                l.push_back(v[i]-x);
                r.push_back(v[i]);
                if(!v[i])
                    f=1;
            }
        }
        if(f)
        {
            ans.push_back(-x);
            solve(r,ans);
        }
        else
        {
            ans.push_back(x);
            solve(l,ans);
        }
        
    }
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int>ans;
        solve(sums,ans);
        return ans;
    }
};