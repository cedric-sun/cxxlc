// cesun, 9/16/20 4:26 PM.

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

// nice hash map solution for counting subarrays that sum up to k
class Solution {
public:
    int subarraySum(const vector<int> &nums, int k) {
        unordered_map<int, int> sumCnt;
        int sum = 0, ans = 0;
        for (const int x : nums) {
            sum += x;
            if (sum == k)
                ans++;
            const auto it = sumCnt.find(sum - k);
            if (it != sumCnt.cend())
                ans += it->second;
            sumCnt[sum]++;
        }
        return ans;
    }
};
