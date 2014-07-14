// Nothing. That's all!
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        if (digits.size() == 0) {ret.push_back(""); return ret;}
        for (int i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '0' - 2;
            if (ret.size() == 0) {
                for (int k = 0; k < map[num].size(); ++k) 
                    ret.push_back(string(1, map[num][k]));
                continue;
            }
            int n = ret.size();
            for (int j = 0; j < n; ++j) {
                string tmp = ret[j];
                for (int k = 0; k < map[num].size(); ++k)
                    ret.push_back(tmp + string(1, map[num][k]));
            }
            ret.erase(ret.begin(), ret.begin() + n);
        }
        return ret;
    }
};