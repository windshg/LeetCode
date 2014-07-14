// DP
class Solution {
public:
    int maxSubArray(int a[], int n) {
        if (n == 0) return 0;
        int ret = a[0], csum = a[0];
        for (int i = 1; i < n; ++i) {
            if (csum < 0) csum = 0;
            csum += a[i];
            ret = max(ret, csum);
        }
        return ret;
    }
};