// tricky but stupid method which is able to be generalized, O(n) space, O(n) time
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int left[n], minVal = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (prices[i] < minVal) minVal = prices[i];
            left[i] = minVal;
        }
        
        int right[n], maxVal = INT_MIN;
        for (int i = n-1; i >= 0; --i) {
            if (prices[i] > maxVal) maxVal = prices[i];
            right[i] = maxVal;
        }
        
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, right[i] - left[i]);
        }
        
        return ret;
    }
};

// non-tricky but practical, O(n) time, inplace
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int ret = 0, last = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < last) last = prices[i];
            ret = max(ret, prices[i] - last);
        }
        return ret;
    }
};