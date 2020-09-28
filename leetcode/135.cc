// cesun, 9/21/20 4:06 PM.

/*
 * roll forward and backward; use 1 extra array for winner at peak;
 */

#include <vector>
#include <cstdio>

using std::vector;

class Solution {
public:
    int candy(const vector<int> &a) {
        if (a.size() == 1) return 1;
#define MAXN 50005
        static int v[MAXN];
        const int n = a.size();
        int cur = 1;
        for (int i = 0; i < n - 1; ++i) {
            v[i] = cur; // downhill is 1, peak is temporary winner
            if (a[i] < a[i + 1]) {
                ++cur;
            } else {
                cur = 1;
            }
        }
        v[n - 1] = a[n - 1] > a[n - 2] ? cur : 1;
        cur = 1;
        for (int i = n - 1; i > 0; --i) {
            if (a[i] < a[i - 1]) {
                v[i] = cur; // overwriting local minima to 1 but not hurt
                ++cur;
            } else {
                if (cur > v[i])
                    v[i] = cur;
                cur = 1;
            }
        }
        v[0] = a[0] > a[1] ? cur : 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += v[i];
        }
        return ans;
    }
};

int main() {
    Solution x;
    vector<int> data{1, 10000, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10000, 1};
    printf("%d\n", x.candy(data));
}
