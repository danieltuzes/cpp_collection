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

struct wordl
{
    wordl *nextw[26] = {};
    bool isend;

    wordl() : isend(false){};
};

class WordDictionary
{
    wordl root;

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        wordl *curr = &root;
        for (char letter : word)
        {
            if (!curr->nextw[letter - 'a'])
            {
                curr->nextw[letter - 'a'] = new wordl;
            }
            curr = curr->nextw[letter - 'a'];
        }
        curr->isend = true;
    }

    bool search(string &word, int startpos, wordl *ownroot)
    {
        wordl *curr = ownroot;
        for (int i = startpos; i < word.size(); ++i)
        {
            char letter = word[i];
            if (letter == '.')
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (curr->nextw[j] && search(word, i + 1, curr->nextw[j]))
                        return true;
                }
                return false;
            }
            else
            {
                if (curr->nextw[letter - 'a'])
                    curr = curr->nextw[letter - 'a'];
                else
                    return false;
            }
        }
        return curr->isend;
    }

    bool search(string word)
    {
        return search(word, 0, &root);
    }
};

int main()
{
    WordDictionary trie;
    trie.addWord("bad");
    trie.addWord("dad");
    trie.addWord("mad");
    cout << trie.search("ba.");
    cout << trie.search("b.d");
    cout << trie.search("b..");
    cout << trie.search("no") << trie.search("h") << trie.search("hey") << trie.search("heyho") << trie.search("h") << trie.search("hey");
    cout << trie.search("hey.o") << trie.search("hey..") << trie.search("heyh.") << trie.search("heh.o");

    return 0;
}