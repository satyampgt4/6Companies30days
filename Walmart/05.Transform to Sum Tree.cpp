#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *node)
    {
        if(!node)
            return 0;
        
        int temp = node->data;
            node->data =0;
        if (node->left ||node->right)
        {
            node->data = solve(node->left)+solve(node->right);
        }
        return node->data +temp;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};