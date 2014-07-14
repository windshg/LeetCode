// straightforward method
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string last = countAndSay(n-1);
        string ret;
        char e = last[0];
        int i = 1, count = 1;
        while (i < last.size()) {
            if (last[i] != last[i-1]) {
                ret += count + '0';
                ret += e;
                count = 0;
                e = last[i];
            }
            ++ count;
            ++ i;
        }
        ret += count + '0';
        ret += e;
        return ret;
    }
};