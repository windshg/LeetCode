class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ret = 0, l = 0, h = 0, n = s.size();
        while (h < n) {
            ++ h;
            if (h < n && dict[s[h]] > dict[s[l]]) {
                ret += dict[s[h]] - dict[s[l]];
                ++ h;
                l = h;
            } else {
                ret += dict[s[l]];
                l = h;
            }
        }
        return ret;
    }
};