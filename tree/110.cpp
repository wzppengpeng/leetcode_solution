/**
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */


/**
 * 递归
 * 递归的函数中返回depth和子树是否平衡的结果
 * 然后只要子树不平衡那么总体就不平衡
 * 当子树平衡时，判断差值
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
    bool isBalanced(TreeNode* root) {
        return is_bance(root).first;
    }

    std::pair<bool, int> is_bance(TreeNode* work) {
        if(!work) return {true, 0};
        auto left_res = is_bance(work->left);
        auto right_res = is_bance(work->right);
        auto max_len = max(left_res.second, right_res.second);
        if((left_res.first == false) || (right_res.first == false)) return {false, 1 + max_len};
        else return {std::abs(left_res.second - right_res.second) <= 1, 1 + max_len};
    }
};