// cesun, 9/28/20 8:56 PM.

#include <iostream>

auto speedup = []() {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


#include <algorithm>
#include <cstring>

#define MAX_ITEM_N 1005
#define MAX_CAP 1005

static int item_n, capacity;
static int dp[MAX_CAP + 1], lb[MAX_ITEM_N], items[MAX_ITEM_N];

int knapsack() {
    memset(dp, 0, (capacity + 1) * sizeof(*dp)); // capacity+1 is crucial
    lb[item_n - 1] = capacity;
    for (int i = item_n - 2; i >= 0; --i)
        lb[i] = lb[i + 1] - items[i + 1];
    for (int i = 0; i < item_n; ++i) {
        const int &x = items[i];
        const int lbi = std::max(lb[i], x);
        for (int j = capacity; j >= lbi; --j) {
            dp[j] = std::max(dp[j], x + dp[j - x]);
        }
    }
    return dp[capacity];
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", items + i);
        }
        int m;
        scanf("%d", &m);
        if (m < 5) {
            printf("%d\n", m);
            continue;
        }
        if (n == 1) {
            printf("%d\n", m - items[0]);
            continue;
        }
        std::sort(items, items + n);
        // set up knapsack
        item_n = n - 1;
        capacity = m - 5;
        int ans = knapsack();
        printf("%d\n", m - ans - items[n - 1]);
    }
}
