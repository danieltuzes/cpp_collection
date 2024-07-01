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
    int getNext(int &start, string &s)
    {
        if (s[start] == '(')
        {
            start++;
            return eval(start, s);
        }
        if (s[start] == '-')
        {
            start++;
            return -getNext(start, s);
        }
        int num = 0;
        for (; start < s.length() && isdigit(s[start]); start++)
        {
            num *= 10;
            int val = (int)(s[start] - '0');
            num += val;
        }
        return num;
    }

    int eval(int &start, string &s)
    {
        vector<int> terms;
        terms.push_back(getNext(start, s));
        for (; start < s.length();)
        {
            char operand = s[start];
            start++;
            if (operand == ')')
                break;
            int nextval = getNext(start, s);
            if (operand == '*')
                terms.back() *= nextval;
            else if (operand == '/')
                terms.back() /= nextval;
            else if (operand == '-')
                terms.push_back(-nextval);
            else if (operand == '+')
                terms.push_back(nextval);
            else
                cout << "error";
        }
        int sum = 0;
        for (int term : terms)
            sum += term;

        return sum;
    }

public:
    int calculate(string s)
    {
        int start = 0;
        string spaceRemoved;
        for (auto chara : s)
        {
            if (chara != ' ')
                spaceRemoved.push_back(chara);
        }
        return eval(start, spaceRemoved);
    }
};

class Solution2
{
public:
    int calculate(const string &s)
    {
        int l = 0;
        return calculate(s, l);
    }

private:
    int calculate(const string &s, int &l)
    {
        int ans = 0;
        int num = 0;
        int sign = 1;

        while (l < s.size())
        {
            int c = s[l++];
            if (isdigit(c))
            {
                num = (num * 10) + (c - '0');
            }
            else
            {
                ans += num * sign;
                num = 0;

                if (c == '+')
                {
                    sign = 1;
                }
                else if (c == '-')
                {
                    sign = -1;
                }
                else if (c == '(')
                {
                    ans += sign * calculate(s, l);
                }
                else if (c == ')')
                {
                    return ans;
                }
            }
        }

        ans += num * sign;
        return ans;
    }
};

int main()
{
    Solution sol;
    // string calcstring = "1+2";
    // string calcstring = " 2-1 + 2 ";
    // string calcstring = "-2+ 1";
    // string calcstring = "(1+(4+5+2)-3)+(6+8)";
    string calcstring = "(1+(4+5*2)-3)/(4+8)";
    cout << sol.calculate(calcstring);
}