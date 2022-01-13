#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int sovle(Node* root, int&maxdis, int target)
    {
        if(!root)
            return -1;
        else
        {
            int ld = sovle(root->left,maxdis,target);
            int rd = sovle(root->right,maxdis,target); 
            
            if(root->data == target)
            {
                maxdis = -min(ld,rd);
                return 1;
            }
            else if(ld>0)
            {
                maxdis = max(ld-rd,maxdis);
                return ld+1;
            }
            else if(rd>0)
            {
                maxdis = max(rd-ld,maxdis);
               
                return rd+1;
            }
            else
            {
                return min(ld,rd)-1;
                
            }
        }
        
    }
    int minTime(Node* root, int target) 
    {
        int maxdis = 0;
        sovle(root,maxdis,target); 
        return maxdis-1 ;
    }
    };