#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string r = "";
        if(s[0]<'a')
            r +=(s[0]+32);
        else
            r +=(s[0]);
        for(int i =1; i<s.size(); i++)
        {
            if(s[i]<'a')
            {
                r +=" ";
                r +=(s[i]+32);
            }
            else
            {
                r +=(s[i]);
            }
        }
        return r;
    }
};
