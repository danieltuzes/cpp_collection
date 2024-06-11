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
    string word = "";
    Node *next[26] = {};
    Node *&at(char letter)
    {
        int index = letter - 'a';
        if (index < 0 || index >= 26)
        {
            throw std::out_of_range("Letter out of valid range");
        }
        return next[index];
    }
};

/*
class Solution2
{
    Node *trie;
    void insertWord(string word)
    {
        auto curr = trie;
        for (int i = 0; i < word.size(); ++i)
        {
            auto letter = word[i];
            if (!curr->at(letter))
                curr->at(letter) = new Node;
            curr = curr->at(letter);
        }
        curr->isend = true;
    }
    pair<bool, bool> status(vector<char> &word) // has word, isend
    {
        auto curr = trie;
        for (int i = 0; i < word.size(); ++i)
        {
            auto letter = word[i];
            if (!curr->at(letter))
                return make_pair(false, false);
            curr = curr->at(letter);
        }
        bool isend = curr->isend;
        if (isend)
            curr->isend = false;
        return make_pair(true, isend);
    }

    void hasNext(int i, int j, vector<char> &curr, vector<vector<char>> &board, vector<string> &matchedWords)
    {
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] == '0')
            return;
        curr.push_back(board[i][j]);
        board[i][j] = '0';
        auto thisstatus = status(curr);
        if (!thisstatus.first)
        {
            board[i][j] = curr.back();
            curr.pop_back();
            return;
        }
        if (thisstatus.second)
        {
            string foundWord(curr.begin(), curr.end());
            matchedWords.push_back(foundWord);
        }
        hasNext(i + 1, j, curr, board, matchedWords);
        hasNext(i, j + 1, curr, board, matchedWords);
        hasNext(i - 1, j, curr, board, matchedWords);
        hasNext(i, j - 1, curr, board, matchedWords);

        board[i][j] = curr.back();
        curr.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        trie = new Node;
        for (auto word : words)
        {
            insertWord(word);
        }
        vector<string> matchedWords;
        for (int i = 0; i < board.size(); ++i)
        {
            vector<char> curr;
            for (int j = 0; j < board[0].size(); ++j)
            {
                hasNext(i, j, curr, board, matchedWords);
            }
        }
        return matchedWords;
    }
};
*/

class Solution
{
    Node *trie;
    void insertWord(string word)
    {
        auto curr = trie;
        for (int i = 0; i < word.size(); ++i)
        {
            auto letter = word[i];
            if (!curr->at(letter))
                curr->at(letter) = new Node;
            curr = curr->at(letter);
        }
        curr->word = word;
    }

    void hasNext(int i, int j, Node *root, vector<vector<char>> &board, vector<string> &matchedWords)
    {
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] == '0')
            return;

        auto letter = board[i][j];
        auto child = root->at(letter);
        if (!child)
            return;

        board[i][j] = '0';
        auto matchedWord = child->word;
        if (matchedWord != "")
        {
            matchedWords.push_back(matchedWord);
            child->word = "";
        }

        hasNext(i + 1, j, child, board, matchedWords);
        hasNext(i, j + 1, child, board, matchedWords);
        hasNext(i - 1, j, child, board, matchedWords);
        hasNext(i, j - 1, child, board, matchedWords);

        board[i][j] = letter;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        trie = new Node;
        for (auto word : words)
        {
            insertWord(word);
        }
        vector<string> matchedWords;
        for (int i = 0; i < board.size(); ++i)
        {
            vector<char> curr;
            for (int j = 0; j < board[0].size(); ++j)
            {
                hasNext(i, j, trie, board, matchedWords);
            }
        }
        return matchedWords;
    }
};

int main()
{
    vector<string> words{"a"};
    vector<vector<char>> board{{'a'}, {'a'}};
    Solution sol;

    for (auto word : sol.findWords(board, words))
        cout << word;
    return 0;
}