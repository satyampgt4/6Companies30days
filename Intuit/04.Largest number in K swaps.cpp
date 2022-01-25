#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(string str, int k,int i, string& ans)
    {
        if(!k ||i==str.size())
            return;
        int j = i;
        for(int p =i+1;p<str.size(); p++)
        {
            if(str[p]>str[j])
                j=p;
        }
        if(str[i]!=str[j])
        {
            k--;
            for(int p = i+1;p<str.size(); p++)
            {
                if(str[p]==str[j])
                {    
                    swap(str[p],str[i]);
                ans = max(ans,str);
                solve(str,k,i+1,ans);
                swap(str[p],str[i]);
                }
            }
        }
        else
        {
            solve(str,k,i+1,ans);
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    
    {
       // code here.
       solve(str,k,0,str);
       return str;
    } 
};