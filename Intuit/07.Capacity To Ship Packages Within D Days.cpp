#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count_day(vector<int>& weights, int capacity)
    {
        int day =1;
        int intake =0;
        for(int i =0; i<weights.size(); i++)
        {
            if(intake+weights[i]>capacity)
            {
                intake =0;
                day++;
            }
            intake += weights[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum(0), n(weights.size()),mi(0);
        for(int i =0; i<n; i++)
        {
            sum += weights[i];
            mi = max(mi,weights[i]);
        } 
        while(mi<=sum)
        {
             int mid = mi +(sum-mi)/2;  
             int cal = count_day(weights,mid);
            if(cal>days)
            {
                mi = mid+1;
            }
            else
            {
                sum = mid-1;
            }
        }
       return mi;
        
    }
};