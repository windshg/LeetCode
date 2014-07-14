class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &s) {
        vector<vector<int> > ret;
        vector<int> buf;
        sort(s.begin(), s.end());
        dfs(s, 0, buf, ret);
        return ret;
    }
    
    void dfs(vector<int> &s, int beg, vector<int> buf, vector<vector<int> > &ret) {
        ret.push_back(buf);
        if (beg == s.size()) return;
        for (int i = beg; i < s.size(); ++i) {
            if (i > beg && s[i] == s[i-1]) continue;
            buf.push_back(s[i]);
            dfs(s, i+1, buf, ret);
            buf.pop_back();
        }
    }
};