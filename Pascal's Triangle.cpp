class Solution {
public:
    vector<vector<int> > generate(int n) {
        vector<vector<int> > ret;
        for (int i = 0; i < n; ++i) {
            vector<int> buf;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) buf.push_back(1);
                else buf.push_back(ret[i-1][j] + ret[i-1][j-1]);
            }
            ret.push_back(buf);
        }
        return ret;
    }
};