// cesun, 9/21/20 2:45 AM.

#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

/**
 * Raw backtracking and TLE.
 */
class Solution {
public:
    bool equalAt(int i, const string &s, const string &m) {
        int j = 0;
        while (true) {
            if (i >= s.size() || j >= m.size())
                break;
            if (s[i] != m[j])
                return false;
            ++i;
            ++j;
        }
        if (j >= m.size())
            return true;
        return false;
    }

    bool tryDict(int i, const string &s, const vector<string> &dict) {
        if (i == s.size()) {
            return true;
        }
        for (const string &ent : dict) {
            if (equalAt(i, s, ent)) {
                if (tryDict(i + ent.size(), s, dict))
                    return true;
            }
        }
        return false;
    }

    bool wordBreak(const string s, vector<string> &wordDict) {
        std::sort(wordDict.begin(), wordDict.end(),
                  [](const string &a, const string &b) {
                      return a.size() > b.size();
                  });
        return tryDict(0, s, wordDict);
    }
};


#include <iostream>

int main() {
    Solution x;
    string word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> dict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    bool ans = x.wordBreak(word,dict);
    std::cout << std::boolalpha << ans << std::endl;
}
