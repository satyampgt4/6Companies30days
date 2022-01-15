#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<vector<char>>numpad = {{},{},{'a','b','c'},
    {'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
    {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int N, int i, string s,vector<string>&ans)
    {
        if(i==N)
        {
            ans.push_back(s);
            return;
        }
        for(int j =0; j<numpad[a[i]].size(); j++)
        {
            solve(a,N,i+1,s+numpad[a[i]][j],ans);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        //Your code here
        solve(a,N,0,"",ans);
        return ans;
    }
};

