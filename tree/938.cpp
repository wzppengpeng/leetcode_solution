/**
 * Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

 */


/**
 * 注意递归条件，即出现超出的情况时就不要往下递归
 */


class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        dfs(root, L, R, res);
        return res;
    }

    void dfs(TreeNode* work, int L, int R, int& res) {
        if(!work) return;
        if(work->val > L)
            dfs(work->left, L, R, res);
        if(work->val >= L && work->val <= R)
            res += work->val;
        if(work->val < R)
            dfs(work->right, L, R, res);
    }
};