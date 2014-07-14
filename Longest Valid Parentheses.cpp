// not my original solution as I am shit-like.
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ret = 0, count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(count);
                count = 0;
            } else {
                if (stk.empty()) {
                    count = 0;
                } else {
                    count += stk.top() + 1;
                    stk.pop();
                }
                ret = max(ret, count);
            }
        }
        return ret * 2;
    }
};