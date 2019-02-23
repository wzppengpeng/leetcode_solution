/**
 * Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example, given a 3-ary tree:
 */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> row;
        queue<Node*> que;
        que.push(root);
        int num = 1;
        while(!que.empty()) {
            auto tmp = que.front();
            que.pop();
            --num;
            row.push_back(tmp->val);
            for(auto child : tmp->children) {
                if(child) que.push(child);
            }
            if(num == 0) {
                res.emplace_back(std::move(row));
                row.clear();
                num = que.size();
            }
        }
        return res;
    }
};