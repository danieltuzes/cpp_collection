#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

class RandomizedSet {
public:
    vector<int> randoms;
    unordered_map<int,int> lookup;
    mt19937 engine;

    RandomizedSet() {
        engine.seed(0);
    }
    
    bool insert(int val) {
        if (lookup.count(val))
            return false;
        lookup.emplace(val, randoms.size());
        randoms.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!lookup.count(val))
            return false;
        int loc = lookup[val];
        lookup.erase(val);
        randoms[loc]=randoms.back();
        randoms.pop_back();
        lookup[randoms[loc]]=loc;
        return true;
    }
    
    int getRandom() {
        int rnd = engine()%randoms.size();
        return randoms[rnd];
    }
};

int main()
{
    RandomizedSet A;
    A.insert(0);
    A.insert(1);
    A.remove(0);
    A.insert(2);
    A.remove(1);
    cout << A.getRandom();
    return 0;
}

    