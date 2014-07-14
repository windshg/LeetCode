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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        int n = preorder.size();
        return build(preorder, 0, inorder, 0, n);
    }
    
    TreeNode *build(vector<int> &preorder, int pl, vector<int> &inorder, int il, int len) {
        if (len <= 0) return NULL;
        if (len == 1) {
            TreeNode *node = new TreeNode(preorder[pl]);
            return node;
        }
        int im = il;
        while (inorder[im] != preorder[pl]) ++ im;
        int lLen = im - il;
        int rLen = len - lLen - 1;
        TreeNode *node = new TreeNode(inorder[im]);
        node->left = build(preorder, pl + 1, inorder, il, lLen);
        node->right = build(preorder, pl + lLen + 1, inorder, im + 1, rLen);
        return node;
    }
};