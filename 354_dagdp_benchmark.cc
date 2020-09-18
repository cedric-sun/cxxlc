// cesun, 9/18/20 2:54 PM.

/**
 * A TLE Solution.
 *
 * Built a DAG and run non-source longest path DP
 *
 * for Envelope count = 4573, on my Intel i7-4720HQ and GCC 10
 *      with -fsanitize=address and no optimization takes  1.8 to 2 second
 *      with no sanitize and no optimization takes about 1.10 second
 *      with no sanitize and -O2 optimization takes about 0.22 to 0.33 second
 */
#include <vector>

using std::vector;

#define MAXN 50005

static vector<int> G[MAXN];
static int d[MAXN];

int dp(int i) {
    int &ans = d[i];
    if (ans > 0) return ans;
    ans = 1;
    for (const int j: G[i]) {
        ans = std::max(ans, dp(j) + 1);
    }
    return ans;
}

// ---------------
#include <cstring>

class Solution {
public:
    int maxEnvelopes(const vector<vector<int>> &envelopes) {
        if (envelopes.empty()) return 0;
        for (int i = 0; i < envelopes.size(); ++i)
            G[i].clear();
        // carefult that vector::size() returns a unsigned number, and when it returns 0,
        // unsigned 0 - 1 = SIZE_T_MAX = 18446744073709551615UL
        for (int i = 0; i < envelopes.size() - 1; ++i) {
            for (int j = 1; j < envelopes.size(); ++j) {
                if (envelopes[i][0] < envelopes[j][0] && envelopes[i][1] < envelopes[j][1]) {
                    G[j].push_back(i); // j contains i
                } else if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    G[i].push_back(j); // i contains j
                }
            }
        }
        memset(d, 0, sizeof(*d) * envelopes.size());
        int max = 0;
        for (int i = 0; i < envelopes.size(); ++i)
            max = std::max(max, dp(i));
        return max;
    }
};

#include <cstdio>
#include <stdio_ext.h>
#include <chrono>

int main() {
    __fsetlocking(stdin, FSETLOCKING_BYCALLER);
    FILE *f = fopen("datagen/dataxx", "r");
    if (f== nullptr) {
        printf("oops");
        return -1;
    }
    vector<vector<int>> tst;
    int a, b;
    while (~fscanf(f, "%d %d", &a, &b)) {
        tst.push_back({a, b});
    }
    Solution x;
    // ---
    auto t0 = std::chrono::high_resolution_clock::now();
    int ans = x.maxEnvelopes(tst);
    auto t1 = std::chrono::high_resolution_clock::now();
    //---
    long duration = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    printf("%f seconds. and = %d\n", duration / 1000000.0, ans);
    fclose(f);
}