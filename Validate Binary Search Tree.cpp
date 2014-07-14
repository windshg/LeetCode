/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // recursion
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int buf = INT_MIN;
        return travel(root, buf);
    }
    
    bool travel(TreeNode *root, int &buf) {
        if (!root) return true;
        if (!travel(root->left, buf)) return false;
        if (buf >= root->val) return false;
        buf = root->val;
        if (!travel(root->right, buf)) return false;
        return true;
    }
};

// iteration