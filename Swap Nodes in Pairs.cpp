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
    ListNode *swapPairs(ListNode *head) {
        if (!head) return head;
        ListNode dh(0);
        ListNode *pre = &dh;
        pre->next = head;
        ListNode *l = head, *h = head->next;
        while (l && h) {
            pre->next = h;
            l->next = h->next;
            h->next = l;
            pre = l;
            l = pre->next;
            if (l) h = l->next;
            else h = NULL;
        }
        return dh.next;
    }
};