/**
 * Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)
 */


/**
 *  这道题是从子节点往回回溯，所以先往下递归得到左右子字符串，然后再通过push_back的方式将当前节点加入到最终结果中
 *  使用string自带的compare功能就可以
 */


class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        string res;
        if(root->left) res = smallestFromLeaf(root->left);
        if(root->right) {
            auto right_s = smallestFromLeaf(root->right);
            if(res.empty() || right_s < res)
                res = std::move(right_s);
        }
        res.push_back('a' + root->val);
        return res;
    }
};