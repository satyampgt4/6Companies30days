#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        int x = (K-1+M)%N;
        if(x)
            return x;
        
        return N;
    }
};