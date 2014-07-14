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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode dh(0);
        ListNode *pre = &dh;
        pre->next = head;
        ListNode *pvt = head;
        while (pvt && pvt->val < x) pvt = pvt->next;
        if (!pvt) return head;
        ListNode *l = pre;
        ListNode *h = pvt;
        while (true) {
            while (l->next != pvt && l->next->val <= x) l = l->next;
            ListNode *ln = l->next == pvt ? NULL : l->next;
            while (h->next != NULL && h->next->val >= x) h = h->next;
            ListNode *hn = h->next;
            if (!ln && !hn) break;
            if (ln) {
                l->next = ln->next;
                ln->next = h->next;
                h->next = ln;
            }
            if (hn) {
                h->next = hn->next;
                hn->next = l->next;
                l->next = hn;
            }
        }
        return pre->next;
    }
};