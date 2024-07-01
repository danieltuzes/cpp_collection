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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *bhead = new ListNode;
        auto dummystart = bhead;

        bool goodnom = true;
        for (; head; head = head->next)
        {
            if (head->next && head->val == head->next->val)
            {
                goodnom = false;
                bhead->next = nullptr;
            }
            else if (goodnom)
            {
                bhead->next = head;
                bhead = bhead->next;
            }
            else
                goodnom = true;
        }

        return dummystart->next;
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
    auto mlist = sol.createLinkedList({});
    sol.printLinkedList(sol.deleteDuplicates(mlist));

    return 0;
}