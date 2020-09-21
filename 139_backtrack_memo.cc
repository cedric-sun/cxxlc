// cesun, 9/21/20 2:36 PM.

#include <string>
#include <vector>
#include <cstring>

using std::vector;
using std::string;

// backtracking with decision tree pruning
// key observation is that, once you tried every single dict word at a given position on s,
// you don't need to try that again

#define MAXN 10005

static int breakableSince[MAXN];//0=no 1=yes -1=undetermined
static const char *ss;
static int ssn;
static const string *words;
static int wn;

static inline bool prefixMatch(int begin, const string &x) {
    int i = 0;
    for (; begin < ssn && i < x.size(); ++begin, ++i) {
        if (ss[begin] != x[i])
            return false;
    }
    return i >= x.size();
}

static bool tryBreak(int begin) {
    if (begin == ssn)
        return true;
    if (breakableSince[begin] != -1)
        return static_cast<bool>(breakableSince[begin]);
    for (int i = 0; i < wn; ++i) {
        if (prefixMatch(begin, words[i]) && tryBreak(begin + words[i].size()))
            return static_cast<bool>(breakableSince[begin] = 1);
    }
    return static_cast<bool>(breakableSince[begin] = 0);
}

#include <algorithm>

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        // sort non-increasing in word length so that deeper index is memorized earlier.
        std::sort(wordDict.begin(), wordDict.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        memset(breakableSince, 0xff, sizeof(breakableSince));
        ss = s.c_str();
        ssn = s.size();
        words = wordDict.data();
        wn = wordDict.size();
        return tryBreak(0);
    }
};

#include <iostream>

int main() {
    Solution x;
    string word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> dict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    bool ans = x.wordBreak(word, dict);
    std::cout << std::boolalpha << ans << std::endl;
}
