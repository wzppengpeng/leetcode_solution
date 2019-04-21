class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int now, int& res) {
        if(!root) return;
        int tmp = now * 2 + root->val;
        if(root->left == nullptr && root->right == nullptr)
            res += tmp;
        dfs(root->left, tmp, res);
        dfs(root->right, tmp, res);
    }
};
