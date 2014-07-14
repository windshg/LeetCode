// One piece of stuff
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int ret = 0, last = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[i-1]) {
                ret += prices[i-1] - last;
                last = prices[i];
            }
        }
        ret += prices[n-1] - last;
        return ret;
    }
};