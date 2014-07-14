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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode dummy(0);
        ListNode *dh = &dummy;
        dh->next = head;
        ListNode *pre = dh;
        ListNode *last = head;
        ListNode *cur = head->next;
        ListNode *end = cur;
        while (-- m) {
            pre = pre->next;
            last = last->next;
            cur = cur->next;
            end = end->next;
            -- n;
        }
        while (--n) end = end->next;
        while (cur != end) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return dh->next;
    }
};