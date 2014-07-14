// Goodbye
class Solution {
public:
    int removeDuplicates(int a[], int n) {
        if (n < 3) return n;
        int k = 0, l = 0, h = 0;
        while (h < n) {
            while (h < n && a[h] == a[l] && h - l < 2)
                a[k++] = a[h++];
            if (h - l == 2) {
                while (h < n && a[h] == a[l]) ++ h;
            }
            l = h;
        }
        return k;
    }
};