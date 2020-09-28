// cesun, 9/21/20 7:51 PM.

#include <vector>
#include <unordered_map>
#include <climits>

using std::vector;

/*
 * find a subarray of the shortest length that sum up to `r = total_sum % p`
 * (or any `k*p + r` for integer k>=0)
 */

class Solution {
public:
    int minSubarray(const vector<int> &nums, int p) {
        std::unordered_map<int, int> prefixSumLastOccur{{0, -1}};
        prefixSumLastOccur.reserve(nums.size());
        int r = 0;
        for (const int x:nums) // using property: (a+b)%p = (a%p + b)%p
            r = (r + x) % p;
        if (r == 0) return 0;
        // safe guard: the following loop requires r>0; consider nums=[1,2,3] p=3
        int sum = 0, ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % p;
            // notice the possibility sum < r
            const auto it = prefixSumLastOccur.find((sum - r + p) % p);
            if (it != prefixSumLastOccur.cend()) {
                ans = std::min(ans, i - (it->second));
            }
            // greedy is fine: overwrite with new index always provides shorter interval
            prefixSumLastOccur[sum] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};
