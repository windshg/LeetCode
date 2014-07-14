// recursion, TLE
class Solution {
public:
    bool canJump(int a[], int n) {
        if (n <= 1) return true;
        for (int i = 1; i <= a[0]; ++i) {
            if (canJump(a + i, n - i)) return true;
        }
        return false;
    }
};

// O(n)
class Solution {
public:
    bool canJump(int a[], int n) {
        int l = 0, h = 0;
        while (l <= h && h < n) {
            h = max(h, l + a[l]);
            ++ l;
        }
        return h >= n - 1;
    }
};