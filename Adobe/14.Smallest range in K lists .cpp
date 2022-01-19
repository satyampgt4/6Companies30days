#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>mih;
        int m = 0;
        for(int i =0; i<k; i++)
        {
            mih.push({KSortedArray[i][0],{i,0}});
            m = max(m,KSortedArray[i][0]);
        }
        pair<int,int> ans = {-100000,100000};
        while(1)
        {
            // cout<<mah.top()[0]<<" "<<mih.top()[0]<<"\n";
            if((m-mih.top().first)<(ans.second-ans.first))
            {
                ans  ={mih.top().first,m};
            }
            int i = mih.top().second.first;
            int j = mih.top().second.second+1;
            if(j==n)
                break;
            mih.pop();
            mih.push({KSortedArray[i][j],{i,j}});
            m = max(KSortedArray[i][j],m);

        }
        return ans;
    }

};