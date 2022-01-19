#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        bool x =1;
        int ans =0;
        for(int i =0; i<s.size() ; i++)
        {
            if(x && s[i]=='-')
            {
                x = 0;
            }
            else if (s[i]<='9' && s[i]>='0')
            {
                ans = ans*10 + (s[i]-'0');
            }
            else
                return -1;
        }
        if(x)
            return ans;
        else
            return -ans;
            
    }
};
