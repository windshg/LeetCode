/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dh;
        ListNode* pre = &dh;
        
        int ac = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + ac;
            ListNode* n = new ListNode(sum % 10, nullptr);
            ac = sum / 10;
            pre->next = n;
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* l = l1;
        if (l2) l = l2;

        while (l) {
            int sum = l->val + ac;
            ListNode* n = new ListNode;
            n->val = sum % 10;
            ac = sum / 10;
            pre->next = n;
            pre = pre->next;
            l = l->next;
        }

        if (ac > 0) pre->next = new ListNode(ac, nullptr);

        return dh.next;
    }
};
