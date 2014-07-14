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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (!root->left) return r + 1;
        if (!root->right) return l + 1;
        return min(l, r) + 1;
    }
};