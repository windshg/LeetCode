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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        return build(inorder, 0, postorder, 0, inorder.size());
    }
    
    TreeNode *build(vector<int> &inorder, int il, vector<int> &postorder, int pl, int len) {
        if (len <= 0) return NULL;
        if (len == 1) {
            TreeNode *node = new TreeNode(inorder[il]);
            return node;
        }
        int im = il;
        while (inorder[im] != postorder[pl+len-1]) ++ im;
        int lLen = im - il;
        int rLen = len - lLen - 1;
        TreeNode *node = new TreeNode(inorder[im]);
        node->left = build(inorder, il, postorder, pl, lLen);
        node->right = build(inorder, im + 1, postorder, pl + lLen, rLen);
        return node;
    }
};