// cesun, 9/16/20 2:07 PM.

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return {};
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        vector<vector<int>> ans;
        int curBegin = intervals[0][0], curEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > curEnd) {
                ans.push_back({curBegin, curEnd});
                curBegin = intervals[i][0];
                curEnd = intervals[i][1];
            } else {
                curEnd = std::max(curEnd, intervals[i][1]);
            }
        }
        ans.push_back({curBegin, curEnd});
        return ans;
    }
};

#include <cstdio>

int main() {
    Solution x;
    vector<vector<int>> test{{1, 2},
                             {2, 3}};
    for (const vector<int> &ref : x.merge(test)) {
        printf("%d %d\n", ref[0], ref[1]);
    }
}
