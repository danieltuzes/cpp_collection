#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <cmath>

using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
    bool allSame(vector<vector<int>> &grid, int sr, int sc, int size)
    {
        int val = grid[sr][sc];
        for (int i = sr; i < sr + size; ++i)
        {
            for (int j = sc; j < sc + size; ++j)
            {
                if (grid[i][j] != val)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void constrBlock(vector<vector<int>> &grid, Node *root, int sr, int sc, int size)
    {
        root->val = grid[sr][sc];
        if (allSame(grid, sr, sc, size))
        {
            root->isLeaf = true;
            return;
        }
        root->isLeaf = false;

        int subs = size / 2;
        // top left
        root->topLeft = new Node;
        constrBlock(grid, root->topLeft, sr, sc, subs);

        // top right
        root->topRight = new Node;
        constrBlock(grid, root->topRight, sr, sc + subs, subs);

        // bottem left
        root->bottomLeft = new Node;
        constrBlock(grid, root->bottomLeft, sr + subs, sc, subs);

        // bottom right
        root->bottomRight = new Node;
        constrBlock(grid, root->bottomRight, sr + subs, sc + subs, subs);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        Node *ret = new Node;
        constrBlock(grid, ret, 0, 0, grid.size());
        return ret;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
    Solution sol;
    sol.construct(matrix);
}