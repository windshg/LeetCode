class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        char *p1 = haystack;
        while (*p1) {
            if (*p1 == *needle) {
                char *tp1 = p1;
                char *tp2 = needle;
                while (*tp1 && *tp2 && (*tp2) == (*tp1)) {
                    tp1 ++;
                    tp2 ++;
                }
                if (!(*tp2)) return p1;
            }
            p1 ++;
        }
        return NULL;
    }
};

