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
    void recoverTree(TreeNode *root) {
        if (!root) return;
        vector<TreeNode *> mistake;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        TreeNode *last = NULL;
        while (!stk.empty() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                if (last && last->val > cur->val) {
                    mistake.push_back(last);
                    mistake.push_back(cur);
                }
                last = cur;
                cur = cur->right;
            }
        }
        if (mistake.size() > 0) 
            swap(mistake.front()->val, mistake.back()->val);
    }
    
};