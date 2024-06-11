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

    // Function to rotate the list to the right by k places
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;

        int length = 1;
        for (auto curr = head; curr->next;)
        {
            curr = curr->next;
            length++;
        }
        k %= length;
        if (!k)
            return head;

        auto remaining = length - k;

        auto curr = head;
        for (int i = 1; i < remaining; ++i)
        {
            curr = curr->next;
        }

        auto newhead = curr->next;
        curr->next = nullptr;

        for (curr = newhead; curr->next; curr = curr->next)
            ;
        curr->next = head;

        return newhead;
    }
};

int main()
{
    Solution solution;
    vector<int> values = {1, 2};
    ListNode *list = solution.createList(values);

    // Test the rotateRight function
    int k = 2;
    ListNode *rotatedList = solution.rotateRight(list, k);

    // Print the rotated list
    ListNode *current = rotatedList;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
}
