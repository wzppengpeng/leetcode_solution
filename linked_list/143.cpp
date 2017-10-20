/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 使用一个数组来保存当前所有的指针，然后利用数组可以下标访问的特点，使用双指针法进行遍历
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        vector<ListNode* > nodes;
        ListNode* p = head;
        while(p) {
            nodes.emplace_back(p);
            p = p->next;
        }
        int i = 0, j = nodes.size() - 1;
        while(i < j) {
            nodes[i++]->next = nodes[j];
            if(i == j) break;
            nodes[j--]->next = nodes[i];
        }
        nodes[j]->next = nullptr;
    }
};