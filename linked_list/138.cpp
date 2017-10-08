/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
 */

/**
 * 使用哈希表来保存旧的单链表和新的单链表之间的对应关系，先建链表，然后再一次遍历附上随机指针的值
 */

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
        if(!head) return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> list_map;
        RandomListNode* n_head = new RandomListNode(head->label);
        list_map.emplace(head, n_head);
        RandomListNode* p = head->next, *q = n_head;
        while(p) {
            RandomListNode* s = new RandomListNode(p->label);
            q->next = s;
            q = q->next;
            list_map.emplace(p, q);
            p = p->next;
        }
        p = head, q = n_head;
        while(p) {
            if(p->random) {
                q->random = list_map[p->random];
            }
            p = p->next;
            q = q->next;
        }
        return n_head;
    }
};