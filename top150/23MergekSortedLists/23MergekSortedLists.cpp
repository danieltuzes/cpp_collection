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

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LNComp
{
public:
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
        return lhs->val > rhs->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *newHead = new ListNode();
        ListNode *curr = newHead;
        priority_queue<ListNode *, vector<ListNode *>, LNComp> nexts;
        for (auto list : lists)
        {
            if (list)
                nexts.push(list);
        }
        for (; !nexts.empty();)
        {
            auto pop = nexts.top();
            nexts.pop();
            curr->next = pop;
            curr = curr->next;
            if (pop->next)
            {
                nexts.push(pop->next);
            }
        }
        return newHead->next;
    }

    ListNode *createLinkedList(std::initializer_list<int> list)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for (int val : list)
        {
            if (!head)
            {
                head = new ListNode(val);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(val);
                tail = tail->next;
            }
        }

        return head;
    }
    void printLinkedList(ListNode *head)
    {
        while (head != nullptr)
        {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Solution sol;
    vector<ListNode *> lists = {sol.createLinkedList({1, 4, 5}),
                                sol.createLinkedList({1, 3, 4}),
                                sol.createLinkedList({2, 6})};
    auto res = sol.mergeKLists(lists);
    sol.printLinkedList(res);
    return 0;
}