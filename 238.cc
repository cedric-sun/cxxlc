// cesun, 9/16/20 12:54 PM.

#include <vector>

using std::vector;

#define MAXN 100005
static int ans[MAXN];

class Solution {
public:
    vector<int> productExceptSelf(const vector<int> &nums) {
        const int n = nums.size();
        const int *const A = nums.data();
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * A[i - 1];
        }
        int tmp = A[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            ans[i] *= tmp;
            tmp *= A[i];
        }
        return vector(ans, ans + n);
    }
};
