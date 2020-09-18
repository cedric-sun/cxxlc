// cesun, 9/17/20 10:02 AM.

// cesun, 9/17/20 8:36 AM.

namespace qselect {
#define MAXN 10005
    struct Point {
        int x, y, sqed;
    };
    static Point arr[MAXN];
    static int n;
    static int k; // find the greatest k elements

    // TODO: can we boost when interval size is small?
    // [l,r]
    // after return arr[n-k] is the k-th largest element, and arr[n-k,n-1] are
    // the k largest elements but unordered.
    void _qselect(int l, int r) {
        if (l < r) {
            int gauge = arr[(l + r) >> 1].sqed;
            int i = l - 1, j = r + 1;
            while (1) {
                // 逆符「天下転覆」
                // NOTICE: REVERSING THE NORMAL GREATER/LESS COMPARISON TO DO NON-ASCENDING HOARE
                while (arr[++i].sqed > gauge);
                while (arr[--j].sqed < gauge);
                if (i >= j) break;
                Point tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            const int rsize = n - j - 1;
            if (rsize < k) {
                _qselect(l, j);
            } else if (rsize >= k) {
                // equal here is critical: even right size is exactly k, we still need to finish our job
                _qselect(j + 1, r);
            }
        }
    }
}

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        int n = 0;
        for (const vector<int> &p : points) {
            qselect::arr[n++] = {p[0], p[1], p[0] * p[0] + p[1] * p[1]};
        }
        qselect::n = n;
        qselect::k = K;
        qselect::_qselect(0, n - 1);
        vector<vector<int>> ans;
        for (int i = n - K; i < n; ++i) {
            ans.push_back({qselect::arr[i].x, qselect::arr[i].y});
        }
        return ans;
    }
};
