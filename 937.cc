// cesun, 9/3/20 9:28 AM.

#include <utility>
#include <vector>
#include <string>
#include <cctype>

using std::string;
using std::vector;

struct LetterLog {
    string iden, text;

    LetterLog(string iden, string text) : iden(std::move(iden)), text(std::move(text)) {}

    operator string() const {
        return iden + text;
    }
};

static bool operator<(const LetterLog &x, const LetterLog &y) {
    return x.text == y.text ? x.iden < y.iden : x.text < y.text;
}

class Solution {
public:
    vector<string> reorderLogFiles(const vector<string> &logs) {
        vector<LetterLog> l_logs;
        vector<string> sd_logs;
        l_logs.reserve(logs.size());
        sd_logs.reserve(logs.size());
        for (const string &s : logs) {
            int i_sp = s.find_first_of(' ');
            if (std::isdigit(s[i_sp + 1])) sd_logs.push_back(s);
            else l_logs.emplace_back(s.substr(0, i_sp), s.substr(i_sp));
        }
        std::sort(l_logs.begin(), l_logs.end());
        vector<string> sl_logs{l_logs.cbegin(), l_logs.cend()};
        sl_logs.insert(sl_logs.cend(),
                       std::make_move_iterator(sd_logs.cbegin()),
                       std::make_move_iterator(sd_logs.cend()));
        return sl_logs; // move constructing the return value
    }
};

int main() {
    Solution s;
    for (const string &ref : s.reorderLogFiles({"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"})) {
        printf("%s\n", ref.c_str());
    }
}
