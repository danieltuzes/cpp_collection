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

class Solution {
public:
    int mySqrt(int x) {
        int lo = 0;
        int hi = sqrt((2<<30))-1;
        int ret;
        for (; lo <= hi;)
        {
            int i=(hi+lo)/2;
            if (i*i <= x)
            {
                lo = i+1;
                ret = i;
            }
            else
                hi = i-1;
        }
        cout << ((int)sqrt(x) == ret);
        return ret;
    }

    int mySqrt2(int x) {
        double guess = 1;
        for (; abs(pow(guess,2)-x)>0.5;)
        {
            guess = guess - (pow(guess,2)-x)/(2*guess);
        }
        unsigned ret = (int)guess;
        if (ret*ret != x && (ret+1)*(ret+1) <=x)
            ret++;
        return (int)ret;
    }
};



int main()
{
    Solution sol;
    cout << ((int)(sqrt(2147483647)) == sol.mySqrt(2147483647));
    sol.mySqrt(4);
    sol.mySqrt(10);
    sol.mySqrt(100);
    sol.mySqrt(2);
    sol.mySqrt(1);
    
    return 0;
}
