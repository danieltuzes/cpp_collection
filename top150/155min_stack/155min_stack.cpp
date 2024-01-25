#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <cmath>

using namespace std;

class MinStack
{
    stack<int> regular;
    stack<int> mins;

public:
    void push(int val)
    {
        regular.push(val);
        if (mins.empty() || mins.top() >= val)
            mins.push(val);
    }

    void pop()
    {
        if (mins.top() == regular.top())
            mins.pop();

        regular.pop();
    }

    int top()
    {
        return regular.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

int main()
{
    MinStack mys;
    mys.push(2);
    cout << mys.getMin();
    mys.push(4);
    cout << mys.getMin();
    cout << mys.top();
    mys.push(-2);
    cout << mys.getMin();
    mys.top();
    cout << mys.getMin();
    mys.pop();
    cout << mys.getMin();
    return 0;
}
