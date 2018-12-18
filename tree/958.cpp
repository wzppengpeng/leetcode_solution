/**
 * Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


Example 1:



Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:



Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 */

/**
 * 使用bfs,首先按顺序把所有的节点都装进容器，如果是完全二叉树，末尾位置应该全部为空节点
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
    bool isCompleteTree(TreeNode* root) {
        std::vector<TreeNode*> bfs;
        bfs.emplace_back(root);
        size_t i = 0;
        while(i < bfs.size() && bfs[i]) {
            bfs.emplace_back(bfs[i]->left);
            bfs.emplace_back(bfs[i]->right);
            ++i;
        }
        while(i < bfs.size() && !bfs[i])
            ++i;
        return bfs.size() == i;
    }
};