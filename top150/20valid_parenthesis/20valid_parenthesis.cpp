#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
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
    bool valid_parenthesis(string s)
    {
        stack<char> parhs;
        for (char letter : s)
        {
            if (letter == '(' || letter == '{' || letter == '[') // opening char
                parhs.push(letter);
            else // closing char, guaranteed by descr
            {
                if (parhs.empty())
                    return false;

                char t = parhs.top();
                if ((t == '(' && letter == ')') ||
                    t == '[' && letter == ']' ||
                    t == '{' && letter == '}')
                    parhs.pop();
                else
                    return false;
            }
        }

        return parhs.empty();
    };
};

int main()
{
    Solution sol;
    cout << sol.valid_parenthesis("()[]{}") << endl;
    cout << sol.valid_parenthesis("([{}])") << endl;
    cout << sol.valid_parenthesis("()[]{") << endl;
    cout << sol.valid_parenthesis("()[]}") << endl;
    return 0;
}