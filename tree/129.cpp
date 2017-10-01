/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
 */


/**
 * dfs递归的时候需要输入一个当前的求和值
 * 而结束条件为当前节点为叶子节点
 * 在向下递归的时候注意到下一层为10倍的当前值，相当于进位
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
    int sumNumbers(TreeNode* root) {
        return get_sum(root, 0);
    }

    int get_sum(TreeNode* work, int sum_tmp) {
        if(!work) return 0;
        if(work->left == nullptr && work->right == nullptr) return 10 * sum_tmp + work->val;
        return get_sum(work->left, work->val + 10 * sum_tmp)
            + get_sum(work->right, work->val + 10 * sum_tmp);
    }
};