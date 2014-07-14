class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int ret = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size(); ++i) {
            int l = i + 1, h = num.size() - 1;
            while (l < h) {
                int s = num[i] + num[l] + num[h];
                if (s < target) {
                    ++l;
                } else if (s > target) {
                    --h;
                } else {
                    return s;
                }
                if (abs(s - target) < abs(ret - target))
                    ret = s;
            }
        }
        return ret;
    }
    
};