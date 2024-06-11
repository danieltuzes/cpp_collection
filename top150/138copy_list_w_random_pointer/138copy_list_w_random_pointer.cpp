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

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = new Node(head->val);
        Node *ret = curr;

        unordered_map<Node *, int> orig;
        vector<Node *> bnew;

        orig.insert({head, 0});
        bnew.push_back(curr);

        Node *it_o = head->next;
        for (int i = 1; it_o; ++i)
        {
            curr->next = new Node(it_o->val);
            curr = curr->next;
            bnew.push_back(curr);
            orig.insert({it_o, i});
            it_o = it_o->next;
        }

        it_o = head;
        curr = ret;
        for (; it_o;)
        {
            Node *rnd = it_o->random;
            if (rnd)
                curr->random = bnew[orig[rnd]];
            it_o = it_o->next;
            curr = curr->next;
        }
        return ret;
    }

    Node *createList(const std::vector<std::vector<int>> &listData)
    {
        if (listData.empty())
            return nullptr;

        std::vector<Node *> nodes(listData.size(), nullptr);

        // First pass: Create all nodes
        for (int i = 0; i < listData.size(); ++i)
        {
            nodes[i] = new Node(listData[i][0]);
        }

        // Second pass: Set next and random pointers
        for (int i = 0; i < listData.size(); ++i)
        {
            if (i + 1 < listData.size())
            {
                nodes[i]->next = nodes[i + 1];
            }
            int randomIndex = listData[i][1];
            if (randomIndex != -1)
            { // Assuming null is represented as -1
                nodes[i]->random = nodes[randomIndex];
            }
        }

        return nodes[0];
    }

    void printList(Node *head)
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << "Node value: " << current->val;
            if (current->random != nullptr)
            {
                std::cout << ", Random points to: " << current->random->val;
            }
            else
            {
                std::cout << ", Random points to: null";
            }
            std::cout << std::endl;
            current = current->next;
        }
    }
};

int main()
{
    Solution solution;
    std::vector<std::vector<int>> listData = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};

    Node *head = solution.createList(listData);
    solution.printList(head);
    auto sol = solution.copyRandomList(head);
    solution.printList(sol);

    return 0;
}