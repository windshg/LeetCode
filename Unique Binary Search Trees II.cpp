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
    vector<TreeNode *> generateTrees(int n) {
        int a[n];
        for (int i = 0; i < n; ++i) a[i] = i + 1;
        return generate(a, 0, n-1);
    }
    
    vector<TreeNode *> generate(int a[], int l, int h) {
        vector<TreeNode *> ret;
        if (l > h) {
            ret.push_back(NULL);
            return ret;
        }
        if (l == h) {
            TreeNode *root = new TreeNode(a[l]);
            ret.push_back(root);
            return ret;
        }
        for (int k = l; k <= h; ++k) {
            vector<TreeNode *> left = generate(a, l, k-1);
            vector<TreeNode *> right = generate(a, k+1, h);
            for (int i = 0; i < left.size(); ++i) {
                for (int j = 0; j < right.size(); ++j) {
                    TreeNode *root = new TreeNode(a[k]);
                    root->left = left[i];
                    root->right = right[j];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};