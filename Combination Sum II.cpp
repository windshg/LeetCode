// Combination Sum II 

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> tmp;
        combination(num, 0, target, tmp, ret);
        return ret;
    }
    
    void combination(vector<int> &num, int beg, int target, vector<int> &tmp, vector<vector<int> > &ret) {
        if(target < 0) return;
        if(target == 0) {ret.push_back(tmp); return;}
        for(int i = beg; i < num.size();) {
            int t = num[i];
            tmp.push_back(t);
            combination(num, i+1, target - t, tmp, ret);
            tmp.pop_back();
            while(num[++i] == t && i < num.size());
        }
    }
};