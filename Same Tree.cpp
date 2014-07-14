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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// iteration
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> stk;
        stk.push(p);
        stk.push(q);
        while (!stk.empty()) {
            TreeNode *r = stk.top(); stk.pop();
            TreeNode *l = stk.top(); stk.pop();
            if (!l && !r) continue;
            if (!l && r) return false;
            if (l && !r) return false;
            if (l->val != r->val) return false;
            stk.push(l->left);
            stk.push(r->left);
            stk.push(l->right);
            stk.push(r->right);
        }
        return true;
    }
};