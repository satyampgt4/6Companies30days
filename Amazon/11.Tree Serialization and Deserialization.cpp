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

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void solve_serial(Node *root,vector<int>&a)
    {
        if(!root)
        {
            a.push_back(-1);
            return;
        }
            
        
            a.push_back(root->data);
        solve_serial(root->left,a);
        solve_serial(root->right,a);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>x;
        solve_serial(root,x);
        return x;
        
    }
    
    //Function to deserialize a list and construct the tree.
    Node * solve_deserial(int &i,vector<int>&a)
    {
        if(i>=a.size() || a[i]==-1)
        {
            i++;
            return nullptr;
        }
            
        
        Node * temp = new Node(a[i++]);
        temp->left = solve_deserial(i,a);
        temp->right = solve_deserial(i,a);
        return temp;
    }
    Node * deSerialize(vector<int> &A)
    {
        int i =0;
        return solve_deserial(i,A);
        
       //Your code here
    }

};