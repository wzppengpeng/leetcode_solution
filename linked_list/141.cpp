/**
 * Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

 */


/**
 * 使用快慢指针相遇法，如果有环，快指针一定会在某个时刻与慢指针相遇
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
    bool hasCycle(ListNode *head) {
        ListNode *low = head, *fast = head;
        while(fast) {
            low = low->next;
            fast = fast->next;
            if(!fast) return false;
            fast = fast->next;
            if(!fast) return false;
            if(low == fast) return true;
        }
        return false;
    }
};