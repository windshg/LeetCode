// Permutations II

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        helper(num, 0, ret);
        return ret;
    }
    
    void helper(vector<int> &num, int beg, vector<vector<int> > &ret) {
        if(beg == num.size()) {ret.push_back(num); return;}
        for(int i = beg; i < num.size(); ++i) {
            swap(num[beg], num[i]);
            helper(num, beg+1, ret);
            swap(num[beg], num[i]);
        }
    }
};