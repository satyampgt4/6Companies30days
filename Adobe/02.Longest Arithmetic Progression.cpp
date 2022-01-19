#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
       
        // code here
        int ans =1;
        vector<unordered_map<int,int>>v(n);
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<i; j++)
            {
                int t = A[i]-A[j];
                if(v[j].find(t)==v[j].end())
                    v[i][t] = max(v[i][t],2);
                else
                    v[i][t] = max(v[i][t],v[j][t]+1); 
                    
                ans = max(ans,v[i][t]);
            }
        }
        return ans;
    }
};
