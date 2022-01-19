#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> lis;
        
        unordered_set<int> s;
        for(int i = 0; i < M ;i++){
            s.insert(B[i]);
        }
        for(int i = 0; i < N ;i++){
            if(s.find(A[i])!=s.end()){
                if(lis.size())
                {
                    if(lis[lis.size()-1]<A[i])
                    {
                        lis.push_back(A[i]);
                    }
                    else
                    {
                        int j = lower_bound(lis.begin(),lis.end(),A[i])-lis.begin();
                        lis[j] = A[i];
                    }
                }
                else
                {
                    lis.push_back(A[i]);
                }
            }
        }
        
        return N+M-2*lis.size();
    }
};