/**
 * We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:

Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 */

/**
 * 还是使用哈希表来处理，用哈希set保存所有的待查值，然后遍历链表对是否在待查区进行判断
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
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head || G.empty()) return 0;
        unordered_set<int> G_set(std::begin(G), std::end(G));
        int res = 0;
        bool is_in = false;
        ListNode* p = head;
        while(p) {
            if(G_set.count(p->val) && !is_in) {
                ++res;
                is_in = true;
            } else if(G_set.count(p->val) == 0 && is_in) {
                is_in = false;
            }
            p = p->next;
        }
        return res;
    }
};