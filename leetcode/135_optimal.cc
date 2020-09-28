// https://leetcode.com/problems/candy/discuss/135698/

#include <vector>

using std::vector;

class Solution {
public:
    int candy(const vector<int> &ratings) {
        if (ratings.empty()) return 0;
        int ret = 1;
        int up = 0, down = 0, peak = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                // after taking a increasing step, i'm at pos i
                peak = ++up; // accumulated up steps inc, new peak found
                down = 0;
                ret += 1 + up; // add cost for the current pos
            } else if (ratings[i - 1] == ratings[i]) {
                peak = up = down = 0;
                ret += 1;
            } else {
                up = 0;
                down++;
                ret += 1 + down + (peak >= down ? -1 : 0); // downhill reversal + lazy peak increment
            }
        }
        return ret;
    }
};

#include <cstdio>

int main() {
    Solution x;
//    printf("%d\n", x.candy({1, 2}));
    //x.candy({1, 100, 9, 8, 7, 6, 5, 6, 7, 8, 9, 100, 1});
}
