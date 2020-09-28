// cesun, 9/21/20 6:54 PM.

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        std::unordered_map<int, int> cnt;
        for (const int x: nums) {
            if (cnt.find(x) != cnt.cend())
                return x;
            ++cnt[x];
        }
        return 0xdeadbeef;
    }
};
