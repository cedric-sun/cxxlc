// cesun, 9/21/20 11:48 PM.

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> dict;
    string s;
    vector<vector<string>> trailing;
    vector<int> curStack;

    vector<string> wordBreak(string _s, vector<string> &_wordDict) {
        s = std::move(s);
        dict = std::move(_wordDict);
    }
};
