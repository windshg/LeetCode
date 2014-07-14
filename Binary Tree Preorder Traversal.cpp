// recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        travel(root, ret);
        return ret;
    }
    
    void travel(TreeNode *root, vector<int> &ret) {
        if (!root) return;
        ret.push_back(root->val);
        travel(root->left, ret);
        travel(root->right, ret);
    }
};

// iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *tp = stk.top();
            stk.pop();
            ret.push_back(tp->val);
            if (tp->right) stk.push(tp->right);
            if (tp->left) stk.push(tp->left);
        }
        return ret;
    }
};

// Morris Traversal