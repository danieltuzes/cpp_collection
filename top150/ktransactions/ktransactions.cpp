#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;

        // If k is very large, convert to problem with unlimited transactions.
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        vector<vector<int>> buy(k + 1, vector<int>(n, 0));
        vector<vector<int>> sel(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            buy[i][0] = -prices[0];
            for (int j = 1; j < n; j++) {
                buy[i][j] = max(buy[i][j-1], sel[i-1][j] - prices[j]);
                sel[i][j] = max(sel[i][j-1], buy[i][j] + prices[j]);
            }
        }
        return sel[k][n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> prices = {10, 15, 5, 20, 25, 30};
    int k = 2;
    cout << "Maximum profit with " << k << " transactions: " << sol.maxProfit(k, prices) << endl;
    return 0;
}