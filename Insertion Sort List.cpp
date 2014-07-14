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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode dummy(0);
        ListNode *dh = &dummy;
        dh->next = head;
        ListNode *preStart = head;
        ListNode *start = preStart->next;
        while (start) {
            ListNode *pre = dh;
            ListNode *cur = dh->next;
            while (cur != start) {
                if (cur->val > start->val) {
                    preStart->next = start->next;
                    pre->next = start;
                    start->next = cur;
                    break;
                }
                pre = pre->next;
                cur = cur->next;
            }
            if (cur == start) preStart = start;
            start = preStart->next;
        }
        return dh->next;
    }
};