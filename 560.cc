// cesun, 9/16/20 4:26 PM.

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

// nice hash map solution for counting subarrays that sum up to k.
// Conceptually it's okay to assume a 0-length prefix sum of 0
// at the beginning of num, so the sum==k check can be saved,
// i.e. initialize sumCnt with {{0,1}};

class Solution {
public:
    int subarraySum(const vector<int> &nums, int k) {
        unordered_map<int, int> sumCnt;
        int sum = 0, ans = 0;
        for (const int x : nums) {
            sum += x;
            if (sum == k)
                ans++;// this whole prefix is an answer
            const auto it = sumCnt.find(sum - k);
            if (it != sumCnt.cend())
                ans += it->second;
            sumCnt[sum]++; // when k==0 the position of this statement matters, don't find yourself.
        }
        return ans;
    }
};
