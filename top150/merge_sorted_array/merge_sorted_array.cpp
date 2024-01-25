#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num1i = 0;
        int num2i = 0;

        for (;num2i<n; ++num2i)
        {
            for (;num1i < m && nums1[num1i] < nums2[num2i];++num1i);
            shift(nums1, num1i);
            ++m;
            nums1[num1i] = (nums2[num2i]);
        }
    }
    
    void shift(vector<int>& nums, int start)
    {
        for (int ri = nums.size()-1; ri>start; --ri)
            nums[ri] = nums[ri-1];
    }
};

int main()
{
    vector<int> nums1({1,2,3,0,0,0});
    int m = 3;
    vector<int> nums2({2,5,6});
    int n = 3;
    Solution sol;
    sol.merge2(nums1,m,nums2,n);
    for (int val: nums1) cout << val << endl;
    return 0;
}