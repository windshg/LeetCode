// easy, no need to explain
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        while (root) {
            if (root->left) {
                TreeNode *cur = root->left;
                while (cur->right) cur = cur->right;
                cur->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};