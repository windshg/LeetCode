// Palindrome Partitioning

// 1. Very stupid, Brute Force, TLE......shit
class Solution {
public:
    int minCut(string s) {
        int ret = INT_MAX;
        helper(s, 0, 0, ret);
        return ret;
    }
    
    void helper(string &s, int beg, int n, int &ret) {
        if(beg == s.size()) ret = min(ret, n-1);
        for(int i = beg; i < s.size(); ++i) {
            if(palindrome(s.substr(beg, i-beg+1))) {
                n++;
                helper(s, i+1, n, ret);
                n--;
            }
        }
    }
    
    bool palindrome(string s) {
        for(int i = 0; i <= s.size()/2; ++i)
            if(s[i] != s[s.size()-i-1]) return false;
        return true;
    }
};

// DFS, TLE
class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1) return 0;
        int h = 0, ret = INT_MAX;
        while (h < s.size()) {
            if (isPalindrome(s, 0, h)) {
                int subMinCut = minCut(s.substr(h + 1, s.size() - h - 1));
                ret = min(ret, subMinCut + 1);
            }
            ++ h;
        }
        return ret;
    }
    
    bool isPalindrome(string &s, int l, int h) {
        int m = (l + h) / 2;
        for (int i = l; i <= m; ++i) {
            if (s[i] != s[h-i+l]) return false; 
        }
        return true;
    }
};

// 2. WA becase it did not be able to return the optimal result, and we know that there is always not realistic to get the optimal result in real scene.
// Stupid though, it did make a breakthrough in solving the TLE problem... 

class Solution {
public:
    int minCut(string s) {
        int sum = 0;

        int n = s.size();
        int i = 0, j = n - 1;
        while(i <= j && i < n && j < n) {
            if(s[i] == s[j]) {
                int k = i, l = j;
                while(k <= l && s[k++] == s[l--]);
                if(k - l > 0 && s[k-1] == s[l+1]) { 
                    i = j+1;
                    j = n-1;
                    ++sum;
                } else {
                    --j;
                }
            }
            else --j;
        }
        
        return sum == 0 ? n-1 : sum-1;
    }
};

// brute-forcing dp without trick, TLE
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n < 2) return 0;
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) {
                if (isPalindrome(s, j, i)) {
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[n-1];
    }
    
    inline bool isPalindrome(string &s, int l, int h) {
        int m = (l + h) / 2;
        for (int i = l; i <= m; ++i) {
            if (s[i] != s[h-i+l]) return false; 
        }
        return true;
    }
};


// Best solution by now.
// Contributed by 孙冕 & AnnieKim (https://github.com/AnnieKim/LeetCode/blob/master/PalindromePartitioningII.h)
// Awesome trick that records the status whether previous window is a palindrome which is the biggest inner encapsulated window of current window being visited.
// isP[j] => whether s[j..i] is palindrome
// isP[j+1] => whether s[j+1..i-1] is palindrome
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n < 2) return 0;
        int dp[n];
        dp[0] = 0;
        bool isP[n];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + 1;
            isP[i] = true;
            for (int j = 0; j < i; ++j) {
                isP[j] = (s[j] == s[i]) ? isP[j+1] : false;
                if (isP[j])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);
            }
        }
        return dp[n-1];
    }
};

