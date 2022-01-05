#include<bits/stdc++.h>
using namespace std;
#define  ull unsigned long long

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    int two =0,three =0,five =0;
	    ull uglyNo[n] ;
	    uglyNo[0]= 1;
	    
	    for(int i =1; i<n; i++)
	    {
	        uglyNo[i] = min(min(2*uglyNo[two],3*uglyNo[three]),5*uglyNo[five]);
	        
	        if(uglyNo[i] == 2*uglyNo[two]) two++;
	        if(uglyNo[i] == 3*uglyNo[three]) three++;
	        if(uglyNo[i] == 5*uglyNo[five]) five++;
	    }
	    return uglyNo[n-1];
	}
};

