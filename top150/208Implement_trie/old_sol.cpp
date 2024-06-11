struct TL
{
    TL **letters; // Pointer to an array of TrieNode pointers
    bool isWord;  // Flag to mark the end of a word

    TL() : isWord(false)
    {
        letters = new TL *[26]; // Allocate space for 26 pointers
        for (int i = 0; i < 26; ++i)
        {
            letters[i] = nullptr; // Initialize all pointers to nullptr
        }
    }

    ~TL()
    {
        for (int i = 0; i < 26; ++i)
        {
            delete letters[i]; // Delete all allocated child nodes
        }
        delete[] letters; // Delete the array of pointers
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TL;
    }

    void insert(string word)
    {
        TL *node = root;
        for (char &letter : word)
        {
            int index = letter - 'a';
            if (node->letters[index] == nullptr)
            {
                node->letters[index] = new TL;
            }
            node = node->letters[index];
        }
        node->isWord = true;
    }

    bool search(string word)
    {
        TL *node = root;
        for (char &letter : word)
        {
            int index = letter - 'a';
            if (node->letters[index] == nullptr)
                return false;
            node = node->letters[index];
        }
        return node->isWord;
    }

    bool startsWith(string prefix)
    {
        TL *node = root;
        for (char &letter : prefix)
        {
            int index = letter - 'a';
            if (node->letters[index] == nullptr)
                return false;
            node = node->letters[index];
        }
        return true;
    }

    TL *root;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */