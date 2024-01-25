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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
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

        for (;list1 || list2;)
        {
            if (list1 && list2)
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
            else if (list1)
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
        return ret;
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
    auto arr1 = sol.createLinkedList({1,2,5,8,9});
    auto arr2 = sol.createLinkedList({5,6,7});
    sol.printLinkedList(sol.mergeTwoLists(arr1, arr2));
    return 0;
}
