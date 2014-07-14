// Double-Pointer Solution
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> dict, visit;
        int dcount = 0, vcount = 0;
        for (int i = 0; i < m; ++i) dict[t[i]] ++;
        int l = 0, h = 0, retStart = 0, retLen = n + 1;
        while (h < n) {
            for (; h < n && vcount < m; ++h) {
                if (dict.find(s[h]) != dict.end()) {
                    if (visit[s[h]] < dict[s[h]]) vcount ++;
                    visit[s[h]] ++;
                }
            }
            if (h == n && vcount < m) break;
            for (; l < h; ++l) {
                if (dict.find(s[l]) != dict.end()) {
                    if (visit[s[l]] <= dict[s[l]]) break;
                    visit[s[l]] --;
                }
            }
            if (h - l < retLen) {
                retStart = l;
                retLen = h - l;
            }
            visit[s[l++]] --;
            vcount --;
        }
        return s.substr(retStart, retLen > n ? 0 : retLen);
    }
};