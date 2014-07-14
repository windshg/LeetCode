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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode dh(0);
        ListNode *cur = &dh;
        while (l1 && l2) {
            int t = l1->val + l2->val + carry;
            cur->next = new ListNode(t % 10);
            carry = t / 10;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int t = l1->val + carry;
            cur->next = new ListNode(t % 10);
            carry = t / 10;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2) {
            int t = l2->val + carry;
            cur->next = new ListNode(t % 10);
            carry = t / 10;
            cur = cur->next;
            l2 = l2->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        return dh.next;
    }
};