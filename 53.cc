// cesun, 9/6/20 5:07 PM.

#include <climits>
#include <algorithm>

template<typename E, typename T>
E max_subarray_sum(const T *const x, const long N) {
    E dp{}, max = std::numeric_limits<E>::min();
    for (long i = 0; i < N; ++i) {
        dp = std::max(dp + x[i], static_cast<E>(x[i]));
        max = std::max(max, dp);
    }
    return max;
}

#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(const vector<int> &nums) {
        return max_subarray_sum<long>(nums.data(), nums.size());
    }
};