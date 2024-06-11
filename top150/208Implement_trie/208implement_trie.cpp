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

/*
struct link
{
    link *next[26] = {};
    bool val;
};

class Trie
{
private:
    link *root;

public:
    Trie() { root = new link; }

    void insert(string word)
    {
        link *curr = root;
        for (char letter : word)
        {
            if (!curr->next[letter - 'a'])
            {
                curr->next[letter - 'a'] = new link;
                curr->next[letter - 'a']->val = false;
            }
            curr = curr->next[letter - 'a'];
        }
        curr->val = true;
    }

    bool search(string word)
    {
        link *curr = root;
        for (char letter : word)
        {
            if (curr->next[letter - 'a'])
            {
                curr = curr->next[letter - 'a'];
                continue;
            }
            return false;
        }
        return curr->val;
    }

    bool startsWith(string prefix)
    {
        link *curr = root;
        for (char letter : prefix)
        {
            if (curr->next[letter - 'a'])
            {
                curr = curr->next[letter - 'a'];
                continue;
            }
            return false;
        }
        return true;
    }
};
*/

struct vletter
{
    unordered_map<char, vletter *> mynext;
    bool isend;

    vletter() : isend(false) {}
};

class Trie
{
private:
    vletter root;

public:
    Trie(){};
    void insert(string word)
    {
        vletter *current = &root;
        for (char letter : word)
        {
            if (current->mynext.find(letter) == current->mynext.end())
            {
                current->mynext[letter] = new vletter;
            }
            current = current->mynext[letter];
        }
        current->isend = true;
    }

    bool search(string word)
    {
        vletter *current = &root;
        for (char letter : word)
        {
            if (current->mynext.find(letter) == current->mynext.end())
            {
                return false;
            }
            current = current->mynext[letter];
        }
        return current->isend;
    }

    bool startsWith(string prefix)
    {
        vletter *current = &root;
        for (char letter : prefix)
        {
            if (current->mynext.find(letter) == current->mynext.end())
            {
                return false;
            }
            current = current->mynext[letter];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("hey");
    trie.insert("heyhi");
    trie.insert("sep");
    cout << trie.search("no") << trie.search("h") << trie.search("hey") << trie.search("heyho") << trie.startsWith("h") << trie.startsWith("hey");

    return 0;
}