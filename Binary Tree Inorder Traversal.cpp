// Basic solution. Stack overflows evidently on a large scale.
// Time: O(n) 
// Space: O(n) in worst case, O(log n) in best case.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
    
    void dfs(TreeNode *root, vector<int> &ret) {
        if (!root) return;
        dfs(root->left, ret);
        ret.push_back(root->val);
        dfs(root->right, ret);
    }
};

// Iterative Version
// Use stack from STL.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (!stk.empty() || p) {
            if (p) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                ret.push_back(p->val);
                p = p->right;
            }
        }
        return ret;
    }
};
