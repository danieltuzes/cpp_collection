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
    ListNode *removeNthNode(ListNode *list, int n)
    {
        auto ahead = list;
        for (int i = 0; i < n; ++i, ahead = ahead->next)
        {
        }
        if (ahead == nullptr)
            return list->next;
        auto behind = list;
        for (; ahead->next != nullptr; ahead = ahead->next, behind = behind->next)
        {
        }
        behind->next = behind->next->next;
        return list;
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
    auto arr = sol.createLinkedList({9, 8, 7, 6, 5, 4, 3, 2, 1});
    sol.printLinkedList(sol.removeNthNode(arr, 9));
    return 0;
}
