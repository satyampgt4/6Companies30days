#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*>q;
       int p=1;
       int c=0;
       q.push(root);
       while(q.size())
       {
           Node *temp = q.front();
           q.pop();
           p--;
           if(temp->left)
           {
               q.push(temp->left);
               c++;
               
           }
           if(temp->right)
           {
               q.push(temp->right);
               c++;
               
           }
           if(!p)
           {
                p=c;
                c=0;
                temp->nextRight = NULL;
           }
           else
           {
               temp->nextRight = q.front();
           }
           
       }
       
    }    
      
};

