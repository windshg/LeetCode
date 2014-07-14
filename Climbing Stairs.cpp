// recursion
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        return climbStairs(n - 2) + climbStairs(n - 1);
    }
};

// dp, use extra O(n) space to speed up
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int dp[n];
        dp[n-1] = 1;
        dp[n-2] = 2;
        for (int i = n - 3; i >= 0; --i)
            dp[i] = dp[i+1] + dp[i+2];
        return dp[0];
    }
};