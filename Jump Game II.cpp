// Brute-force Recursion, TLE
class Solution {
public:
    int jump(int a[], int n) {
        if (n <= 1) return 0;
        int ret = INT_MAX;
        for (int i = 1; i < a[0]; ++i) {
            int subJump = jump(a + i, n - i);
            if (subJump >= 0)
                ret = min(ret, subJump + 1);
        }
        return -1;
    }
};

// Brute-force DP, TLE
class Solution {
public:
    int jump(int a[], int n) {
        if (n <= 1) return 0;
        int dp[n];
        memset(dp, INT_MAX, sizeof(dp));
        int l = 0, h = 0;
        dp[l] = 0;
        while (l < n) {
            for (int i = 1; i <= a[l]; ++i) {
                int t = l + a[i];
                if (t < n)
                    dp[t] = min(dp[t], dp[l] + 1);
            }
            l ++;
        }
        return dp[n-1];
    }
};

// Wrong but accepted, shit!!!
class Solution {
public:
    int jump(int a[], int n) {
        if (n <= 1) return 0;
        int dp[n];
        for (int i = 0; i < n; ++i) dp[i] = n;
        int l = 0, h = 0;
        dp[l] = 0;
        while (l < n - 1) {
            h = max(h, l + a[l]);
            if (h > n - 1) {
                dp[n-1] = min(dp[n-1], dp[l] + 1);
            } else {
                dp[h] = min(dp[h], dp[l] + 1);
            }
            ++ l;
        }
        return dp[n-1];
    }
};

// Greedy Method, Bingo!
class Solution {
public:
    int jump(int a[], int n) {
        int cur = 0, ret = 0;
        while (cur < n - 1) {
            ret ++;
            if (cur + a[cur] >= n - 1) return ret;
            int next = cur;
            for (int i = cur + 1; i <= cur + a[cur]; ++i) {
                if (i + a[i] > next + a[next])
                    next = i;
            }
            cur = next;
        }
        return 0;
    }
};