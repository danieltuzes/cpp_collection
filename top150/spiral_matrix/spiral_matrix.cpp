#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int toprow = 0;
        int rightcol = matrix[0].size();
        int bottomrow = matrix.size();
        int leftcol = 0;
        for (;;)
        {
            for (int x=leftcol; x<rightcol; ++x)
                ret.push_back(matrix[toprow][x]);
            ++toprow;
            if (toprow >= bottomrow) break;

            for (int y=toprow; y<bottomrow; ++y)
                ret.push_back(matrix[y][rightcol]);
            --rightcol;
            if (leftcol >= rightcol) break;

            for (int x=rightcol; x>= leftcol; --x)
                ret.push_back(matrix[bottomrow][x]);
            --bottomrow;
            if (toprow >= bottomrow) break;

            for (int y=bottomrow; y>= toprow; --y)
                ret.push_back(matrix[y][leftcol]);
            ++leftcol;
            if (leftcol >= rightcol) break;
        }
        return ret;
    }
};



int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for (auto val: s.spiralOrder(matrix))
        cout << val;
    cout << "hi";
}