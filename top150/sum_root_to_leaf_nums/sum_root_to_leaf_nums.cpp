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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        
        vector<string> nums;
        getNums(nums, root);
        return accumulate(nums.begin(), nums.end(), 0, [](int sum, string num) {return sum+stoi(num);});

    }
    void getNums(vector<string>& nums, TreeNode* root)
    {
        if (!root->left && !root->right)
        {
            nums.push_back(to_string(root->val));
            return;
        }
        
        if (root->left)
        {
            getNums(nums, root->left);
        }
        if (root->right)
        {
            getNums(nums, root->right);
        }
        for (auto& val : nums)
            val = to_string(root->val) + val;
        
    }
};


int main()
{
    std::vector<int> values = {1, 5, 1, -1, -1, -1, 6};
    TreeNode* root = constructTree(values);
    Solution sol;
    cout << sol.sumNumbers(root);
    
    return 0;
}

    