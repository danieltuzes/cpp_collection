#include <iostream>
#include <vector>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class LRUCache
{
    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int capacity = 0;
    void moveToBegin(int key)
    {
        l.erase(m[key].second);
        l.push_front(key);
        m[key].second = l.begin();
    }
    void putSure(int key, int value)
    {
        l.push_front(key);
        m.insert(make_pair<>(key, make_pair<>(value, l.begin())));
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        moveToBegin(key);
        return m[key].first;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            m[key].first = value;
            moveToBegin(key);
            return;
        }
        if (m.size() < capacity)
        {
            putSure(key, value);
            return;
        }
        int key_to_rm = l.back();
        l.pop_back();
        m.erase(key_to_rm);
        putSure(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int capacity = 2;
    LRUCache *obj = new LRUCache(capacity);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1);
    obj->put(3, 3);
    cout << obj->get(2);
    obj->put(4, 4);
    cout << obj->get(1);
    cout << obj->get(3);
    cout << obj->get(4);
    return 0;
}