#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(int i, int j , int k, vector<vector<char>>& board, string word){
    //   cout<<i<<" "<<j<<" "<<k<<"\n";
        if(k== word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[k])
            return false;
            
        board[i][j] = '-';
        
        bool x = false;
        
            x = x|solve(i+1,j,k+1,board,word);
        if(!x)
            x = x|solve(i-1,j,k+1,board,word);
        if(!x)
            x = x|solve(i,j+1,k+1,board,word);
        if(!x)
            x = x|solve(i,j-1,k+1,board,word);
        
        board[i][j] = word[k];
        return x;
            
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i =0; i<board.size();i++)
        {
            for(int j =0; j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(i,j,0,board,word))
                        return true;
                }
            }
        }
        return false;
    }
};
