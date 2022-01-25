#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses, vector<int>());
        vector<int>inc(numCourses,0);
        for(int i =0; i<prerequisites.size(); i++)
        {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inc[prerequisites[i][0]]++;
        }
        vector<int>ans;
        for(int i=0;i<numCourses;i++)
        {
            if(!inc[i])
            {
                ans.push_back(i);
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j =0; j<v[ans[i]].size(); j++)
            {
                inc[v[ans[i]][j]]--;
                if(!inc[v[ans[i]][j]])
                {
                     ans.push_back(v[ans[i]][j]);   
                }
            }
        }
        if(ans.size() != numCourses)
            return {};
        return ans;
    }
};