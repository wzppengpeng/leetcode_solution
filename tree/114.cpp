/**
 * Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 */


/**
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        if(!root) return;
        std::vector<TreeNode*> container;
        pre_order(root, container);
        for(size_t i = 0; i < container.size() - 1; ++i) {
            container[i]->left = nullptr;
            container[i]->right = container[i + 1];
        }
        container.back()->left = nullptr;
        container.back()->right = nullptr;
    }

    void pre_order(TreeNode* work, std::vector<TreeNode*>& container) {
        if(!work) return;
        container.emplace_back(work);
        pre_order(work->left, container);
        pre_order(work->right, container);
    }
};