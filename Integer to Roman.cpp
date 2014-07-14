// Stupid
class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0 || num > 3999) return "";
        static map<char, int> dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        vector<char> level = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string ret = "";
        int l = 0;
        while (num) {
            int t = num % 10;
            if (t == 0) {
                // TO DO
            } else if (t <= 3) {
                ret = string(t, level[l]) + ret;
            } else if (t <= 8) {
                int a = t - 5;
                string mid = string(1, level[l+1]);
                if (a <= 0) mid = string(-a, level[l]) + mid;
                else mid += string(a, level[l]);
                ret = mid + ret;
            } else {
                ret = string(1, level[l+2]) + ret;
                if (t == 9) ret.insert(ret.begin(), level[l]);
            }
            num /= 10;
            l += 2;
        }
        return ret;
    }
};