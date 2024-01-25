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

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


TreeNode* constructTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < values.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int smallest = numeric_limits<int>::max();
        TreeNode* prev = nullptr;

        deque<TreeNode*> levels;
        levels.push_back(root);
        for(; root->left; root = root->left)
                levels.push_back(root->left);

        for(; !levels.empty(); )
        {
            root = levels.back();
            levels.pop_back();

            if (prev)
                smallest = min(smallest, root->val - prev->val);
            
            prev = root;
            if (root->right)
            {
                levels.push_back(root->right);
                root = root->right;
                for(; root->left; root = root->left)
                    levels.push_back(root->left);
            }
        }
        return smallest;
    }
};


int main()
{
    std::vector<int> values = {4,2,6,1,3};
    TreeNode* root = constructTree(values);
    Solution sol;
    cout << sol.getMinimumDifference(root);
    
    return 0;
}

    