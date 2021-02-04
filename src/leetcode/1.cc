#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    unordered_map<int, int> x;

    vector<int> twoSum(vector<int> &nums, int target) {
        x.clear();
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int v = nums[i];
            //if (x.contains(nums[i]))// since c++20
            if (x.find(v) == x.cend())// pre c++20 membership query
                x[target - v] = i;
            else
                return {i, x[v]};
        }
        return {};
    }
};
