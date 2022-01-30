#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN &&divisor ==-1)
            return INT_MAX;
        else if(dividend==INT_MIN &&divisor ==1)
            return INT_MIN;
        else if (dividend==INT_MIN &&divisor ==INT_MIN)
            return 1;
        else if(divisor ==INT_MIN)
            return 0;
        
        int ans =0;
        bool f =0;
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            f =1;
        divisor = abs(divisor);
        if(dividend==INT_MIN)
        {
                int temp = divisor,x =0;
            while(temp<1073741824 && -(temp<<1) >dividend)
            {

                temp = temp<<1;
                x++;
            }
            dividend = dividend + temp;
            ans+=(1<<x);
        }
        
        dividend = abs(dividend);
        while(divisor<=dividend)
        {
            int temp = divisor,x =0;
            while(temp<1073741824 && (temp<<1) <=dividend)
            {
                temp = temp<<1;
                x++;
            }
            dividend = dividend - temp;
            ans+=(1<<x);  
        }
        if(f)
            return -ans;
        return ans;
    }
};