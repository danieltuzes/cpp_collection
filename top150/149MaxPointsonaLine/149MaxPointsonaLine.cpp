#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
    vector<int> primes;
    vector<int> smpfy(int x, int y)
    {
        if (y == 0)
            return vector<int>{1, 0};
        if (x == 0)
            return vector<int>{0, 1};

        if (y < 0)
        {
            x *= -1;
            y *= -1;
        }
        for (int prime : primes)
        {
            if (prime > min(abs(x), abs(y)))
                break;
            while ((x % prime == 0) && (y % prime == 0))
            {
                x /= prime;
                y /= prime;
            }
        }
        return vector<int>{x, y};
    }

    vector<int> cinter(vector<int> &point1, vector<int> &point2, vector<int> &slope)
    {
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];

        // y1 - slopeDy/slopeDx * x1 =
        // = (y1 * slopeDx - slopeDy * x1) / slopeDx
        if (slope[1] == 0)
            return vector<int>{x1, 0};
        int nom = y1 * slope[1] - slope[0] * x1;
        return smpfy(nom, slope[1]);
    }

    vector<int> cslope(vector<int> &point1, vector<int> &point2)
    {
        int x1 = point1[0];
        int y1 = point1[1];
        int x2 = point2[0];
        int y2 = point2[1];

        int h = y2 - y1;
        int d = x2 - x1;

        return smpfy(h, d);
    }

public:
    Solution() : primes(1, 2)
    {
        for (int i = 3; i < 2 * 10e4; i += 2)
        {
            int lim = sqrt(i);
            bool isprime = true;
            for (int prime : primes)
            {
                if (prime > lim)
                    break;
                if (i % prime == 0)
                {
                    isprime = false;
                    break;
                }
            }
            if (isprime)
            {
                primes.push_back(i);
            }
        }
    };

    int maxPoints(vector<vector<int>> &points)
    {
        // pair<frac slope, frac intercept>, how many
        map<pair<vector<int>, vector<int>>, set<vector<int>>> lines;
        for (int i = 0; i < points.size(); ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                auto slope = cslope(points[i], points[j]);
                auto inter = cinter(points[i], points[j], slope);
                lines[make_pair<>(slope, inter)].insert(points[i]);
                lines[make_pair<>(slope, inter)].insert(points[j]);
            }
        }
        size_t maxl = 1;
        for (auto lines_counts : lines)
        {
            maxl = max(maxl, lines_counts.second.size());
        }
        return maxl;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << sol.maxPoints(points) << endl;
    cout << boolalpha << (10. / 3 == 20. / 6);
    return 0;
}