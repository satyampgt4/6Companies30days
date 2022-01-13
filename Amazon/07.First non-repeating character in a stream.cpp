#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>alph(26,0);
		    string s = "";
		    for(int i =0,j=0; j<A.size(); j++)
		    {
		        alph[A[j]-'a']++;
                
		        while(i<=j && alph[A[i]-'a']>1)
		        {
		            i++;
		        }
		        if(i>j)
		        {
		            s += '#';
		        }
		        else
		        {
		            s += A[i];
		        }
		    }
		    return s;
		}

};