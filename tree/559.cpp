/**
 * Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example, given a 3-ary tree:
 */

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int max_length = 0;
        for(auto child : root->children) {
            max_length = std::max(max_length, maxDepth(child));
        }
        return 1 + max_length;
    }
};
