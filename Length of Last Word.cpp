// Piece of stuff
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int l = 0, h = 0;
        while (s[h]) {
            while (s[h] && s[h] != ' ') h ++;
            if (!s[h]) break;
            int p = h;
            while (s[p] && s[p] == ' ') p ++;
            if (!s[p]) break;
            h = l = p;
        }
        return h - l;
    }
};