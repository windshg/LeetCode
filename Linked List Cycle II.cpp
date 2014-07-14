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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *l = head;
        ListNode *r = head;
        while (r) {
            l = l->next;
            r = r->next;
            if (r) r = r->next;
            if (r && l == r) break;
        }
        if (!r) return NULL;
        l = head;
        while (l != r) {
            l = l->next;
            r = r->next;
        }
        return r;
    }
};