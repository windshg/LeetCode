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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *l = head;
        ListNode *r = head;
        while (r) {
            l = l->next;
            r = r->next;
            if (r) r = r->next;
            if (r && l == r) return true;
        }
        return false;
    }
};