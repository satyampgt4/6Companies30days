#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>g(N);
	    vector<int>inorder(N,0),ans;
	    for(int i=0; i<prerequisites.size(); i++)
	    {
	        g[prerequisites[i].second].push_back(prerequisites[i].first);
	        inorder[prerequisites[i].first]++;
	    }
	    for(int i=0; i<N; i++)
	    {
	        if(!inorder[i])
	            ans.push_back(i);
	    }
	    for(int i=0;i<ans.size();i++)
	    {
	        for(auto x : g[ans[i]])
	        {
	            inorder[x]--;
	            if(!inorder[x])
	                ans.push_back(x);
	            
	        }
	    }
	    return N == ans.size();
	}
};