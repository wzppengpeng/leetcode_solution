/**
 * Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.
 */


class Solution {
public:
    int distributeCoins(TreeNode* root) {
        res_ = 0;
        dfs(root);
        return res_;
    }

    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        res_ += std::abs(l) + std::abs(r);
        return root->val + l + r - 1;
    }

    int res_ = 0;
};