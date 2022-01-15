#include <bits/stdc++.h>
using namespace std;


vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i =1; i<=N; i++)
	{
	    int t = i;
	    string s = "";
	    while(t)
	    {
	        s = s+to_string(t&1);
	        t = t>>1;
	    }
	    reverse(s.begin(),s.end());
	    ans.push_back(s);
	}
	return ans;
}
