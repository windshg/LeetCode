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

// n * O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) len ++;
        if (len < 2) return head;

        ListNode dh(0);
        dh.next = head;
        
        int skip = 1;        
        while (skip < len) {
            ListNode* pre = &dh;
            ListNode* h1 = pre->next;
            ListNode* h2 = h1;
            while (h2) {
                int s = 0;
                while (h2 && (++s) <= skip) h2 = h2->next;
                ListNode* end = h2;
                s = 0;
                while (end && (++s) <= skip) end = end->next;
                pre = merge(pre, h1, h2, end);
                h1 = pre->next;
                h2 = h1;
            }
            skip *= 2;
        }
        
        return dh.next;
    }

    void print(ListNode* head) {
        ListNode* p = head;
        while (p) {
            cout << p->val << "->";
            p = p->next;
        }
        cout << "null" << endl;
    }

    ListNode* merge(ListNode* pre, ListNode* h1, ListNode* h2, ListNode* end) {
        ListNode* pre1 = pre;
        ListNode* p1 = h1;
        ListNode* pre2 = h1;
        while (pre2->next != h2) pre2 = pre2->next;
        ListNode* p2 = h2;

        while (p1 != p2 && p2 != end) {
            if (p1->val < p2->val) {
                p1 = p1->next;
            } else {
                pre2->next = p2->next;
                p2->next = p1;
                pre1->next = p2;
                p2 = pre2->next;
            }
            pre1 = pre1->next;
        }

        while (pre2->next != end) pre2 = pre2->next;

        return pre2;
    }
};
