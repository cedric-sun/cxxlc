// cesun, 9/17/20 10:02 AM.

namespace qselect {
#define MAXN 50005
    struct FreqValue {
        int freq, value;
    };
    static FreqValue arr[MAXN];

    static int n;
    static int k; // find the greatest k elements

    // TODO: can we boost when interval size is small?
    // [l,r]
    // after return arr[n-k] is the k-th largest element, and arr[n-k,n-1] are
    // the k largest elements but unordered.
    void _qselect(int l, int r) {
        if (l < r) {
            int gauge = arr[(l + r) >> 1].freq;
            int i = l - 1, j = r + 1;
            while (1) {
                while (arr[++i].freq < gauge);
                while (arr[--j].freq > gauge);
                if (i >= j) break;
                FreqValue tmp = arr[i];
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
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        std::unordered_map<int, int> freqCnt;
        for (int x : nums) freqCnt[x]++;
        int n = 0;
        for (const auto &[k, v] : freqCnt)
            qselect::arr[n++] = {v, k};
        qselect::n = n;
        qselect::k = k;
        qselect::_qselect(0, n - 1);
        vector<int> ans;
        ans.reserve(k + 20);
        for (int i = n - k; i < n; ++i) {
            ans.push_back(qselect::arr[i].value);
        }
        return ans;
    }
};
