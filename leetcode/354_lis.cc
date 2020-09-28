// cesun, 9/19/20 9:25 PM.

/*
 * template lis
 * Need < to be defined.
 */

template<typename T>
struct lis {
    // [0,r)
    static inline int lower_bound(const T *const a, const int *const d, int r, const T &key) {
        int l = 0;
        while (l < r) {
            int m = (l + r) >> 1; // or l+((n-l)>>1)
            if (a[d[m]] < key) l = m + 1;
            else r = m;
        }
        return l;
    }

    //precond: n>0
    static int work(const T *const a, const int n) {
        int *d = new int[n]; // a[d[i]] is the value of tail of lis of size i+1
        d[0] = 0; // init: lis of size 1 end at a[0]
        int dsz = 1;
        for (int i = 1; i < n; ++i) {
            int j = lower_bound(a, d, dsz, a[i]);
            if (j == dsz) dsz++;
            d[j] = i;
        }
        delete[] d;
        return dsz;
    }
};

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        if (envelopes.empty()) return 0;
        std::sort(envelopes.begin(), envelopes.end(), [](const auto &va, const auto &vb) {
            // ascending in width; if width is equal, descending in height
            return va[0] == vb[0] ? va[1] > vb[1] : va[0] < vb[0];
        });
        int *hs = new int[envelopes.size()];
        for (int i = 0; i < envelopes.size(); ++i) {
            hs[i] = envelopes[i][1];
        }
        int ans = lis<int>::work(hs, envelopes.size());
        delete[] hs;
        return ans;
    }
};
