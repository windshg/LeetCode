// O(n) + O(n * log n)
class Solution {
public:
    int search(int a[], int n, int target) {
        if (n == 0) return -1;
        if (n == 1) return a[0] == target ? 0 : -1;
        int m;
        for (m = 1; m < n && a[m] > a[m-1]; ++m);
        if (m == n) return binarySearch(a, 0, n - 1, target);
        if (target <= a[m-1] && target >= a[0])
            return binarySearch(a, 0, m - 1, target);
        return binarySearch(a, m, n - 1, target);
    }
    
    int binarySearch(int a[], int l, int h, int target) {
        if (l > h) return -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (a[m] < target) {
                l = m + 1;
            } else if (a[m] > target) {
                h = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};