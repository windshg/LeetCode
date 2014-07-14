/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        TreeLinkNode *pre = NULL;
        int l1 = 1, l2 = 0;
        while (!q.empty()) {
            TreeLinkNode *f = q.front();
            q.pop();
            -- l1;
            
            if (!pre) {
                pre = f;
            } else {
                pre->next = f;
                pre = pre->next;
            }
            
            if (f->left) {
                q.push(f->left);
                ++ l2;
            }
            
            if (f->right) {
                q.push(f->right);
                ++ l2;
            }
            
            if (l1 == 0) {
                l1 = l2;
                l2 = 0;
                pre = NULL;
            }
        }
    }
};