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
    /*reverse the upcoming k nodes, not including bGroup, pointing to the last element within the group
    return False if there are no k nodes*/
    bool reverseNextK(ListNode *&bGroup, int k)
    {
        ListNode *back = bGroup;
        for (int i = 0; i < k; ++i)
        {
            if (back->next)
                back = back->next;
            else
                return false;
        }
        auto behind = bGroup->next;
        auto curr = behind->next;

        behind->next = back->next;
        auto new_bGroup = bGroup->next;
        bGroup->next = back;
        bGroup = new_bGroup;

        for (int i = 1; i < k; ++i)
        {
            auto ahead = curr->next;
            curr->next = behind;
            behind = curr;
            curr = ahead;
        }

        return true;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k < 2)
            return head;
        ListNode *dummyh = new ListNode;
        dummyh->next = head;
        for (ListNode *bGroup = dummyh; reverseNextK(bGroup, k);)
            ;
        return dummyh->next;
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
    arr1 = sol.reverseKGroup(arr1, 4);
    sol.printLinkedList(arr1);
    return 0;
}
