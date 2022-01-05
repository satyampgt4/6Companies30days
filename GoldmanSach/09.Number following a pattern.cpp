#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here
        stack<int>st;
        string r = "";
        int n = S.size();
        for(int i =0; i<n; i++)
        {
            st.push(i+1);
            if(S[i]=='I')
            {
                while(st.size())
                {
                    r+=to_string(st.top());
                    st.pop();
                }
            }
        }
         st.push(n+1);
                while(st.size())
                {
                    r+=to_string(st.top());
                    st.pop();
                }
        return r;
    }
};
