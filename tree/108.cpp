/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/**
 * 类似于二分查找的思路，始终在中间位置建树，然后递归
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int i = 0, j = nums.size();
        return helper(nums, i, j);
    }

    TreeNode* helper(const vector<int>& nums, int i, int j) {
        if(i >= j) return nullptr;
        int mid = (i + j) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, i, mid);
        node->right = helper(nums, mid + 1, j);
        return node;
    }
};