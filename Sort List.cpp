// bubble sort, O(n^2) TLE, stupid method, 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode dummy(0);
        ListNode *dh = &dummy;
        dh->next = head;
        ListNode *end = NULL;
        while (dh->next != end) {
            ListNode *last = dh;
            ListNode *cur = dh->next;
            while (cur != end) {
                if (cur->next) {
                    if (cur->val > cur->next->val) {
                        last->next = cur->next;
                        cur->next = cur->next->next;
                        last->next->next = cur;
                        last = last->next;
                        continue;
                    }
                }
                last = last->next;
                cur = cur->next;
            }
            end = last;
        }
        
        return dh->next;
    }
};

// merge sort, which borrow some incredible trick from internet. A merge solution is easy to come up with. 
// Since, you know, random access is not available for linked list. You have to do something to get value of specific node.
// Luckily, merge sort have its spontaneous feature that corresponding pointer pointing to element in need of sorting moves one by one from left to right during each recursion process.
// That means we can add some trick in the recursion function making use this feature by changing the pointer value assignment to pointer reference assignment.
// And keep manipulating the reference in every recursion so as to move the head pointer forward.

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return sortLinkedList(head, getLength(head));
    }
    
    ListNode *sortLinkedList(ListNode *&head, int n) {
        if (n == 0) return head;
        if (n == 1) {
            ListNode *cur = head;
            head = head->next;
            cur->next = NULL;
            return cur;
        }
        int mid = n / 2;
        ListNode *head1 = sortLinkedList(head, mid);
        ListNode *head2 = sortLinkedList(head, n - mid);
        return mergeLinkedList(head1, head2);
    }
    
    ListNode *mergeLinkedList(ListNode *head1, ListNode *head2) {
        ListNode dummy(0);
        ListNode *dh = &dummy;
        ListNode *cur = dh;
        while (head1 && head2) {
            if (head1->val > head2->val) {
                cur->next = head2;
                head2 = head2->next;
            } else {
                cur->next = head1;
                head1 = head1->next;
            }
            cur = cur->next;
        }
        while (head1) {cur->next = head1; head1 = head1->next; cur = cur->next;}
        while (head2) {cur->next = head2; head2 = head2->next; cur = cur->next;}
        cur->next = NULL;
        return dh->next;
    }
    
    int getLength(ListNode *head) {
        int ret = 0;
        while (head) {
            ret ++;
            head = head->next;
        }
        return ret;
    }
    
};

// O(2 * n * logn)
// shorter but slower

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *l = head, *h = head, *t = NULL;
        while (h && h->next) {
            h = h->next->next;
            t = l;
            l = l->next;
        }
        t->next = NULL;
        ListNode *head2 = l;
        
        head = sortList(head);
        head2 = sortList(head2);
        
        // merge two lists
        ListNode dh(0);
        ListNode *cur = &dh;
        while (head && head2) {
            if (head->val > head2->val) {
                cur->next = head2;
                head2 = head2->next;
            } else {
                cur->next = head;
                head = head->next;
            }
            cur = cur->next;
        }
        if (head) cur->next = head;
        if (head2) cur->next = head2;
        return dh.next;
    }
};