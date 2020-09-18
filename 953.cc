// cesun, 9/16/20 2:41 PM.

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int mag[128];

    // lex compare a <= b ?
    bool le(const string &a, const string &b) {
        for (int i = 0; i < a.size(); ++i) {
            if (i < b.size()) {
                if (a[i] == b[i]) continue;
                return mag[a[i]] < mag[b[i]];
            }
            return false;
        }
        return true;
    }

    bool isAlienSorted(const vector<string> &words, string order) {
        for (int i = 0; i < order.size(); ++i)
            mag[order[i]] = i;
        for (int i = 1; i < words.size(); ++i)
            if (le(words[i], words[i - 1]))
                return false;
        return true;
    }
};

int main() {
    Solution x;
    x.isAlienSorted({"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz");
}