class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        if (n < 1) return ret;
        int l = 0, h = 0;
        int t = nums[l];
        for (; h < l + k && h < n; h ++) {
            t = max(t, nums[h]);
        }
        ret.push_back(t);

        while (h < n) {
            if (t == nums[l]) {
                t = nums[l+1];
                for (int i = l + 1; i <= h; i++) {
                    t = max(t, nums[i]);
                }
            } else {
                t = max(t, nums[h]);
            }
            ret.push_back(t);
            l ++;
            h ++;
        }

        return ret;
    }
};
