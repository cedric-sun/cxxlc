// cesun, 9/21/20 2:23 AM.

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.empty()) return "";
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++) {
            char &c = s[i];
            if (c == '(')
                st.emplace(c, i);
            else if (c == ')') {
                if (st.empty()) {
                    c = '-';
                } else {
                    //st.top()=='(' should be always true here
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            s[st.top().second] = '-';
            st.pop();
        }
        string ans;
        ans.reserve(s.size());
        for (const char c : s)
            if (c != '-')
                ans.push_back(c);
        return ans;
    }
};
