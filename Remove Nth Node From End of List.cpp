// Remove Nth Node From End of List

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head) return head;
        ListNode *h = head;
        while(n && h) {h = h->next; --n;}
        if(n > 0) return head;
        ListNode *dh = new ListNode(0);
        dh->next = head;
        ListNode *pre = dh;
        ListNode *l = head;
        while(h) {
            pre = pre->next;
            l = l->next;
            h = h->next;
        }
        pre->next = l->next;
        delete l;
        ListNode *ret = dh->next;
        delete dh;
        return ret;
    }
};