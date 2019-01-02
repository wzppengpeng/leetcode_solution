/**
 * A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.


 */


/**
 * 使用DFS，首先获取初始值，然后递归判断
 */

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return helper(root, root->val);
    }

    bool helper(TreeNode* root, int val) {
        if(root->val != val) return false;
        if(root->left && !helper(root->left, val)) return false;
        if(root->right && !helper(root->right, val)) return false;
        return true;
    }
};