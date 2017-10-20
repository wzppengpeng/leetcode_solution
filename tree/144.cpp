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
 * 前向遍历，先当前节点，再左节点，最后右节点
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, &res);
        return res;
    }

    void help(TreeNode* root, vector<int>* res) {
        if(!root) return;
        res->emplace_back(root->val);
        help(root->left, res);
        help(root->right, res);
    }
};