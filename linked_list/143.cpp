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


/**
 * 用O(1)空间复杂度的方法
 * 先快慢指针找中间，然后翻转后半部分，然后再将前面和后半部分交叉合并
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        auto* mid = find_mid(head);
        mid = reverse_list(mid);
        merge(head, mid);
    }

private:
    ListNode* find_mid(ListNode* head) {
        ListNode* low = head, *fast = head;
        while(fast) {
            fast = fast->next;
            if(!fast) {
                low = low->next;
                break;
            }
            fast = fast->next;
            low = low->next;
        }
        return low;
    }

    ListNode* reverse_list(ListNode* work) {
        ListNode *s = nullptr, *p = work, *q = work->next;
        while(p) {
            p->next = s;
            s = p;
            p = q;
            if(q) q = q->next;
        }
        return s;
    }

    void merge(ListNode* p, ListNode* q) {
        ListNode *next_p = nullptr, *next_q = nullptr;
        while(p && q) {
            next_p = p->next;
            next_q = q->next;
            p->next = q;
            q->next = next_p;
            p = next_p;
            q = next_q;
        }
        p->next = q;
    }

};