#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void solve(vector<int> adj[],int i,  int c, int d,vector<bool>&ch)
    {
        if(ch[i])
        {
            ch[i] = false;
            for(auto x : adj[i])
            {
                if((x==c && i ==d) || (x==d && i ==c));
                else
                {
                    solve(adj,x,c,d,ch);
                }
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool>check_before(V,true),check_after(V,true);
        int coun1 =0,coun2 =0;
        for(int i =0; i<V; i++)
        {
            if(check_before[i])
            {
                solve(adj,i,-1,-1,check_before);
                coun1++;
            }
        }
        for(int i =0; i<V; i++)
        {
            if(check_after[i])
            {
                solve(adj,i,c,d,check_after);
                coun2++;
            }
        }
        return coun1 !=coun2;
    }
};