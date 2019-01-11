/**
 * Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.  Call such a sequence of N values the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].
 */


/**
 * 使用一个全局的index来保存现在遍历结束时的索引，索引是只递增的！
 */


class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        idx = 0;
        vector<int> res;
        return dfs(root, voyage, &res) ? res : vector<int> {-1};
    }

    bool dfs(TreeNode* root, const vector<int>& voyage, vector<int>* res) {
        if(!root) return true;
        if(idx >= voyage.size() || root->val != voyage[idx++])
            return false;
        if(root->left && root->left->val != voyage[idx]) {
            res->push_back(root->val);
            return dfs(root->right, voyage, res) && dfs(root->left, voyage, res);
        }
        return dfs(root->left, voyage, res) && dfs(root->right, voyage, res);
    }

    size_t idx = 0;
};