#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s = "";
        string r = "";
        int a = str1.size(),b=str2.size();
        int n = min(a,b);
        for(int i =0; i<n; i++)
        {
            s = s+str1[i];
            if(a%(i+1) || b%(i+1))
                continue;
            int t  = a/(i+1);
            string temp = "";
            while(t--)
                temp+=s;

            if(temp != str1)
                continue;
            
            t = b/(i+1);
            temp = "";
            while(t--)
                temp+=s;
            
            if(temp != str2)
                continue;
            
            r = s;
        }
        return r;        
    }
};