/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive version
// One piece of cake.
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSame(root->left, root->right);
    }
    
    bool isSame(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) return true;
        if (!node1 && node2) return false;
        if (node1 && !node2) return false;
        if (node1->val != node2->val) return false;
        return isSame(node1->left, node2->right) && isSame(node1->right, node2->left);
    }
};

// Iterative version
// It is stack that always comes up first when you try to convert your solution from recursive way to iterative way.
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> stk;
        stk.push(root->left);
        stk.push(root->right);
        while (!stk.empty()) {
            TreeNode *r = stk.top(); stk.pop();
            TreeNode *l = stk.top(); stk.pop();
            if (!l && !r) continue;
            if (!l && r) return false;
            if (l && !r) return false;
            if (l->val != r->val) return false;
            stk.push(l->left);
            stk.push(r->right);
            stk.push(l->right);
            stk.push(r->left);
        }
        return true;
    }
    
};