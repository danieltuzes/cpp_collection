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

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = nums1.size();
        for (; low <= high;)
        {
            int mid1 = (low + high) / 2;
            int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;

            int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int r1 = mid1 < nums1.size() ? nums1[mid1] : INT_MAX;

            int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            int r2 = mid2 < nums2.size() ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
            {
                if ((nums1.size() + nums2.size()) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                high = mid1;
            }
            else if (r1 < l2)
            {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};