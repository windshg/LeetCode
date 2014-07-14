/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        ListNode *l = head;
        ListNode *h = head->next;
        while (h) {
            if (l->val == h->val) {
                l->next = h->next;
                delete h;
                h = l->next;
            } else {
                l = l->next;
                h = h->next;
            }
        }
        return head;
    }
};