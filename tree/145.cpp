/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * 后序遍历，先左节点，然后右节点，最后添加当前值
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, &res);
        return res;
    }

    void help(TreeNode* root, vector<int>* res) {
        if(!root) return;
        help(root->left, res);
        help(root->right, res);
        res->emplace_back(root->val);
    }
};