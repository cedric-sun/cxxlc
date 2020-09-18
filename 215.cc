// cesun, 9/17/20 7:29 PM.

// cesun, 9/17/20 8:36 AM.

namespace qselect {
    static int *arr;
    static int n;
    static int k; // find the greatest k elements

    // TODO: can we boost when interval size is small?
    // [l,r]
    // after return arr[n-k] is the k-th largest element, and arr[n-k,n-1] are
    // the k largest elements but unordered.
    void _qselect(int l, int r) {
        if (l < r) {
            int gauge = arr[(l + r) >> 1];
            int i = l - 1, j = r + 1;
            while (1) {
                while (arr[++i] < gauge);
                while (arr[--j] > gauge);
                if (i >= j) break;
                int tmp = arr[i];
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

    void qselect(int *_arr, int _n, int _k) {
        arr = _arr;
        n = _n;
        k = _k;
        _qselect(0, n - 1);
    }
}


//test: https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <vector>

using std::vector;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        qselect::qselect(nums.data(), nums.size(), k);
        return nums[nums.size() - k];
    }
};

