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
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode * sortedArrayToBST(vector<int>& nums, int start, int end)
    {
        if (end <= start)
            return nullptr;
        int mid = (end-start)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid);
        root->right = sortedArrayToBST(nums, mid+1, end);
        return root;
    }
    

    vector<int> parseStringToVector(string data) {
        vector<int> result;
        // Remove the leading '[' and trailing ']'
        data = data.substr(1, data.size() - 2);

        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            result.push_back(stoi(item));
        }
        return result;
    }

};


int main()
{
    Solution solution;
    string data = "[-10,-3,0,5,9]";
    auto nums = solution.parseStringToVector(data);
    TreeNode* root = solution.sortedArrayToBST(nums);
    
    return 0;
}

    