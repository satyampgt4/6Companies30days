#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
       int tr =0,br = r-1, lc = 0, rc =c-1;
        vector<int>v;
        
        while(tr<=br && lc<=rc)
        {
            // cout<<tr<<" "<<br<<" "<<lc<<" "<<rc<<"\n";
            if(tr==br && lc==rc)
            {
                v.push_back(matrix[tr][lc]);
                return v;
            }
            for(int i =lc; i<rc; i++)
            {
                v.push_back(matrix[tr][i]);   
            }
            for(int i =tr; i<br; i++)
            {
                v.push_back(matrix[i][rc]);   
            }
            if(tr!=br)
            {
                 for(int i =rc; i>lc; i--)
                {
                    v.push_back(matrix[br][i]);   
                }
            }
            else
            {
                v.push_back(matrix[tr][rc]);
            }
            if(lc!=rc)
            {
                for(int i =br; i>tr; i--)
                {
                    v.push_back(matrix[i][lc]);   
                }
            }
            else
            {
                
                v.push_back(matrix[br][rc]);
            }
            tr++,lc++,br--,rc--;
        }
        return v;
    }
};