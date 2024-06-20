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

// Node definition as provided.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Helper function to split the string and convert to vector
vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s.substr(1, s.size() - 2)); // Remove the brackets
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to create a tree from a string
Node *stringToNodeTree(const string &input)
{
    if (input.empty())
        return nullptr;

    vector<string> parts = split(input, ',');
    Node *root = new Node(stoi(parts[0]));
    queue<Node *> queue;
    queue.push(root);
    bool isLeft = true;

    for (int i = 1; i < parts.size(); ++i)
    {
        Node *node = queue.front();
        if (isLeft)
        {
            if (parts[i] != "null")
            {
                node->left = new Node(stoi(parts[i]));
                queue.push(node->left);
            }
            isLeft = false;
        }
        else
        {
            if (parts[i] != "null")
            {
                node->right = new Node(stoi(parts[i]));
                queue.push(node->right);
            }
            queue.pop();
            isLeft = true;
        }
    }

    return root;
}

// Function to print the tree in level order to verify
void printLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        queue<Node *> layer;
        layer.push(root);
        for (; layer.size();)
        {
            int nof_layer_elem = layer.size();
            for (int i = 0; i < nof_layer_elem; ++i)
            {
                auto curr = layer.front();
                layer.pop();
                if (i == nof_layer_elem - 1)
                {
                    curr->next = nullptr;
                }
                else
                {
                    curr->next = layer.front();
                }
                if (curr->left)
                {
                    layer.push(curr->left);
                }
                if (curr->right)
                {
                    layer.push(curr->right);
                }
            }
        }
        return root;
    }
};

int main()
{
    string treeStr = "[1,2,3,4,5,null,7]";
    Node *root = stringToNodeTree(treeStr);
    cout << "Level order traversal of the constructed tree: ";
    printLevelOrder(root);
    Solution sol;
    sol.connect(root);
    return 0;
}
