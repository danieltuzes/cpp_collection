#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper function to split the string and convert to vector
std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to create a tree from a string
TreeNode *stringToTreeNode(std::string input)
{
    input = input.substr(1, input.length() - 2); // Trim the brackets
    if (input.empty())
    {
        return nullptr;
    }

    std::vector<std::string> parts = split(input, ',');
    std::string item = parts[0];
    TreeNode *root = new TreeNode(stoi(item));
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    int index = 1;
    while (!nodeQueue.empty())
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (index < parts.size() && parts[index] != "null")
        {
            int leftNumber = stoi(parts[index]);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        index++;

        if (index < parts.size() && parts[index] != "null")
        {
            int rightNumber = stoi(parts[index]);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
        index++;
    }
    return root;
}

// Function to print the tree in-order (for verification)
void printInOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        printInOrder(root->left);
        std::cout << root->val << " ";
        printInOrder(root->right);
    }
}

class Solution
{
    bool isValidNode(int minm, int maxm, TreeNode *node)
    {
        if (!node)
            return true;
        int val = node->val;
        if (val > minm && val < maxm)
        {
            bool leftValid = isValidNode(minm, min(maxm, val), node->left);
            bool rightValid = isValidNode(max(minm, val), maxm, node->right);
            return leftValid && rightValid;
        }
        return false;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isValidNode(numeric_limits<int>::min(), numeric_limits<int>::max(), root);
    }
};

int main()
{
    auto tree = stringToTreeNode("[5,1,4,null,null,3,6]");
    Solution sol;
    cout << sol.isValidBST(tree);
}