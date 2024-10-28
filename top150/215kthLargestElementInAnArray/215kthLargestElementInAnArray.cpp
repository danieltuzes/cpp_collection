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
    int kthLargest(vector<int> numbers, int k)
    {
        priority_queue<int, vector<int>, greater<int>> ord_nums;
        for (int num : numbers)
        {
            if (ord_nums.size() < k)
                ord_nums.push(num);
            else if (ord_nums.top() < num)
            {
                ord_nums.pop();
                ord_nums.push(num);
            }
        }
        return ord_nums.top();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> numbers_arr = {{3, 2, 1, 5, 6, 4}, {3, 2, 3, 1, 2, 4, 5, 5, 6}};
    vector<int> ks = {2, 4};
    for (int i = 0; i < 2; ++i)
        cout << sol.kthLargest(numbers_arr[i], ks[i]);
}