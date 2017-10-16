/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


 */

/**
 * 使用快慢指针相遇法
 * 该问题可以将第二个链表的首尾连起来，然后通过快慢指针相遇法寻找形成了环的起始位置
 * 但是需要注意在结束时需要将链表还原
 */


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if((!headB) || (!headA)) return nullptr;
        ListNode* p = headB;
        while(p->next) p = p->next;
        p->next = headB;
        ListNode* fast = headA, *low = headA;
        while(fast) {
            fast = fast->next;
            if(!fast) return return_fun(p, nullptr);
            fast = fast->next;
            low = low->next;
            if(low == fast) {
                ListNode* q = headA;
                while(q != low) {
                    q = q->next;
                    low = low->next;
                }
                return return_fun(p, low);
            }
        }
        return return_fun(p, nullptr);
    }

    inline ListNode* return_fun(ListNode* p, ListNode* res) {
        p->next = nullptr;
        return res;
    }
};