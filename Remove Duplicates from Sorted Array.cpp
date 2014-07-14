// brainless solution, TLE
class Solution {
public:
    int removeDuplicates(int a[], int n) {
        if (n < 2) return n;
        int l = 0, h = l + 1;
        while (h < n) {
            while (a[h] == a[l]) ++ h;
            if (h > l + 1) {
                int del = h - l - 1;
                for (int i = h; i < n; ++i) {
                    a[i - del] = a[i];
                } 
                n -= del;
            }
            l += 1;
            h = l + 1;
        }
        return n;
    }
};

// 