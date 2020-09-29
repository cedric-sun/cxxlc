// cesun, 9/27/20 3:04 AM.
#include <algorithm>
#include <cstring>

#define MAX_ITEM_N 205
#define MAX_CAP 10005

static int item_n, capacity;
static int lb[MAX_ITEM_N], *items;
static bool dp[MAX_CAP + 1];

bool knapsack() {
    memset(dp, 0, (capacity + 1) * sizeof(*dp)); // capacity+1 is crucial
    dp[0] = true;
    lb[item_n - 1] = capacity;
    for (int i = item_n - 2; i >= 0; --i)
        lb[i] = lb[i + 1] - items[i + 1];
    for (int i = 0; i < item_n; ++i) {
        const int &x = items[i];
        const int lbi = std::max(lb[i], x);
        for (int j = capacity; j >= lbi; --j) {
            if (dp[j - x]) dp[j] = true;
        }
    }
    return dp[capacity];
}


// ------------
#include <vector>

using std::vector;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum;
        for (int x:nums)
            sum += x;
        if (sum & 1)
            return false;
        capacity = sum >> 1;
        item_n = nums.size();
        items = nums.data();
        return knapsack();
    }
};
