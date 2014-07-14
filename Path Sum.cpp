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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

// iteration
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        stack<pair<TreeNode *, int> > stk;
        stk.push(pair<TreeNode *, int>(root, sum));
        while (!stk.empty()) {
            pair<TreeNode *, int> f = stk.top();
            stk.pop();
            if (!f.first->left && !f.first->right && f.first->val == f.second) return true;
            f.second -= f.first->val;
            if (f.first->left) stk.push(pair<TreeNode *, int>(f.first->left, f.second));
            if (f.first->right) stk.push(pair<TreeNode *, int>(f.first->right, f.second));
        }
        return false;
    }
};