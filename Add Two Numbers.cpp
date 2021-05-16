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
        while (l1 || l2 || ac > 0) {
            int sum = ac;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            ListNode* n = new ListNode(sum % 10, nullptr);
            ac = sum / 10;
            pre->next = n;
            pre = pre->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dh.next;
    }
};
