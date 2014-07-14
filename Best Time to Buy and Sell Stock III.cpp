// I guess you could figure something out since the solution here seems like the union of the two versions of solution for 'Best Time to Buy and Sell Stock' introduced above.

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        
        int left[n];
        int lMaxPft = 0, last = prices[0];
        for (int i = 0; i < n; ++i) {
            if (prices[i] < last) last = prices[i];
            lMaxPft = max(lMaxPft, prices[i] - last);
            left[i] = lMaxPft;
        }
        
        int right[n];
        int rMaxPft = 0, next = prices[n-1];
        for (int i = n-1; i >= 0; --i) {
            if (prices[i] > next) next = prices[i];
            rMaxPft = max(rMaxPft, next - prices[i]);
            right[i] = rMaxPft;
        }
        
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, right[i] + left[i]);
        }
        
        return ret;
    }
};