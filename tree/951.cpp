/**
 * 951. Flip Equivalent Binary Trees
Medium
41
1


For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.


Example 1:

Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
 */

/**
 * 名为翻转，其实就是交换左右，所以每到一处就判断左右节点能不能够交换即可
 */

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        else if((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val))
            return false;
        if(is_same(root1->left, root2->left) && is_same(root1->right, root2->right)) {
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        } else if(is_same(root1->left, root2->right) && is_same(root1->right, root2->left)) {
            return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        } else {
            return false;
        }
    }

    bool is_same(TreeNode* a, TreeNode* b) const {
        if(!a && !b) return true;
        else if(a && b && a->val == b->val) return true;
        else return false;
    }
};