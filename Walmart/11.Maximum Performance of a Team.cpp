#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        long long m = 1e9+7;
        vector<pair<int,int>>v;
        for(int i =0; i<n; i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        long long sum =0;
        long long eff=0;
        long long ans =0;
        for(int i=0; i<k; i++)
        {
            sum = sum+v[i].second;
            eff = v[i].first;
            pq.push(v[i].second);
            ans = max((sum*eff),ans);
            
        }
        for(int i=k;i<n; i++)
        {
           
                // cout<<v[i].second<<" "<<pq.top()<<"\n";
            if(v[i].second>pq.top())
            {  
                sum = sum +v[i].second-pq.top();    
                pq.pop(); 
                pq.push(v[i].second);
                
                
            
                eff = v[i].first;
                ans = max(sum*eff,ans);
            }
            
        }
        return (ans)%m;
    }
};