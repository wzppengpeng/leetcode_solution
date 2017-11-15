/**
 * Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
 */

/**
 * 首先使用大数组来保存所有的节点指针
 * 然后通过/ 和 %操作来得到每个分区的长度，以及前面额外加一的长度
 * 数字遍历，注意每一个插入的node指针，要让前面的那一个节点的后续指向空
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if(!root) return vector<ListNode*>(k, nullptr);
        vector<ListNode*> total;
        ListNode* p = root;
        while(p) {
            total.emplace_back(p);
            p = p->next;
        }
        int length = total.size();
        int less = length / k, more = length % k;
        vector<ListNode*> res;
        int loc = 0;
        for(int i = 0; i < more; loc += (1 + less), ++i) {
            if(loc > 0) total[loc - 1]->next = nullptr;
            res.emplace_back(total[loc]);
        }
        for(int j = res.size(); j < k; loc += less, ++j) {
            if(loc > 0) total[loc - 1]->next = nullptr;
            if(loc < total.size()) {
                res.emplace_back(total[loc]);
            }
            else res.emplace_back(nullptr);
        }
        return res;
    }
};