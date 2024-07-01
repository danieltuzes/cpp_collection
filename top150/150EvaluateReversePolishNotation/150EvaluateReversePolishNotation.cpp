#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
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

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> nums;
        for (int i = 0; i < tokens.size(); ++i)
        {
            string inp = tokens[i];
            if (inp == "+" || inp == "-" || inp == "/" || inp == "*")
            {
                int rhs = nums.back();
                nums.pop_back();
                int lhs = nums.back();
                nums.pop_back();
                if (inp == "+")
                    nums.push_back(lhs + rhs);
                else if (inp == "-")
                    nums.push_back(lhs - rhs);
                else if (inp == "*")
                    nums.push_back(lhs * rhs);
                else
                    nums.push_back(lhs / rhs);
            }
            else
                nums.push_back(stoi(inp));
        }
        return nums.back();
    }
};

int main()
{
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sol;
    cout << sol.evalRPN(tokens);
}