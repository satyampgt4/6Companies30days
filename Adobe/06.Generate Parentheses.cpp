#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(int n,int m, string s, vector<string>&ans)
    {
        if(!n && !m)
        {
            ans.push_back(s);
            return;
        }
        if(n)
        {
            solve(n-1,m+1,s+'(',ans);
        }
        if(m)
        {
             solve(n,m-1,s+')',ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
            solve(n,0,"",ans);
        return ans;
        // Your code goes here 
    }
};
