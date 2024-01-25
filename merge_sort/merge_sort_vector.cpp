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
    void sortVector(vector<int>& vec) {
        sortVectorRange(vec, 0, vec.size());
    }

    void sortVectorRange(vector<int>& vec, int start, int past_end)
    {
        if (start+1 == past_end)
            return;
        int mid = (start+past_end)/2;
        sortVectorRange(vec, start, mid);
        sortVectorRange(vec, mid, past_end);
        vector<int> right_copy;
        for (int copy_mid = mid; copy_mid < past_end; ++copy_mid)
            right_copy.push_back(vec[copy_mid]);

        mergeVectors(vec, start, mid, right_copy);
    }

    void mergeVectors(vector<int>& nums1, int start, int m, vector<int>& nums2) {
        int n = nums2.size();
        int to_fill = m+n-1;
        --m;
        --n;
        for (; n >= 0;)
        {
            if (m >= start && nums1[m] > nums2[n])
            {
                nums1[to_fill] = nums1[m];
                --m;
            }
            else
            {
                nums1[to_fill] = nums2[n];
                n--;
            }
            to_fill--;
        }
    }

    void printVector(vector<int>& vec) {
        for (int num: vec)
            cout << num << " ";
        cout << endl;
    }
};

int main()
{
    Solution sol;
    auto vec = vector<int>{1, 3, 5, 9, 3, 7};
    sol.sortVector(vec);
    sol.printVector(vec);
    return 0;
}
