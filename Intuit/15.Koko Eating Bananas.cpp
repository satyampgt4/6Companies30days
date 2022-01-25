#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& piles, int sp)
    {
        int sum = 0;
        for(int i =0; i<piles.size() ;i++)
        {
            sum += ceil(double(piles[i])/sp); 
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int right =0,left =1;
        for(int i =0; i<piles.size() ;i++)
        {
            right = max(right,piles[i]);
        }
        while(left<=right)
        {
            int mid = left + (right - left)/2;
            int y = solve(piles,mid);
            if(y<=h)
            {
                right = mid-1;
            }
            else
            {
                left = mid +1;
            }
        }
        return left;
    }
};