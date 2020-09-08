// cesun, 9/5/20 8:00 PM.

#include <vector>
#include <cstdio>

using std::vector;

class Solution {
public:
    template<typename Iterator>
    int foo(const Iterator cbegin, const Iterator cend, bool tie) {
        int ans = 0, h_left = -1, vol;
        for (auto it = cbegin; it != cend; ++it) {
            //printf("%lu: %d\n", it - cbegin, *it);
            if (h_left > 0) {
                if (*it > h_left || (*it == h_left && tie)) {
                    h_left = -1;
                    ans += vol;
                } else {
                    vol += h_left - *it;
                }
            }
            if (h_left < 0 && it + 1 != cend && *it > *(it + 1)) {
                h_left = *it; // can't be 0
                vol = 0;
            }
        }
        return ans;
    }

    int trap(const vector<int> &height) {
        return foo(height.cbegin(), height.cend(), true)
               + foo(height.crbegin(), height.crend(), false);
    }
};


int main() {
    Solution x;
    int ans = x.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    printf("%d\n", ans);
}