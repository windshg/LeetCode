/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Simple solution without any trick. Be accepted suprisingly.
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> buf;
        int l1 = 1, l2 = 0;
        while (!q.empty()) {
            TreeNode *f = q.front();
            q.pop();
            -- l1;
            buf.push_back(f->val);
            
            if (f->left) {
                q.push(f->left);
                ++ l2;
            }
            
            if (f->right) {
                q.push(f->right);
                ++ l2;
            }
            
            if (l1 == 0) {
                l1 = l2;
                l2 = 0;
                ret.push_back(buf);
                buf.erase(buf.begin(), buf.end());
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
};