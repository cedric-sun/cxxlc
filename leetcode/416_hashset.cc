// cesun, 9/29/20 2:39 AM.

#include <vector>
#include <unordered_set>

using std::vector;
std::unordered_set<int> s;
std::vector<int> gen;
bool knapsack(const int *items, const int item_n, const int capacity) {
    s.clear();
    gen.clear();
    s.reserve(capacity); // space complexity is still there...
    gen.reserve(capacity);
    s.insert(0);
    gen.push_back(0);
    for (int i = 0; i < item_n; ++i) {
        const int genCurSize = gen.size();
        for (int j = 0; j < genCurSize; ++j) {
            const int newWeight = gen[j] + items[i]; // TODO: ensure no int overflow
            if (newWeight > capacity)
                continue;
            if (newWeight == capacity)
                return true;
            if (s.find(newWeight) == s.cend()) {
                gen.push_back(newWeight);
                s.insert(newWeight);
            }
        }
    }
    return false;
}

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum;
        for (int x:nums)
            sum += x;
        if (sum & 1)
            return false;
        return knapsack(nums.data(), nums.size(), sum >> 1);
    }
};
