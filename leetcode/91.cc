#include <string>

#define MAXN 100005
static int ans[MAXN] = {1}; // in .data and create a relative large executable
static int *const bns = ans + 1;

class Solution {
public:
    int numDecodings(std::string s) {
        const char *const ss = s.c_str();
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (ss[i] == '0') {
                if (i == 0 || !(ss[i - 1] == '1' || ss[i - 1] == '2'))
                    return 0;
                else
                    bns[i] = bns[i - 2];
            } else {
                bns[i] = bns[i - 1];
                if (i!=0 &&(ss[i - 1] == '1' || (ss[i - 1] == '2' && ss[i] <= '6')))
                    bns[i] += bns[i - 2];
            }
        }
        return ans[n];
    }
};

#include <cstdio>
int main() {
    Solution x;
    printf("%d\n", x.numDecodings("12380192381047109283"));
}
