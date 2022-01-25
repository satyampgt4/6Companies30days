#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans =0;
        for(int i =0 ;i<points.size(); i++)
        {
            unordered_map<long long,int>m;
            for(int j =0; j<points.size(); j++)
            {
                m[(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+
                 (points[i][1]-points[j][1])*(points[i][1]-points[j][1])]++;
            }
            for(auto x:m)
            {
                // cout<<x.first<<" "<<x.second<<"\n";
                if(x.second>1)
                {
                    ans += (x.second*(x.second-1));
                }
            }
        }
        return ans;
    }
};