class Solution {
public:
    void reverseWords(string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        if (s.size() <= 1) return;
        string::iterator lit = s.begin();
        string::iterator hit = s.begin();
        while (hit != s.end()) {
            while (*hit != ' ' && hit != s.end()) hit ++;
            if (hit == s.end()) break;
            reverse(lit, hit);
            lit = hit;
            while (*hit == ' ' && hit != s.end()) hit ++;
            lit = s.erase(lit + 1, hit);
            hit = lit;
        }
        reverse(lit, hit);
        reverse(s.begin(), s.end());
    }
};
