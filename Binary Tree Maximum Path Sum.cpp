/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// straight-forward solution
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int ret = 0, sps = 0;
        maxPathSumRec(root, sps, ret);
        return ret;
    }
    
    void maxPathSumRec(TreeNode *root, int &singlePathSum, int &maxSum) {
        if (!root) return;
        singlePathSum = root->val;
        maxSum = root->val;
        int lsps = 0, lms = INT_MIN, rsps = 0, rms = INT_MIN;
        maxPathSumRec(root->left, lsps, lms);
        maxPathSumRec(root->right, rsps, rms);
        singlePathSum = max(singlePathSum, singlePathSum + max(lsps, rsps));
        maxSum = max(maxSum, lms);
        maxSum = max(maxSum, rms);
        maxSum = max(maxSum, singlePathSum);
        maxSum = max(maxSum, lsps + rsps + root->val);
    }
};

// shorter code
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int ret = INT_MIN;
        maxPathSumRec(root, ret);
        return ret;
    }
    
    int maxPathSumRec(TreeNode *root, int &ret) {
        if (!root) return 0;
        int l = maxPathSumRec(root->left, ret);
        int r = maxPathSumRec(root->right, ret);
        int ps = max(root->val, max(l, r) + root->val);
        ret = max(ret, ps);
        ret = max(ret, l + r + root->val);
        return ps;
    }
};