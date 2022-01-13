#include<bits/stdc++.h>
using namespace std;

/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 
*/
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
          struct Node  *temp = head;
          while(temp)
          {
              int m = M-1;
              int n = N;
              while(m-- && temp)
              {
                  temp = temp->next;
              }
              while(n-- && temp && temp->next)
              {
                  temp->next = temp->next->next;
              }
              if(temp)
                temp = temp->next;
          }
    }
};

