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

template <typename T>
class myQueue
{
    stack<T> pri;
    stack<T> sec;
    bool reverted;
    void revert()
    {
        if (reverted)
        {
            for (; !sec.empty();)
            {
                pri.push(sec.top());
                sec.pop();
            }
            reverted = false;
        }
        else
        {
            for (; !pri.empty();)
            {
                sec.push(pri.top());
                pri.pop();
            }
            reverted = true;
        }
    }

public:
    myQueue() : reverted(false) {};
    void push(T val)
    {
        if (reverted)
        {
            revert();
            reverted = false;
        }
        pri.push(val);
    }

    T back()
    {
        if (reverted)
        {
            revert();
            reverted = false;
        }
        return pri.top();
    }

    T front()
    {
        if (!reverted)
        {
            revert();
            reverted = true;
        }
        return sec.top();
    }

    void pop()
    {
        if (!reverted)
        {
            revert();
            reverted = true;
        }
        sec.pop();
    }

    size_t size() const
    {
        if (reverted)
            return sec.size();
        return pri.size();
    }

    bool empty() const
    {
        if (reverted)
            return sec.empty();
        return pri.empty();
    }

};

int main()
{
    queue<int> my_std_queue;
    myQueue<int> my_queue;
    for (auto [val, act] : std::initializer_list<std::pair<int, std::string>>{{1,"u"}, {2,"u"}, {3, "b"}, {4,"o"}, {5, "b"}, {6, "u"}, {7, "f"}})
    {
        if (act == "u")
        {
            my_std_queue.push(val);
            my_queue.push(val);
        }
        if (act == "o")
        {
            my_std_queue.pop();
            my_queue.pop();
        }
        if (act == "b")
        {
            cout << my_std_queue.back() << "; ";
            cout << my_queue.back() << endl;
        }
        if (act == "b")
        {
            cout << my_std_queue.front() << "; ";
            cout << my_queue.front() << endl;
        }
        if (act == "s")
        {
            cout << my_std_queue.size() << "; ";
            cout << my_queue.size() << endl;
        }
    }
    return 0;
}