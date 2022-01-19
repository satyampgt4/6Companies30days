#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n = N.size()/2;
        
        if(n<2)
            return "-1";
            
        int i;
        for(i =n-1; i>0; i--)
        {
            if(N[i]>N[i-1])
                break;
        }
        if(!i)
            return "-1";
        
        
        int a = i,b= n-1;
        while(a<b)
        {
            swap(N[a],N[b]);
            a++,b--;
        }
        for(int j = i; j<n; j++)
            {
                if(N[j]>N[i-1])
                {
                    swap(N[j],N[i-1]);
                    break;
                }
            }
        a =0; b = N.size()-1;
        while(a<b)
        {
            N[b--] = N[a++];
        }
        return N;
        
    }
};
