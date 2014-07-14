// stupid solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string str = string(n, '(') + string(n, ')');
        do {
            if (valid(str)) ret.push_back(str);
        } while (next_permutation(str.begin(), str.end()));
        return ret;
    }
    
    inline bool valid(string &str) {
        int lpcount = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                lpcount ++;
            } else {
                if (lpcount > 0) -- lpcount;
                else return false;
            }
        }
        return true;
    }
};

// smarter method: DFS, which takes the shortest time.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        dfs("", 0, 0, n, ret);
        return ret;
    }
    
    void dfs(string buf, int leftNum, int rightNum, const int n, vector<string> &ret) {
        if (rightNum > leftNum || leftNum > n) return;
        if (leftNum == rightNum && leftNum == n) {
            ret.push_back(buf);
            return;
        }
        dfs(buf + "(", leftNum + 1, rightNum, n, ret);
        dfs(buf + ")", leftNum, rightNum + 1, n, ret);
    }
};
