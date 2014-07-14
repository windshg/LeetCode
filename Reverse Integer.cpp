class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = abs(x);
        }
        int ret = 0;
        while (x) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret * sign;
    }
};