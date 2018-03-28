/**
 * Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
 */

/**
 * 使用dfs，优先向下遍历。
 * 得到左右子树的最大返回值，之后在该节点位置计算可能的最大值情况
 * 然后向上递归时选取最大支路，同时如果最大之路小于零则截断
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        auto tmp_res = dfs(root, res);
        return res;
    }

    int dfs(TreeNode* p, int& max_sum) {
        if(!p) return 0;
        auto left_res = dfs(p->left, max_sum);
        auto right_res = dfs(p->right, max_sum);
        int back_res = p->val;
        if(left_res > 0) back_res += left_res;
        if(right_res > 0) back_res += right_res;
        max_sum = std::max(max_sum, back_res);
        int return_res = p->val;
        auto son = std::max(left_res, right_res);
        if(son > 0) return_res += son;
        return return_res;
    }
};