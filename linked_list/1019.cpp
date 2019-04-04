class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res(get_list_length(head), 0);
        if(!head) return res;
        ListNode* work = head->next;
        deque<pair<size_t, int>> que;
        que.push_back({0, head->val});
        size_t i = 1;
        while(work) {
            while(!que.empty() && work->val > que.back().second) {
                res[que.back().first] = work->val;
                que.pop_back();
            }
            que.push_back({i, work->val});
            work = work->next;
            ++i;
        }
        return res;
    }

    size_t get_list_length(ListNode* head) const {
        size_t length = 0;
        ListNode* work = head;
        while(work) {
            work = work->next;
            ++length;
        }
        return length;
    }
};