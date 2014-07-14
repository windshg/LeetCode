// recursion, time: O(n), space: O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        travel(root, ret);
        return ret;
    }
    
    void travel(TreeNode *root, vector<int> &ret) {
        if (!root) return;
        travel(root->left, ret);
        travel(root->right, ret);
        ret.push_back(root->val);
    }
};

// iteration, time: O(n), space: O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        stack<TreeNode *> stk;
        TreeNode *last = NULL;
        TreeNode *cur = root;
        do {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            TreeNode *tp = stk.top();
            if (tp->right && tp->right != last) {
                cur = tp->right;
            } else {
                ret.push_back(tp->val);
                last = tp;
                stk.pop();
            }
        } while(!stk.empty());
        return ret;
    }
};

// Morris Travel, time:O(n), space:O(1), to be continued