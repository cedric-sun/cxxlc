// cesun, 9/21/20 1:26 AM.

#include <string>
#include <cctype>

using std::string;

class Solution {
public:
    int parseNRep(string::iterator &it) {
        int ans = 0;
        while (*it != '[') {
            ans = ans * 10 + (*it - '0');
            ++it;
        }
        ++it;
        return ans;
    }

    string expand(string::iterator &it) {
        string tans;
        int nRep = parseNRep(it);
        while (*it != ']') {
            if (isdigit(*it)) {
                tans.append(expand(it));
            } else {
                tans.push_back(*it);
            }
            ++it;
        }
        string ans;
        ans.reserve(nRep * tans.size());
        while (nRep--)
            ans.append(tans);
        return ans;
    }

    string decodeString(string s) {
        s = "1[" + s + "]";
        string::iterator it = s.begin();
        return expand(it);
    }
};

#include <iostream>

int main() {
    Solution x;
//    std::cout << x.decodeString("3[a]2[bc]") << std::endl;
//    std::cout << x.decodeString("3[a2[c]]") << std::endl;
    std::cout << x.decodeString("100[leetcode]") << std::endl;
}
