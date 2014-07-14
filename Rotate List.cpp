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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        ListNode dummy(0);
        ListNode *dh = &dummy;
        dh->next = head;
        ListNode *l = head;
        ListNode *h = head;
        while (k) {
            h = h->next; 
            if (!h) h = head;
            -- k;
        }
        if (!h) return head;
        while (h->next) {
            l = l->next;
            h = h->next;
        }
        h->next = dh->next;
        dh->next = l->next;
        l->next = NULL;
        return dh->next;
    }
};