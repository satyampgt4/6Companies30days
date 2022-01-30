#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        
        colors +='-';
        char last = '-';
        int c=0,a=0,b=0;
        for(int i =0; i<colors.size();i++)
        {
            if(colors[i]==last)
                c++;
            else
            {
                if(c>2)
                {
                    if(last =='A')
                    {
                        a +=(c-2);
                    }
                    else if(last =='B')
                    {
                        b +=(c-2);
                    }
                }
                c=1;
                last=colors[i];
            }
        }
        // cout<<a<<" "<<b;
        if(a>b)
            return true;
        else 
            return false;
    }
};