/**
 * Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.
 */

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = nullptr) {
        if(!root) return tail;
        auto res = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};