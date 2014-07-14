// Trapping Rain Water

class Solution {
public:
    int trap(int a[], int n) {
        if (n < 3) return 0;
        int l = 0, h = n - 1;
        int water = 0;
        while (l < h) {
            if (a[l] < a[h]) {
                int al = a[l];
                while (a[++l] <= al && l < h) water += al - a[l];
            } else {
                int ah = a[h];
                while (a[--h] <= ah && l < h) water += ah - a[h];
            }
        }
        return water;
    }
};

// 2D version, trapping rain water in matrix
