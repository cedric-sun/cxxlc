// cesun, 9/6/20 5:07 PM.

#include <climits>
#include <algorithm>

int max_subarray_sum(const int *const x, const int N) {
    int dp = 0, max = INT_MIN;
    for (int i = 0; i < N; ++i) {
        dp = std::max(dp + x[i], x[i]);
        max = std::max(max, dp);
    }
    return max;
}

#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(const vector<int> &nums) {
        return max_subarray_sum(nums.data(), nums.size());
    }
};