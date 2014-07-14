/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Straight-forward solution, O(3 * n)
class Solution {
public:
    void reorderList(ListNode *head) {
        int n = getLength(head);
        if (n < 2) return;
        if (n % 2 != 0) n += 1;
        int m = n / 2;
        ListNode *l = head;
        ListNode *h = head->next;
        while (--m) {
            l = l->next;
            h = h->next;
        }
        l->next = NULL;
        h = reverseList(h);
        interleaveLists(head, h);
    }
    
private:
    ListNode *reverseList(ListNode *head) {
        if (!head) return head;
        ListNode dummy(0);
        ListNode *dh = &dummy;
        dh->next = head;
        ListNode *last = head;
        ListNode *cur = head->next;
        while (cur) {
            last->next = cur->next;
            cur->next = dh->next;
            dh->next = cur;
            cur = last->next;
        }
        return dh->next;
    }
    
    void interleaveLists(ListNode *head1, ListNode *head2) {
        ListNode dummy(0);
        ListNode *dh = &dummy;
        ListNode *cur = dh;
        while (head1 && head2) {
            cur->next = head1;
            head1 = head1->next;
            cur = cur->next;
            cur->next = head2;
            head2 = head2->next;
            cur = cur->next;
        }
        while (head1) {cur->next = head1; head1 = head1->next; cur = cur->next;}
        while (head2) {cur->next = head2; head1 = head2->next; cur = cur->next;}
        cur->next = NULL;
    }
    
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len ++;
            head = head->next;
        }
        return len;
    }
};

// Tricky solution, O(n)
