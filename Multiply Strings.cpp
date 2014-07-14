// Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int a[n1+n2];
        memset(a, 0, sizeof(a));
        for(int i = n1 - 1; i >= 0; --i) {
            for(int j = n2 - 1; j >= 0; --j) {
                a[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                if(a[i+j+1] >= 10) {
                    a[i+j] += a[i+j+1] / 10;
                    a[i+j+1] = a[i+j+1] % 10;
                }
            }
        }
        string ret = "";
        for(int i = 0; i < n1 + n2; ++i) ret += a[i] + '0';
        int k = 0;
        while(ret[k] == '0') ++k;
        if(k == n1 + n2) return "0";
        return ret.substr(k, ret.size());
    }
};