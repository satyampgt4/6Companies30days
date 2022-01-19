#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string compare_libaray(string s1,string s2)
    {
        int i =0,j=0;
        while(1)
        {
            int x =0;
            int y =0;
            for(; i<s1.size(); i++)
            {
                if(s1[i]=='.')
                {
                    i++;
                    break;
                }
                else
                {
                    x = x*10 + (s1[i]-'0');
                } 
            }
            for(; j<s2.size(); j++)
            {
                if(s2[j]=='.')
                {
                    j++;
                    break;
                }
                else
                {
                    x = x*10 + (s2[j]-'0');
                }
            }
            if(x>y)
                return s1;
            if(y>x)
                return s2; 
        }
        return "-1";
    }
};
