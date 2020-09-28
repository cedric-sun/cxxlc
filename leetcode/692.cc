// cesun, 9/17/20 8:18 PM.


// cesun, 9/17/20 10:02 AM.

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        std::unordered_map<string, int> freqCnt;
        for (const string &x  : words) freqCnt[x]++;
        using StringFreq = std::pair<string, int>;
        auto compFunc = [](const StringFreq &a, const StringFreq &b) {
#define value first
#define freq second
            return a.freq == b.freq ? a.value > b.value : a.freq < b.freq;
        };
        std::priority_queue<StringFreq, vector<StringFreq>, decltype(compFunc)>
                pq{std::make_move_iterator(freqCnt.begin()),
                   std::make_move_iterator(freqCnt.end()),
                   compFunc};
        vector<string> ans;
        ans.reserve(k + 20);
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().value);
            pq.pop();
        }
        return ans;
    }
};
