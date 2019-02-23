/**
 * Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its preorder traversal as: [1,3,5,6,2,4].
 */

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        res.emplace_back(root->val);
        for(auto child : root->children) {
            auto child_res = preorder(child);
            std::copy(std::begin(child_res), std::end(child_res), std::back_inserter(res));
        }
        return res;
    }
};