#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<double,int>>>v(n,vector<pair<double,int>>(0));
        
        for(int i =0; i<edges.size(); i++)
        {
            v[edges[i][0]].push_back({succProb[i],edges[i][1]});
            
            v[edges[i][1]].push_back({succProb[i],edges[i][0]});
            
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        pq.push({1,start});
        vector<bool>c(n,true);
        while(pq.size())
        {
            
            auto x = pq.top();
            if(x.second==end)
            {
                return x.first;
            }
            c[x.second] = false;
            pq.pop();
            for(int i =0; i<v[x.second].size(); i++)
            {
                if(c[v[x.second][i].second])
                    pq.push({x.first*v[x.second][i].first,v[x.second][i].second});
            }  
        }
        return 0;
    }
};