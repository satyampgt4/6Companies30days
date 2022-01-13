#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string colName (long long int n)
    {
        string s="";
        while(n)
        {
            int t = n%26;
            n = n/26;
            if(!t)
            {
                    t = 26;
                    n--;
            }
            // cout<<t<<" "<<n<<"\n";
            s =char('A'-1+t)+s;
        }
        return s;
    }
};