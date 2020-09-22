// cesun, 9/16/20 4:09 PM.

#include <vector>

using std::vector;

// suffix max query
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        vector<int> smax(prices);
        for (int i = smax.size() - 2; i >= 0; --i) {
            smax[i] = std::max(smax[i], smax[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            ans = std::max(ans, smax[i + 1] - prices[i]);
        }
        return ans;
    }
};
