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

class Solution2
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *start_dummy = new ListNode;
        start_dummy->next = head;

        auto curr_front = start_dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            curr_front = curr_front->next;
        }
        auto curr_back = curr_front;

        for (int i = left; i <= right + 1; ++i)
        {
            curr_back = curr_back->next;
        }

        auto curr_behin = curr_front->next;

        for (int i = left; i <= right; ++i)
        {
            auto curr_ahead = curr_behin->next;
            curr_behin->next = curr_back;
            curr_back = curr_behin;
            curr_behin = curr_ahead;
        }

        curr_front->next = curr_back;
        return start_dummy->next;
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

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *start_dumm = new ListNode;
        start_dumm->next = head;

        auto curr_front = start_dumm;
        for (int i = 0; i < left - 1; ++i)
        {
            curr_front = curr_front->next;
        }

        auto curr_behin = curr_front->next;
        auto curr = curr_behin->next;

        auto backlink = curr_behin;

        for (int i = left; i < right; ++i)
        {
            auto curr_ahead = curr->next;
            curr->next = curr_behin;
            curr_behin = curr;
            curr = curr_ahead;
        }
        backlink->next = curr;
        curr_front->next = curr_behin;
        return start_dumm->next;
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
    auto arr1 = sol.createLinkedList({1, 2, 3, 4, 5});
    sol.reverseBetween(arr1, 2, 5);
    return 0;
}
