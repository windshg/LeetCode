// Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> map;
        RandomListNode *dh = new RandomListNode(0);
        RandomListNode *cur = head;
        RandomListNode *last = dh;
        while(cur != NULL) {
            if(!map[cur]) {
                RandomListNode *newNode = new RandomListNode(cur->label);
                map[cur] = newNode;
            }
            last->next = map[cur];
            
            if(cur->random && !map[cur->random]) {
                RandomListNode *newNode = new RandomListNode(cur->random->label);
                map[cur->random] = newNode;
            }
            map[cur]->random = map[cur->random];
            
            last = last->next;
            cur = cur->next;
        }
        delete dh;
        return map[head];
    }
};