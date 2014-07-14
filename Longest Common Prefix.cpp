class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s = "";
        int cur = 0;
        while (true) {
            int n = 0;
            for (int i = 0; i < strs.size(); ++i, ++n) {
                if (cur == strs[i].size()) break;
                if (n == 0) {
                    s.push_back(strs[i][cur]);
                } else {
                    if (strs[i][cur] != s.back()) break;
                }
            }
            if (n == 0) return s;
            if (n < strs.size()) return s.substr(0, s.size() - 1);
            ++ cur;
        }
        return s;
    }
};