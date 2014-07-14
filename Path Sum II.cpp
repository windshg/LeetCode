/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        vector<int> buf;
        travel(root, sum, buf, ret);
        return ret;
    }
    
private:
    void travel(TreeNode *root, const int &sum, vector<int> buf, vector<vector<int> > &ret) {
        if (!root) return;
        buf.push_back(root->val);
        if (!root->left && !root->right)  {
            if (sum(buf) == sum) ret.push_back(buf);
            return;
        }
        travel(root->left, sum, buf, ret);
        travel(root->right, sum, buf, ret);
    }
    
    int sum(const vector<int> &vec) {
        int ret = 0;
        std::for_each(vec.begin(), vec.end(), [&](int n){
            ret += n;
        });
        return ret;
    }
};