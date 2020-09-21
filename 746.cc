// cesun, 9/20/20 11:33 AM.

#include <vector>

using std::vector;

/**
 * dp       | 0 | 0 | ? | ? | ...
 *            |   |   |
 *            v   v   v
 * cost       | a | b | c |
 */
class Solution {
public:
    int minCostClimbingStairs(const vector<int> &cost) {
        vector<int> minCost{0, 0};
        minCost.resize(cost.size() + 1);
        for (int i = 2; i < minCost.size(); ++i) {
            minCost[i] = std::min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        }
        return minCost.back();
    }
};

#include <cstdio>

int main() {
    Solution x;
    int ans = x.minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
    printf("%d\n", ans);
}