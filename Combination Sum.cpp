// Combination Sum 

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &c, int target) {
        sort(c.begin(), c.end());
        vector<vector<int> > ret;
        vector<int> tmp;
        combination(c, 0, target, tmp, ret);
        return ret;
    }
    
    void combination(vector<int> &c, int beg, int target, vector<int> &tmp, vector<vector<int> > &ret) {
        if(target < 0) return;
        if(target == 0) {ret.push_back(tmp); return;}
        for(int i = beg; i < c.size(); ++i) {
            tmp.push_back(c[i]);
            combination(c, i, target - c[i], tmp, ret);
            tmp.pop_back();
        }
    }
};