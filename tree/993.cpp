/**
 * In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
 */


/**
 * 用BFS遍历，保存根节点值
 */


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<std::pair<TreeNode*, int>> que;
        que.push({root, -1});
        int num = 1;
        bool is_got = false; int temp_root_num = -1;
        while(!que.empty()) {
            auto& p = que.front();
            TreeNode* tmp = p.first;
            int root_num = p.second;
            que.pop();
            --num;
            if(is_target(tmp->val, x, y)) {
                if(is_got && temp_root_num != root_num)
                    return true;
                else if(is_got && temp_root_num == root_num)
                    return false;
                else {
                    is_got = true;
                    temp_root_num = root_num;
                }
            }
            if(tmp->left) que.push({tmp->left, tmp->val});
            if(tmp->right) que.push({tmp->right, tmp->val});
            if(num == 0) {

                num = que.size();
                is_got = false;
                temp_root_num = -1;
            }
        }
        return false;
    }

    inline bool is_target(int t, int x, int y) const {
        return t == x || t == y;
    }
};