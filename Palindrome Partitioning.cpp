// Palindrome Partitioning
// DFS, kind of brute-force
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> tmp;
        helper(s, 0, tmp, ret);
        return ret;
    }
    
    void helper(string s, int beg, vector<string> tmp, vector<vector<string>> &ret) {
        if(beg == s.size()) ret.push_back(tmp);
        for(int i = beg; i < s.size(); ++i) {
            string t = s.substr(beg, i-beg+1);
            if(palindrome(t)) {
                tmp.push_back(t);
                helper(s, i+1, tmp, ret);
                tmp.pop_back();
            }
        }
    }
    
    bool palindrome(string s) {
        for(int i = 0; i <= s.size()/2; ++i) {
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
};

// also brute-force
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s == "") ret.push_back(vector<string>());
        int l = 0, h = 0;
        while (h < s.size()) {
            if (isPalindrome(s, l, h)) {
                string head = s.substr(l, h - l + 1);
                vector<vector<string>> subret = partition(s.substr(h + 1, s.size() - h - 1));
                for (int i = 0; i < subret.size(); ++i) {
                    subret[i].insert(subret[i].begin(), head);
                    ret.push_back(subret[i]);
                }
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