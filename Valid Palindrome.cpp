// straight-forward method
class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;
        int n = s.size();
        int l = 0, h = n - 1;
        while (l < h) {
            while (!valid(s[l]) && l < h) ++ l;
            while (!valid(s[h]) && l < h) -- h;
            if (lowerCase(s[l]) != lowerCase(s[h])) return false;
            ++ l;
            -- h;
        }
        return true;
    }
    
    inline bool valid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    
    inline char lowerCase(char c) {
        if (c >= 'A' && c <= 'Z') return c - ('A' - 'a');
        return c;
    }
};

// with thiry-party library <cctype>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, h = n - 1;
        while (l < h) {
            while (l < h && !isalnum(s[l])) ++ l;
            while (l < h && !isalnum(s[h])) -- h;
            if (tolower(s[l]) != tolower(s[h])) return false;
            ++l; --h;
        }
        return true;
    }
};