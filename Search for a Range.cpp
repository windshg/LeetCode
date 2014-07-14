// Search for a Range

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, h = n-1, m = 0;
        vector<int> ret;
        while(l <= h) {
            m = l + (h - l) / 2;
            if(A[m] < target) {
                l = m + 1;
            } else if(A[m] > target) {
                h = m - 1;
            } else {
                int i = m;
                int j = m;
                while(i >= 0 && A[i] == target) --i; 
                while(j < n && A[j] == target) ++j;
                ret.push_back(i+1);
                ret.push_back(j-1);
                break;
            }
        }
        if(ret.size() == 0) {ret.push_back(-1); ret.push_back(-1);}
        return ret;
    }
};