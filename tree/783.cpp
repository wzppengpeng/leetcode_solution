/**
 * Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

 */

/**
 * 二叉排序树，中序遍历即为排序之后的顺序，与前一个数比较即为相邻距离
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
    int minDiffInBST(TreeNode* root) {
        int pre = INT_MAX, minest = INT_MAX;
        inorder_walk(root, pre, minest);
        return minest;
    }

    void inorder_walk(TreeNode* work, int& pre, int& minest) {
        if(!work) return;
        inorder_walk(work->left, pre, minest);
        if(pre < INT_MAX) {
            minest = std::min(minest, work->val - pre);
        }
        pre = work->val;
        inorder_walk(work->right, pre, minest);
    }
};