#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *solve(int i, int j, vector<vector<int>> &grid, int n, int m)
    {

        if (n - i == 0)
        {
            return new Node(grid[i][j], true);
        }
        else
        {
            int c = j + (m - j) / 2;
            int r = i + (n - i) / 2;

            Node *tl = solve(i, j, grid, r, c);
            Node *tr = solve(i, c + 1, grid, r, m);
            Node *bl = solve(r + 1, j, grid, n, c);
            Node *br = solve(r + 1, c + 1, grid, n, m);

            if (tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf 
            && tr->isLeaf && br->isLeaf && bl->isLeaf)
            {
                return new Node(tl->val, true);
            }
            else
            {
                return new Node(tl->val, false, tl, tr, bl, br);
            }
        }
    }
    Node *construct(vector<vector<int>> &grid)
    {
        if (grid.size())
        {
            return solve(0, 0, grid, grid.size() - 1, grid[0].size() - 1);
        }
        return nullptr;
    }
};