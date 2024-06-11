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

// Definition for singly-linked list.
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
    // Function to create a linked list from a vector of values
    ListNode *createList(const vector<int> &values)
    {
        if (values.empty())
            return nullptr;

        ListNode *head = new ListNode(values[0]);
        ListNode *current = head;
        for (size_t i = 1; i < values.size(); ++i)
        {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;

        ListNode *end_part_bhead = new ListNode(0);
        ListNode *end_part_curr = nullptr;

        ListNode *bhead = new ListNode(0, head);
        auto curr = bhead;

        for (; curr->next;)
        {
            if (curr->next->val < x)
            {
                curr = curr->next;
                continue;
            }

            if (!end_part_curr)
            {
                end_part_bhead->next = curr->next;
                end_part_curr = end_part_bhead->next;
            }
            else
            {
                end_part_curr->next = curr->next;
                end_part_curr = end_part_curr->next;
            }
            curr->next = curr->next->next;
        }
        curr->next = end_part_bhead->next;
        if (end_part_curr)
            end_part_curr->next = nullptr;
        return bhead->next;
    }
};

int main()
{
    Solution solution;
    vector<int> values = {1, 1};
    ListNode *list = solution.createList(values);

    // Test the rotateRight function
    int k = 3;
    ListNode *partedList = solution.partition(list, k);

    // Print the rotated list
    ListNode *current = partedList;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
}
