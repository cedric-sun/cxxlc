// cesun, 9/21/20 7:09 PM.

#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unsigned ans = 0;
        for (const unsigned x:nums)
            ans = ans ^ x;
        return static_cast<int>(ans);
    }
};
