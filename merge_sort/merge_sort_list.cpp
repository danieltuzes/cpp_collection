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

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list1end,
                            ListNode* list2, ListNode* list2end) {
        if (list1==list1end)
            return list2;
        if (list2==list2end)
            return list1;

        ListNode* start = list1;
        if (list1->val > list2->val)
        {
            start = list2;
            list2 = list2->next;
        }
        else
            list1 = list1->next;
        
        ListNode* ret = start;

        for (;list1 != list1end || list2 != list2end;)
        {
            if (list1 != list1end && list2 != list2end)
            {
                if (list1->val <= list2->val)
                {
                    start->next = list1;
                    start = start->next;
                    list1 = list1->next;
                }
                else
                {
                    start->next = list2;
                    start = start->next;
                    list2 = list2->next;
                }
            }
            else if (list1 != list1end)
            {
                start->next = list1;
                start = start->next;
                list1 = list1->next;
            }
            else
            {
                start->next = list2;
                start = start->next;
                list2 = list2->next;
            }
        }
        start->next = list2end;
        return ret;
    }
    ListNode* mergeSort(ListNode* list)
    {
        return mergeSortRange(list, nullptr);
    }

    ListNode* mergeSortRange(ListNode* first, ListNode* after_last)
    {
        if (first->next == after_last)
            return first;
        auto mid = midPoint(first, after_last);
        auto left = mergeSortRange(first, mid);
        auto right = mergeSortRange(mid, after_last);
        return mergeTwoLists(left, mid, right, after_last);
    }

    ListNode* midPoint(ListNode* first, ListNode* after_last)
    {
        ListNode* slow = first;
        for (; first != after_last && first->next != after_last;)
        {
            first=first->next;
            first=first->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* createLinkedList(std::initializer_list<int> list) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for (int val : list) {
            if (!head) {
                head = new ListNode(val);
                tail = head;
            } else {
                tail->next = new ListNode(val);
                tail = tail->next;
            }
        }

        return head;
    }
    void printLinkedList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
}
};

int main()
{
    Solution sol;
    auto arr = sol.createLinkedList({9,8,7,6,5,4,3,2,1});
    sol.printLinkedList(sol.mergeSort(arr));
    return 0;
}
