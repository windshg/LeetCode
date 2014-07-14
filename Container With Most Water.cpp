// Version with brute-force, TLE obviously.
class Solution {
public:
    int maxArea(vector<int> &a) {
        int ret = 0;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                ret = max(ret, min(a[i], a[j]) * (i - j));
            }
        }
        return ret;
    }
};

// Version with O(n) time
// Two-pointers way, which easily cross your mind.
class Solution {
public:
    int maxArea(vector<int> &a) {
        int ret = 0, l = 0, h = a.size() - 1;
        while (l < h) {
            ret = max(ret, min(a[l], a[h]) * (h - l));
            if (a[l] < a[h]) {
                int t = a[l];
                while (a[++l] < t);
            } else {
                int t = a[h];
                while (a[--h] < t);
            }
        }
        return ret;
    }
};