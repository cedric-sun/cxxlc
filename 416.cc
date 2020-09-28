// cesun, 9/27/20 3:04 AM.

#include <vector>
#include <cstring>

using std::vector;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int x:nums) sum += x;
        if (sum & 1) return false;
        const int N = sum >> 1;
        bool *dp = new bool[N + 1];
        memset(dp, 0, (N + 1) * sizeof(*dp));
        dp[0] = true;
        for (int x : nums) {
            for (int j = N; j >= x; --j) {
                dp[j] = dp[j] || dp[j - x];
            }
        }
        bool ans = dp[N];
        delete[] dp;
        return ans;
    }
};

#include <cstdio>
int main() {
    Solution x;
    vector<int> data{1, 2, 5};
    bool ans = x.canPartition(data);
    printf("%d", ans);
}
