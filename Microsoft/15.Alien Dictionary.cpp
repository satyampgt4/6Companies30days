#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        int strs =0;
         unordered_map<char,int> m;
         unordered_map<char,vector<char>>g;
         for(int i =0; i<N; i++)
        {
           for(auto x :dict[i])
              m[x];
        }
        for(int i =1; i<N; i++)
        {
           int ma = min(dict[i].size(),dict[i-1].size());
           
           for(int j =0; j<ma; j++)
           {
              m[dict[i][j]];
               if(dict[i-1][j] != dict[i][j])
               {
                   g[dict[i-1][j]].push_back(dict[i][j]);
                   m[dict[i][j]]++;
                  break;
               }
           }
        }
        
        string s = "";
        for(auto x: m)
        {
            // cout<<x.first<<" "<<x.second<<"\n";
            if(!x.second)
                s +=x.first;
        }
        for(int i =0; i<s.size();i++)
        {
            for(auto y : g[s[i]])
            {
                m[y]--;
                if(!m[y])
                {
                    s+=y;
                }
            }
        }
        // cout<<s;
        return s;
        
    }
    
};