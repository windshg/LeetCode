/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Honestly, the only trick in this solution is the algorithm encapsulated in the STL container priority_queue.
// So nothing it is.

struct cmp {
    bool operator () (ListNode *l, ListNode *h) const {
        return l->val > h->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) pq.push(lists[i]);
        }
        ListNode dh(0);
        ListNode *cur = &dh;
        while (!pq.empty()) {
            ListNode *t = pq.top();
            pq.pop();
            cur->next = t;
            cur = cur->next;
            if (t->next) pq.push(t->next);
        }
        return dh.next;
    }
};