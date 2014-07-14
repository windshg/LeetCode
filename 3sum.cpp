// 3Sum

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if(num.size() < 3) return ret;
        sort(num.begin(), num.end());
        int k, l;
        for(int i = 0; i <= num.size() - 3;) {
            k = i+1;
            l = num.size()-1;
            while(k < l) {
                int tsum = num[i] + num[k] + num[l];
                if(tsum > 0) {
                    l--;
                } else if(tsum < 0) {
                    k++;
                } else {                    
                    vector<int> r(3);
                    r[0] = num[i];
                    r[1] = num[k];
                    r[2] = num[l];                    
                    ret.push_back(r);
                    int tl = num[l];
                    while(num[--l] == tl);
                }
            }
            int ti = num[i];
            while(num[++i] == ti);
        }
        return ret;
    }
};