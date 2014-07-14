// 4Sum

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if(num.size() < 4) return ret;
        sort(num.begin(), num.end());
        int n = num.size();
        int i = 0, j, k, l;
        while(i < n-3) {
            j = i + 1;
            while(j < n-2) {
                k = j + 1;
                l = n - 1;                
                while(k < l) {
                    int tsum = num[i] + num[j] + num[k] + num[l];
                    if(tsum > target) { int tl = num[l]; while(num[--l] == tl);} 
                    else if(tsum < target) { int tk = num[k]; while(num[++k] == tk);} 
                    else { 
                        vector<int> r(4); r[0] = num[i]; r[1] = num[j]; r[2] = num[k]; r[3] = num[l]; ret.push_back(r);
                        int tk = num[k];while(num[++k] == tk);
                    }
                }
                int tj = num[j]; while(num[++j] == tj);            
            }
            int ti = num[i]; while(num[++i] == ti);        
        }
    }
};