
class Solution {
public:
    void reverseWords(string &s) {
        ltrim(rtrim(s));
        if (s.size() <= 1) return;
        
        string::iterator lit = s.begin();
        while (lit != s.end()) {
            string::iterator hit = lit;
            while (hit != s.end() && *hit != ' ') hit ++;
            reverse(s, lit - s.begin(), hit - s.begin() - 1);
            if (hit == s.end()) break;
            lit = hit;
            while (hit != s.end() && *hit == ' ') hit ++;
            lit = s.erase(lit, hit - 1);
            lit ++;
        }
        
        reverse(s, 0, s.size() - 1);
    }
    
    void reverse(string &s, int start, int end) {
        int mid = (start + end) / 2;
        for (int i = start; i <= mid; ++i) {
            swap(s[i], s[end - i + start]);
        }
    }
    
    // trim from start
    inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }
    
    // trim from end
    inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }   
};