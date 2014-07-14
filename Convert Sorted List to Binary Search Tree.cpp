/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
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
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head, getLength(head));
    }
    
    TreeNode *build(ListNode *&head, int n) {
        if (n == 0) return NULL;
        if (n == 1) {
            TreeNode *node = new TreeNode(head->val);
            head = head->next;
            return node;
        }
        int mid = n / 2;
        TreeNode *left = build(head, mid);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = build(head, n - mid - 1);
        root->left = left;
        root->right = right;
        return root;
    }
    
    int getLength(ListNode *head) {
        int ret = 0;
        while (head) {
            ret ++;
            head = head->next;
        }
        return ret;
    }
};