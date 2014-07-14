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
    int sumNumbers(TreeNode *root) {
        int ret = 0;
        travel(root, 0, ret);
        return ret;
    }
    
    void travel(TreeNode *root, int buf, int &ret) {
        if (!root) return;
        buf = buf * 10 + root->val;
        if (!root->left && !root->right) {
            ret += buf;
            return;
        }
        travel(root->left, buf, ret);
        travel(root->right, buf, ret);
    }
};