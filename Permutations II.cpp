// Permutations II

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        ret.push_back(num);
        while(next_permutation(num.begin(), num.end())) {
            ret.push_back(num);
        }
        return ret;
    }
};