// cesun, 9/29/20 11:13 PM.
#include <algorithm>
#include <cstring>

static int item_n, capacity;
static int *dp, *items;

int unbounded_knapsack() {
    memset(dp, 0, (capacity + 1) * sizeof(*dp)); // capacity+1 is crucial
    for (int i = 0; i < item_n; ++i) {
        const int &x = items[i];
        for (int j = x; j <= capacity; ++j) {
            dp[j] = std::max(dp[j], x + dp[j - x]);
        }
        if (dp[capacity] == capacity) return capacity; // a further optimization but only work for subset sum knapsack
    }
    return dp[capacity];
}
//---------------------
#include <vector>

using std::vector;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        item_n = coins.size();
        items = coins.data();
        capacity = amount;
        int ans = unbounded_knapsack();
        if (ans ==0)
    }
};
