
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<int>sti;
        stack<string>sts;
        string t = "";
        int n = s.size();
        
        for(int i =0; i<n; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                int x = s[i]-'0';
                if(i && s[i-1]>='0' && s[i-1]<='9')
                {
                    x = sti.top()*10 +x;
                    sti.pop();
                }
                sti.push(x);
                
                sts.push(t);
                t  = "";
            }
            else if(s[i]=='[')
            {
                
            }
            else if(s[i]==']')
            {
                int temp = sti.top();
                sti.pop();
                string r = sts.top();
                sts.pop();
                while(temp--)
                {
                    r += t; 
                }
             t = r;
            }
            else
            {
                t +=s[i];
            }
        }
        return t;
    }
};