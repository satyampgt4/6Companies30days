#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double x,y,r,d;
    double fRand(double fMax)
    {
        double f = double(rand()) / RAND_MAX *fMax;
        return f;
    }
    Solution(double radius, double x_center, double y_center) {
        
        x=x_center;
        y=y_center;
        r=radius;
        d = radius+radius;
    }
    
    vector<double> randPoint() {

        double p =x-r+fRand(d);
        double q =y-r+fRand(d);
        while(((x-p)*(x-p)+(y-q)*(y-q))>(r*r))
        {
            p =x-r+fRand(d);
            q =y-r+fRand(d);
        }
        return {p,q};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */