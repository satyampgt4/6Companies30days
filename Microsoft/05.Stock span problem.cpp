#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector <int>ans(n);
       stack<int>st;
       for(int i =0; i<n; i++)
       {
           int t = 1+i;
           while(st.size())
           {
               if(price[st.top()]>price[i])
                {
                   t -=(st.top()+1);
                    break;
                }
                st.pop();
           }
           ans[i]= t;
           st.push(i);
       }
       return ans;
    }
};

