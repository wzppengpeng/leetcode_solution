/**
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.
 */

/**
 * 典型的用队列实现树的层序遍历（BFS）
 * 注意判断最大值的最小位置，设定初始值
 */

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 1;
        std::queue<TreeNode*> que;
        int min_value = root->val, min_level = 1;
        int level_sum = 0, level_now = 1;
        int num = 1;
        que.push(root);
        while(!que.empty()) {
            auto* tmp = que.front();
            que.pop();
            --num;
            if(tmp->left)
                que.push(tmp->left);
            if(tmp->right)
                que.push(tmp->right);
            level_sum += tmp->val;
            if(num == 0) {
                if(level_sum > min_value) {
                    min_value = level_sum;
                    min_level = level_now;
                }
                num = que.size();
                ++level_now;
                level_sum = 0;
            }
        }
        return min_level;
    }
};