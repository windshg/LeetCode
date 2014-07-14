// Combinations

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> a(n);
        for(int i = 0; i < n; ++i) a[i] = i+1;
        vector<vector<int> > ret;
        vector<int> tmp;
        combine(a, 0, 0, k, tmp, ret);
        return ret;
    }
    
    void combine(vector<int> &a, int beg, int step, int &k, vector<int> &tmp, vector<vector<int> > &ret) {
        if(step == k) {ret.push_back(tmp); return;}
        for(int i = beg; i < a.size(); ++i) {
            tmp.push_back(a[i]);
            combine(a, i+1, step+1, k, tmp, ret);
            tmp.pop_back();
        }
    }
};