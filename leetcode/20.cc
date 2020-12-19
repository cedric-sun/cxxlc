// cesun, 9/16/20 7:20 AM.

#include <string>
#include <stack>

using std::string;

class Solution {
public:
    inline bool isMatch(char l, char r) {
        return (l == '{' && r == '}') || (l == '(' && r == ')') || (l == '[' && r == ']');
    }

    inline bool isOpen(char x) {
        return x == '{' || x == '(' || x == '[';
    }

    bool isValid(string s) {
        std::stack<char> stack;
        for (char x : s) {
            if (stack.empty() || isOpen(x)) {
                stack.push(x);
            } else if (isMatch(stack.top(), x)) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};