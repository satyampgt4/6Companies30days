#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

int solve(Node* root, int X,int&c)
{
    if(!root)
        return 0;
    int sum = root->data + solve(root->left,X,c) + solve(root->right,X,c);
    // cout<<root->data<<" "<<sum<<"\n";
    if(sum==X)
        c++;
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int ans =0;
	solve(root,X,ans);
	return ans;
}
