// dfs non-optimized TLE crap-like
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) 
                return true;
            if (isScramble(s1.substr(n - i, i), s2.substr(0, i)) &&
                isScramble(s1.substr(0, n - i), s2.substr(i, n - i)))
                return true;
        }
        return false;
    }
    
};

// dfs optimized


// dp