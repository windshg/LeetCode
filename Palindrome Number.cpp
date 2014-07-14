// non-tricky solution with O(1) space
class Solution {
public:
    bool isPalindrome(int x) {
        bool neg = false;
        if (x < 0) {neg = true; x *= -1;}
        int w = 0, t = x;
        while (t) {
            w *= 10;
            w += t % 10;
            t /= 10;
        }
        if (w == x && !neg) return true;
        return false;
    }
};