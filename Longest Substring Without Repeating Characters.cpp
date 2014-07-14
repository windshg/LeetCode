// Longest Substring Without Repeating Characters 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        bool v[256] = {false};
        int l = 0, h = 0, ret = 0;
        while (h < n) {
            for (; h < n && !v[s[h]]; ++h) v[s[h]] = true;
            ret = max(ret, h - l);
            if (h == n) break;
            for (; s[l] != s[h]; ++l) v[s[l]] = false;
            ++ l;
            ++ h;
        }
        return ret;
    }
};