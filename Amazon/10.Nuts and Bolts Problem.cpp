#include<bits/stdc++.h>
using namespace std;


class Solution {
public:    

    void matchPairs(char nuts[], char bolts[], int n) {

        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(bolts[j] == nuts[i]) {
                    char temp = bolts[i];
                    bolts[i] = bolts[j];
                    bolts[j] = temp;
                    continue;
                }
            }
        }
        
       
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return nuts[i] < bolts[j];
        });
        
        
        for(int i = 0; i < n; ++i) {
            nuts[i] = bolts[order[i]];
        }
        for(int j = 0; j < n; ++j) {
            bolts[j] = nuts[j];
        }

    }
};