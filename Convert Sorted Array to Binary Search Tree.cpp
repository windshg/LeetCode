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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, num.size() - 1);
    }
    
    TreeNode *build(vector<int> &num, int l, int h) {
        if (l > h) return NULL;
        if (l == h) {
            TreeNode *node = new TreeNode(num[l]);
            return node;
        }
        int mid = (l + h) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = build(num, l, mid - 1);
        root->right = build(num, mid + 1, h);
        return root;
    }
};

// iteration, 纯粹作死
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
        stack<pair<TreeNode *, pair<int, int>>> s;
        
        TreeNode *root = new TreeNode(num[(num.size() - 1) / 2]);
        pair<int, int> pr(0, num.size() - 1);
        pair<TreeNode *, pair<int, int>> ps(root, pr);
        s.push(ps);
        
        while (!s.empty()) {
            pair<TreeNode *, pair<int, int>> p = s.top();
            s.pop();
            
            int l = p.second.first;
            int h = p.second.second;
            int m = (l + h) / 2;
            
            if (m+1 <= h) {
                TreeNode *rnode = new TreeNode(num[(m+h+1)/2]);
                p.first->right = rnode;
                
                pair<int, int> rpr(m+1, h);
                pair<TreeNode *, pair<int, int>> rps(rnode, rpr);
                s.push(rps);
            }
            
            if (l <= m-1) {
                TreeNode *lnode = new TreeNode(num[(l+m-1)/2]);
                p.first->left = lnode;
                
                pair<int, int> lpr(l, m-1);
                pair<TreeNode *, pair<int, int>> lps(lnode, lpr);
                s.push(lps);
            }
        }
        
        return root;
    }
};