// Typical combinatorics's problem

class Solution {
public:
    vector<int> getRow(int n) {
        int dp[n+1][n+1];
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        for (int j = 0; j <= n; ++j) dp[j][j] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j < i; ++j) 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        vector<int> ret(n + 1);
        for (int i = 0; i <= n; ++i)
            ret[i] = dp[n][i];
        return ret;
    }
};