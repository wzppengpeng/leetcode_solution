/**
 * Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

 



 

Return its postorder traversal as: [5,6,3,2,4,1].
 */

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        for(auto child : root->children) {
            auto child_res = postorder(child);
            std::copy(std::begin(child_res), std::end(child_res), std::back_inserter(res));
        }
        res.push_back(root->val);
        return res;
    }
};